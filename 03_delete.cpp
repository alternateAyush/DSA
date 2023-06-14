#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;
    Node(int x)
    {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        return new Node(key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    else if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    return root;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

Node *insuccesor(Node *root)
{
    Node *curr = root->right;
    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            Node *temp = insuccesor(root);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main()
{
    Node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 18);
    root = insert(root, 80);
    root = insert(root, 16);
    root = insert(root, 3);
    root = insert(root, 90);
    inorder(root);
    cout << endl;
    root = deleteNode(root, 15);
    inorder(root);
    return 0;
}