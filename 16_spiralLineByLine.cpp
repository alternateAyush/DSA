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
        left = NULL;
        right = NULL;
    }
};

void print(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    bool flag = true;
    while (q.empty() == false)
    {
        int n = q.size();
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            v.push_back(temp->data);
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
        for (int i = 0; i < n; i++)
        {
            if (flag == true)
            {
                cout << v[i] << " ";
            }
            else
            {
                cout << v[n - 1 - i] << " ";
            }
        }
        flag = (!flag);
        cout << endl;
        v.clear();
    }
    return;
}

// a better solution using two stacks
void printpro(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(root);
    while (s1.empty() == false || s2.empty() == false)
    {
        if (s1.empty() == false)
        {
            int n = s1.size();
            for (int i = 0; i < n; i++)
            {
                Node *temp = s1.top();
                s1.pop();
                cout << temp->data << " ";
                if (temp->left != NULL)
                {
                    s2.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    s2.push(temp->right);
                }
            }
            cout << endl;
        }
        else
        {
            int n = s2.size();
            for (int i = 0; i < n; i++)
            {
                Node *temp = s2.top();
                s2.pop();
                cout << temp->data << " ";
                if (temp->right != NULL)
                {
                    s1.push(temp->right);
                }
                if (temp->left != NULL)
                {
                    s1.push(temp->left);
                }
            }
            cout << endl;
        }
    }
    return;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->right->left->left = new Node(10);
    print(root);
    cout << "----------" << endl;
    printpro(root);
    return 0;
}