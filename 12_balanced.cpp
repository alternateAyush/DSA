// For each node the 0<=|height of left subtree - height of right subtree|<=1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *right, *left;
    int key;
    Node(int x)
    {
        key = x;
        right = NULL;
        left = NULL;
    }
};

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

// bool isBalanced(Node *root)
// {
//     if (root == NULL)
//     {
//         return true;
//     }
//     if (root->left == NULL && root->right == NULL)
//     {
//         return true;
//     }
//     bool ans = false;
//     if (height(root->left) == height(root->right))
//     {
//         ans = true;
//     }
//     else if (height(root->left) - height(root->right) == 1 || height(root->left) - height(root->right) == -1)
//     {
//         ans = true;
//     }
//     return (ans && isBalanced(root->left) && isBalanced(root->right));
// }

int isBalanced(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = isBalanced(root->left);
    if (l == -1)
    {
        return -1;
    }
    int r = isBalanced(root->right);
    if (r == -1)
    {
        return -1;
    }
    if (abs(l - r) > 1)
    {
        return -1;
    }
    return (1 + max(l, r));
}

int main()
{
    cout << boolalpha;
    // Node *root = new Node(10);
    // root->left = new Node(20);
    // root->right = new Node(30);
    // root->right->left = new Node(40);
    // root->right->right = new Node(50);

    ///////////////////////////////////
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(60);
    root->right->right->right = new Node(70);
    cout << height(root) << endl;
    // cout << isBalanced(root) << endl;
    if (isBalanced(root) > 0)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}