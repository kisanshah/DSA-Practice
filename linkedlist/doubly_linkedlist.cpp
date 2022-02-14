#include <iostream>

using namespace std;

class Node
{
public:
    Node *prev;
    int value;
    Node *next;

    Node(int data)
    {
        this->prev = NULL;
        this->value = data;
        this->next = NULL;
    }
};

void print(Node *&head)
{
    cout << "NODE" << endl;
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node *head)
{
    cout << "NODE LENGTH" << endl;
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    cout << count << endl;
    return count;
}

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}
void insertAtPositon(Node *&head, Node *&tail, int pos, int data)
{
    if (pos == 1)
    {
        insertAtHead(head, data);
        return;
    }
    int count = 1;
    Node *temp = head;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }

    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;  
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertAtHead(head, 1);
    insertAtTail(tail, 20);
    insertAtPositon(head, tail, 2, 30);
    print(head);
    getLength(head);
}
