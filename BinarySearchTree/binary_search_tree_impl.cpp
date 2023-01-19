#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insert(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        root->left = insert(root->left, data);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        insert(root, data);
        cin >> data;
    }
}

// Level Order Traversal
void print(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int search(Node *root, int x)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == x)
    {
        return x;
    }

    if (x > root->data)
    {
        return search(root->right, x);
    }
    else
    {
        return search(root->left, x);
    }
}

// Find Min
Node *findMin(Node *root)
{
    if (root->left == NULL)
    {
        return root;
    }
    return findMin(root->left);
}

// Find Max
int findMax(Node *root)
{
    if (root->right == NULL)
    {
        return root->data;
    }
    return findMax(root->right);
}

Node *deleteNode(Node *root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == x)
    {
        // 0 Child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 Child
        // Left
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // Right
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 Child
        if (root->left != NULL && root->right != NULL)
        {
            int min = findMin(root->left)->data;
            root->data = min;
            delete deleteNode(root->left, min);
            return root;
        }
    }
    else if (x > root->data)
    {
        return deleteNode(root->right, x);
    }
    else
    {
        return deleteNode(root->left, x);
    }
}

void levelOrderTraversal(Node *root)
{
    cout << endl
         << "levelOrderTraversal" << endl;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    Node *temp;
    while (q.size() > 1)
    {
        temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            q.push(NULL);
            cout << "\n";
        }
        else
        {
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
            cout << temp->data << "   ";
        }
    }
}

int main()
{
    Node *root = NULL;
    cout << "Enter data for BST" << endl;
    // 10 8 21 7 27 5 4 3 -1
    takeInput(root);

    cout << "In Order Traversal" << endl;
    inOrder(root);
    // cout << "\nPre Order Traversal" << endl;
    // preOrder(root);
    // cout << "\nPost Order Traversal" << endl;
    // postOrder(root);
    // cout << "\nSearch Result for 3 : " << search(root, 3) << endl;
    // cout << "Min : " << findMin(root) << endl;
    // cout << "Max : " << findMax(root) << endl;
    levelOrderTraversal(root);
    root = deleteNode(root, 4);
    // cout << "\nAfter Deletion : " << endl;
    levelOrderTraversal(root);

    return 0;
}