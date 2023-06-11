#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int key;
    Node(int k)
    {
        key = k;
        left = NULL;
        right = NULL;
    }
};

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    //          10
    //    20         30
    // 40  NULL  NULL  NULL
    return 0;
}