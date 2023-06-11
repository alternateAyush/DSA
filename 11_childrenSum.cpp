#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left, *right;
    int key;
    Node(int x)
    {
        key = x;
        right = NULL;
        left = NULL;
    }
};

// time = O(n)
// space = O(height)
bool childSum(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root != NULL && root->left == NULL && root->right == NULL)
    {
        return true;
    }
    int rut = root->key;
    int l = 0;
    int r = 0;
    if (root->left != NULL)
    {
        l = root->left->key;
    }
    if (root->right != NULL)
    {
        r = root->right->key;
    }
    l += r;
    return (rut == l && childSum(root->left) && childSum(root->right));
}

int main()
{
    cout << boolalpha;
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(12);
    cout << childSum(root) << endl;
    return 0;
}