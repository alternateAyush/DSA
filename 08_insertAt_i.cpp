#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int a)
    {
        data = a;
        next = NULL;
    }
};

Node *insert(Node *head, int a)
{
    Node *temp = new Node(a);
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

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    return;
}

Node *insertAtI(Node *head, int x, int i)
{
    Node *temp = new Node(x);
    if (i == 0)
    {
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    for (int j = 0; j < i && curr != NULL; j++)
    {
        if (j == i - 1)
        {
            temp->next = curr->next;
            curr->next = temp;
            return head;
        }
        curr = curr->next;
    }
    return head;
}

int main()
{
    Node *head = new Node(10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);
    head = insert(head, 50);
    head = insertAtI(head, 60, 5);
    print(head);
    return 0;
}