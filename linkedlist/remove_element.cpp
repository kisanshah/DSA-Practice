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
        //Memory Free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Delete " << value << endl;
    }
};

//Insert Node at Head/Start
void insertNodeAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

Node* removeElements(Node *head, int data)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
              Node *prev = temp;
            Node *curr = temp;
            temp = temp->next;
            prev->next = temp->next;
            delete curr;

        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

//Iterating Linked List
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

int main()
{
    Node *node = new Node(6);

    Node *head = node;
    Node *tail = node;
    insertNodeAtHead(head, 5);
    insertNodeAtHead(head, 4);
    insertNodeAtHead(head, 3);
    insertNodeAtHead(head, 6);
    insertNodeAtHead(head, 2);
    insertNodeAtHead(head, 1);
    cout << "Head " << head->data << endl;
    cout << "Tail " << tail->data << endl;
    print(head);
    removeElements(head, 6);
    print(head);
    return 0;
}
