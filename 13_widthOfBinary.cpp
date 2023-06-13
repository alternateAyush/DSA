#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *right, *left;
    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};

int maxWidth(Node *root)
{
    queue<Node *> q;
    q.push(root);
    int width = INT32_MIN;
    while (q.empty() == false)
    {
        int n = q.size();
        width = max(n, width);
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
    return width;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
    cout << maxWidth(root) << endl;
    char a = 'a';
    int x = a;
    cout << x << endl;
    return 0;
}