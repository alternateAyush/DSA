// Output the nth element from back of linked list.

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
// void nFromEnd(Node *head, int n)
// {
//     Node *curr = head;
//     int count = 0;
//     while (curr != NULL)
//     {
//         curr = curr->next;
//         count++;
//     }
//     if (n > count)
//     {
//         return;
//     }
//     count = count - n;
//     curr = head;
//     while (count > 0)
//     {
//         curr = curr->next;
//         count--;
//     }
//     cout << curr->data << endl;
//     return;
// }

// pro
void nFromEnd(Node *head, int n)
{
    if (head == NULL)
    {
        return;
    }
    Node *curr = head;
    Node *ahead = head;
    for (int i = 0; i < n - 1; i++)
    {
        ahead = ahead->next;
        if (ahead == NULL)
        {
            return;
        }
    }
    while (ahead->next != NULL)
    {
        ahead = ahead->next;
        curr = curr->next;
    }
    cout << curr->data << endl;
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
    nFromEnd(head, 3);
    head = insert(head, 60);
    int n;
    cin >> n;
    print(head);
    nFromEnd(head, n);
    return 0;
}