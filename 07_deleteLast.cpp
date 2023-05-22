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

Node *insert(Node *head, int a)
{
    Node *temp = new Node(a);
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

Node *deleteLast(Node *head)
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

    Node *curr = head;
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }
    Node *temp = curr->next;
    curr->next = NULL;
    delete temp;
    return head;
}

int main()
{
    Node *head = new Node(10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);
    head = deleteLast(head);
    print(head);
    return 0;
}