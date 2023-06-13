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

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

// time = O(n^2)
int diameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    int dia = 1 + lh + rh;
    int maxDia = max(diameter(root->left), diameter(root->right));
    return max(dia, maxDia);
}

//////////////////////////////////////////////////////
unordered_map<Node *, int> myMap;
void heights(Node *root)
{
    if (root != NULL)
    {
        myMap.insert({root, height(root)});
        heights(root->left);
        heights(root->right);
    }
}

// after pre-computations time = O(n)
int diameterpro(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    int lh = myMap.find(root->left)->second;
    int rh = myMap.find(root->right)->second;
    int dia = 1 + lh + rh;
    int maxi = max(diameter(root->left), diameter(root->right));
    return max(dia, maxi);
}
///////////////////////////////////////////////////////////////////

// ultra pro maxx solution
// time = O(n) with no overhead
int res = 0;
int diameterpromax(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = diameterpromax(root->left);
    int rh = diameterpromax(root->right);
    res = max(res, 1 + rh + lh);
    return 1 + max(lh, rh);
}
int func(Node *root)
{
    res = 0;
    diameterpromax(root);
    return res;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(60);
    root->left->left = new Node(30);
    root->left->right = new Node(80);
    root->left->left->left = new Node(40);
    root->left->left->right = new Node(50);
    root->left->left->left->left = new Node(60);
    root->left->right->right = new Node(90);
    root->left->right->right->right = new Node(18);
    cout << diameter(root) << endl;
    // solution 2
    heights(root);
    cout << diameterpro(root) << endl;
    cout << func(root) << endl;

    return 0;
}