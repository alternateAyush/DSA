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

bool search(Node *root, int key)
{
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->data == key)
        {
            return true;
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
    return false;
}

bool rsearch(Node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    if (key > root->data)
    {
        return rsearch(root->right, key);
    }
    else
    {
        return rsearch(root->left, key);
    }
}

int main()
{
    cout << boolalpha;
    int key;
    cin >> key;
    Node *root = new Node(15);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(18);
    root->right->right = new Node(80);
    root->right->left->left = new Node(16);
    root->left->left = new Node(3);
    cout << search(root, key) << endl;
    cout << rsearch(root, key) << endl;
    return 0;
}