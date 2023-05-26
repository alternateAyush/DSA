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
    if (head == NULL)
    {
        return temp;
    }
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->pre = curr;
    return head;
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

Node *deleteHead(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node *newHead = head->next;
    newHead->pre = NULL;
    delete head;
    return newHead;
}

int main()
{
    Node *head = new Node(10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);
    head = insert(head, 50);
    print(head);
    head = deleteHead(head);
    print(head);
    return 0;
}