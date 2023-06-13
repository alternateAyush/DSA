#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *pre = NULL;

Node *toLinkedList(Node *root)
{
    if (root == NULL)
    {
        return root;
    }
    Node *head = toLinkedList(root->left);
    if (pre == NULL)
    {
        head = root;
    }
    else
    {
        root->left = pre;
        pre->right = root;
    }
    pre = root;
    toLinkedList(root->right);
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    Node *tail = NULL;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        if (temp->right == NULL)
        {
            tail = temp;
        }
        temp = temp->right;
    }
    cout << endl;
    while (tail != NULL)
    {
        cout << tail->data << " ";
        tail = tail->left;
    }
    cout << endl;
    return;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(35);
    Node *head = toLinkedList(root);
    print(head);

    return 0;
}