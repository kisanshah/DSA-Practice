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
};

//Insert Node at Head/Start
void insertNodeAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

//Insert Node at Head/Start
void insertNodeAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
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
    Node *node = new Node(10);

    Node *head = node;
    Node *tail = node;
    print(head);
    insertNodeAtTail(tail, 20);
    print(head);
    insertNodeAtTail(tail, 30);
    print(head);
    return 0;
}
