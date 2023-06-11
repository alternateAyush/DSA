#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left, *right;
    int key;
    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};

int maxValue(Node *root)
{
    if (root == NULL)
    {
        return INT32_MIN;
    }
    int rut = root->key;
    int l = maxValue(root->left);
    int r = maxValue(root->right);
    l = max(l, r);
    return max(rut, l);
}

int main()
{
    // Node *root = new Node(10);
    // root->left = new Node(20);
    // root->right = new Node(30);
    // root->left->left = new Node(8);
    // root->left->right = new Node(7);
    // root->right->right = new Node(6);
    // root->left->right->left = new Node(9);
    // root->left->right->right = new Node(15);
    Node *root = new Node(10);
    root->left = new Node(30);
    root->right = new Node(40);
    root->left->left = new Node(80);
    root->left->left->right = new Node(70);
    root->right->left = new Node(60);
    root->right->right = new Node(20);

    cout << maxValue(root) << endl;
    return 0;
}