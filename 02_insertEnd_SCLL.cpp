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

// Noob approach
// Node *insert(Node *head, int x)
// {
//     Node *temp = new Node(x);
//     if (head == NULL)
//     {
//         temp->next = temp;
//         return temp;
//     }
//     Node *curr = head;
//     while (curr->next != head)
//     {
//         curr = curr->next;
//     }
//     curr->next = temp;
//     temp->next = head;
//     return head;
// }

// pro
Node *insert(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    temp->next = head->next;
    head->next = temp;
    temp->data = head->data;
    head->data = x;
    return temp;
}

void print(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *curr = head;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;

    } while (curr != head);
    cout << endl;
    return;
}

int main()
{
    Node *head = NULL;
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    print(head);
    head = insert(head, 40);
    head = insert(head, 50);
    head = insert(head, 60);
    print(head);
    return 0;
}