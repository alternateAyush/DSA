// Construct a binary tree
// given : inorder and preorder traversal

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int pre = 0;
// time = O(n^2);
Node *cTree(int inorder[], int preorder[], int instart, int inend)
{
    if (instart > inend)
    {
        return NULL;
    }
    Node *root = new Node(preorder[pre++]);
    int in;
    for (int i = instart; i <= inend; i++)
    {
        if (inorder[i] == root->data)
        {
            in = i;
            break;
        }
    }
    root->left = cTree(inorder, preorder, instart, in - 1);
    root->right = cTree(inorder, preorder, in + 1, inend);
    return root;
}

int main()
{
    int n = 5;
    int inorder[] = {20, 10, 40, 30, 50};
    int preorder[] = {10, 20, 30, 40, 50};
    Node *root = cTree(inorder, preorder, 0, n - 1);
    // pre computation for O(n) solution;
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map.insert({inorder[i], i});
    }

    return 0;
}