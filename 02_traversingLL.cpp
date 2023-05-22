#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int a)
    {
        data = a;
        next = NULL;
    }
};

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
    head->next = new Node(20);
    head->next->next = new Node(30);
    print(head);
    cout << head->data << endl;
    return 0;
}