// Find the middle of linked list.

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

// noob
// void middle(Node *head)
// {
//     if (head == NULL)
//     {
//         return;
//     }
//     int count = 0;
//     Node *curr = head;
//     while (curr != NULL)
//     {
//         count++;
//         curr = curr->next;
//     }
//     count = (count / 2);
//     curr = head;
//     while (count > 0)
//     {
//         curr = curr->next;
//         count--;
//     }
//     cout << curr->data << endl;
//     return;
// }

// pro //slow and fast

void middle(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data << endl;
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
    middle(head);
    head = insert(head, 60);
    print(head);
    middle(head);
    return 0;
}