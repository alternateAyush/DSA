#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *right;
    Node *left;
    int data;
    Node(int x)
    {
        data = x;
        right = NULL;
        left = NULL;
    }
};

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

Node *insert(Node *root, int key)
{
    Node *temp = new Node(key);
    if (root == NULL)
    {
        return temp;
    }
    Node *curr = root;
    Node *pre = NULL;
    while (curr != NULL)
    {
        pre = curr;
        if (curr->data == key)
        {
            return root;
        }
        if (key > curr->data)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
    if (key > pre->data)
    {
        pre->right = temp;
    }
    else
    {
        pre->left = temp;
    }
    return root;
}

Node *rinsert(Node *root, int x)
{
    if (root == NULL)
    {
        return new Node(x);
    }
    else if (x > root->data)
    {
        root->right = rinsert(root->right, x);
    }
    else if (x < root->data)
    {
        root->left = rinsert(root->left, x);
    }
    return root;
}

int main()
{
    Node *root = new Node(15);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(18);
    root->right->right = new Node(80);
    root->right->left->left = new Node(16);
    root->left->left = new Node(3);
    inorder(root);
    cout << endl;
    Node *root2 = NULL;
    root2 = insert(root2, 15);
    root2 = insert(root2, 5);
    root2 = insert(root2, 20);
    root2 = insert(root2, 18);
    root2 = insert(root2, 80);
    root2 = insert(root2, 16);
    root2 = insert(root2, 3);
    root2 = insert(root2, 90);
    inorder(root2);
    cout << endl;
    Node *root3 = NULL;
    root3 = rinsert(root3, 15);
    root3 = rinsert(root3, 5);
    root3 = rinsert(root3, 20);
    root3 = rinsert(root3, 18);
    root3 = rinsert(root3, 90);
    root3 = rinsert(root3, 16);
    root3 = rinsert(root3, 3);
    root3 = rinsert(root3, 90);
    inorder(root3);
    return 0;
}