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

Node *ceil(Node *root, int key)
{
    Node *pre = NULL;
    while (root != NULL)
    {
        if (root->data == key)
        {
            return root;
        }
        else if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            pre = root;
            root = root->left;
        }
    }
    return pre;
}

int main()
{
    Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 55);
    root = insert(root, 65);
    inorder(root);
    cout << endl;
    cout << ceil(root, 58)->data << endl;
    cout << ceil(root, 25)->data << endl;
    // cout << floor(root, 30)->data << endl;
    // cout << floor(root, 30)->data << endl;

    return 0;
}