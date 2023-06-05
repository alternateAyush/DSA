// A singly linked list is given
// partition between odd and even data even first.

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

Node *part(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *curr = head;
    Node *odd = new Node(-1);
    Node *even = new Node(-1);
    Node *oddc = odd;
    Node *evenc = even;
    while (curr != NULL)
    {
        if ((curr->data) % 2 == 0)
        {
            evenc->next = new Node(curr->data);
            evenc = evenc->next;
        }
        else
        {
            oddc->next = new Node(curr->data);
            oddc = oddc->next;
        }
        curr = curr->next;
    }
    if (even->next == NULL || odd->next == NULL)
    {
        return head;
    }
    Node *toDelete = even;
    Node *toDelete2 = odd;
    even = even->next;
    odd = odd->next;
    delete toDelete;
    delete toDelete2;
    evenc->next = odd;
    oddc->next = NULL;
    return even;
}

int main()
{
    Node *head = NULL;
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 7);
    head = insert(head, 9);
    head = insert(head, 4);
    head = insert(head, 8);
    head = insert(head, 11);
    head = insert(head, 10);
    print(head);
    head = part(head);
    print(head);
    return 0;
}