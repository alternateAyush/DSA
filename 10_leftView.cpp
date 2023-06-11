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

void leftView(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (i == 0)
            {
                cout << temp->key << " ";
            }
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
        cout << endl;
    }
}

void rightView(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (i == n - 1)
            {
                cout << temp->key << " ";
            }
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
        cout << endl;
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(8);
    root->left->right = new Node(7);
    root->right->right = new Node(6);
    root->left->right->left = new Node(9);
    root->left->right->right = new Node(15);
    leftView(root);
    cout << endl;
    rightView(root);
    return 0;
}