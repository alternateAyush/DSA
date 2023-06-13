#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int data;
    Node(int x)
    {
        data = x;
        right = NULL;
        left = NULL;
    }
};

// inorder traversal using loop
void print(Node *root)
{
    stack<Node *> s;
    Node *curr = root;
    while (s.empty() == false || curr != NULL)
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
    return;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    print(root);
    return 0;
}