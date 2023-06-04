// In a sorted single linked list insert item such that the list remains sorted

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
    if (x < head->data)
    {
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    while (curr->next != NULL && curr->next->data < x)
    {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

int main()
{
    Node *head = NULL;
    head = insert(head, 10);
    print(head);
    head = insert(head, 50);
    print(head);
    head = insert(head, 20);
    print(head);
    head = insert(head, 40);
    print(head);
    head = insert(head, 30);
    print(head);
    head = insert(head, 60);
    print(head);
    return 0;
}