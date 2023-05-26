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

// Noob
// Node *deleteHead(Node *head)
// {
//     if (head == NULL)
//     {
//         return head;
//     }
//     if (head->next == head)
//     {
//         delete head;
//         return NULL;
//     }
//     Node *curr = head;
//     while (curr->next != head)
//     {
//         curr = curr->next;
//     }
//     Node *newHead = head->next;
//     curr->next = head->next;
//     delete head;
//     return newHead;
// }

// pro
Node *deleteHead(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->next == head)
    {
        delete head;
        return NULL;
    }
    Node *toDelete = head->next;
    head->data = toDelete->data;
    head->next = toDelete->next;
    delete toDelete;
    return head;
}

int main()
{
    Node *head = NULL;
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);
    head = insert(head, 50);
    head = insert(head, 60);
    print(head);
    head = deleteHead(head);
    print(head);
    return 0;
}