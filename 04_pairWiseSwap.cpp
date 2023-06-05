// A singly linked list is given
// Pairwise swap

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

// my solution optimum solution
// but data is being swapped not the node
// void swap(Node *head)
// {
//     if (head == NULL || head->next == NULL)
//     {
//         return;
//     }
//     Node *curr = head;
//     bool flag = true;
//     while (curr->next != NULL)
//     {
//         if (flag)
//         {
//             int n = curr->data;
//             curr->data = curr->next->data;
//             curr->next->data = n;
//         }
//         curr = curr->next;
//         flag = (!flag);
//     }
// }

// better : nodes are swapped
Node *swap(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *curr = head->next->next;
    Node *pre = head;
    Node *newHead = head->next;
    newHead->next = head;
    Node *next = NULL;
    while (curr != NULL && curr->next != NULL)
    {
        next = curr->next->next;
        pre->next = curr->next;
        curr->next->next = curr;
        pre = curr;
        curr = next;
    }
    pre->next = curr;
    return newHead;
}

int main()
{
    Node *head = NULL;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);
    head = insert(head, 6);
    // head = insert(head, 7);
    head = insert(head, 8);
    //  head = insert(head, 9);
    print(head);
    head = swap(head);
    print(head);

    return 0;
}