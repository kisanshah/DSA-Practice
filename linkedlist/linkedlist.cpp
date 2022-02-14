#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        // Memory Free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Delete " << value << endl;
    }
};

// Insert Node at Head/Start
void insertNodeAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

// Delete Node
void deleteNodeAtPosition(Node *head, int pos)
{
    // Handle first node deletion
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        // Destuct/Destroy object
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // Handle middle/last node deletion
        Node *curr = head;
        Node *prev = NULL;
        int count = 1;
        while (count < pos)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

// Insert Node at Tail/End
void insertNodeAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

// Insert node at Index/Position
void insertAtPosition(Node *&head, Node *&tail, int pos, int data)
{
    if (pos == 1)
    {
        insertNodeAtHead(head, data);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        insertNodeAtTail(tail, data);
        return;
    }
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Iterating Linked List
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseList(Node *&head)
{
    //    NULL // 40 10 20 30
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

// Find middle of LinkedList
Node *getMiddleNode(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// Remove duplicate from sorted list
Node *removeDuplicateFromSortedList(Node *&head)
{
    Node *temp = head;
    Node *next = NULL;
    while (temp != NULL)
    {
        next = temp->next;
        if (temp->data == next->data )
        {
            // Delete if next node is same as current
            temp->next = next->next;
            next->next = NULL;
            delete next;
        }else{

        temp = temp->next;
        }
    }
}

int main()
{
    Node *node = new Node(10);

    Node *head = node;
    Node *tail = node;
    print(head);
    insertNodeAtTail(tail, 20);
    insertNodeAtTail(tail, 20);
    insertNodeAtTail(tail, 20);
    print(head);
    insertNodeAtTail(tail, 30);
    print(head);
    removeDuplicateFromSortedList(head);
    print(head);
    insertAtPosition(head, tail, 6, 40);
    print(head);
    cout << "Head " << head->data << endl;
    cout << "Tail " << tail->data << endl;
    print(head);
    reverseList(head);
    print(head);
    Node *n = getMiddleNode(head);
    print(n);

    return 0;
}
