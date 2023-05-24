#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *pre;
    Node(int x)
    {
        data = x;
        next = NULL;
        pre = NULL;
    }
};

Node *insert(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head != NULL)
    {
        head->pre = temp;
    }
    temp->next = head;
    return temp;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    return;
}

int main()
{
    Node *head = new Node(10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);
    head = insert(head, 50);
    print(head);
    return 0;
}