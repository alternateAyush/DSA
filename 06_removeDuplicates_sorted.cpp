// From a given sorted linked list remove duplicate nodes.

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
    return;
}

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
    return head;
}

void removeDupli(Node *head)
{
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        Node *temp = curr->next;
        if (temp->data == curr->data)
        {
            curr->next = temp->next;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
    return;
}

int main()
{
    Node *head = NULL;
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 30);
    head = insert(head, 30);
    head = insert(head, 40);
    print(head);
    removeDupli(head);
    print(head);
    return 0;
}