#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *right, *left;
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
    return max(height(root->left), height(root->right)) + 1;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->left->right->left = new Node(70);
    root->left->right->right = new Node(80);
    root->right->right = new Node(60);
    //        10
    //   20         30
    // 40    50  NULL    60
    //    70  80
    cout << height(root) << endl;
    return 0;
}