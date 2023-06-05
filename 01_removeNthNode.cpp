// A singly linked list is given
// Input: pointer to a node
// delete that node.

#include <iostream>
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

void remove(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    if (node->next == NULL)
    {
        delete node;
        return;
    }
    Node *toDelete = node->next;
    node->data = toDelete->data;
    node->next = toDelete->next;
    delete toDelete;
    return;
}

int main()
{
    Node *head = NULL;
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);
    head = insert(head, 50);
    print(head);
    remove(head->next->next);
    print(head);
    return 0;
}