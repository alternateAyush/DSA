// A singly linked list is given
// Check if a linked list is pallindrome or not.

#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node *next;
    Node(string x)
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

Node *insert(Node *head, string x)
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

bool pallindrome(Node *head)
{
    if (head == NULL)
    {
        return false;
    }
    if (head->next == NULL)
    {
        return true;
    }
    int count = 0;
    Node *curr = head;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    if (count % 2 == 0)
    {
        count = count / 2;
    }
    else
    {
        count = (count / 2) + 1;
    }
    curr = head;
    for (int i = 0; i < count; i++)
    {
        curr = curr->next;
    }
    Node *curr2 = head;
    while (curr != NULL)
    {
        if (curr->data != curr2->data)
        {
            return false;
        }
        curr = curr->next;
        curr2 = curr2->next;
    }
    return true;
}

int main()
{
    Node *head = NULL;
    head = insert(head, "a");
    head = insert(head, "b");
    head = insert(head, "c");
    head = insert(head, "b");
    head = insert(head, "a");
    print(head);
    cout << pallindrome(head) << endl;
    return 0;
}