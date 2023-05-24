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

int search(Node *head, int key)
{
    int index = 0;
    while (head != NULL)
    {
        if (head->data == key)
        {
            return index;
        }
        head = head->next;
        index++;
    }
    return -1;
}

int main()
{
    Node *head = new Node(10);
    head = insertAtI(head, 20, 1);
    head = insertAtI(head, 30, 2);
    head = insertAtI(head, 40, 3);
    head = insertAtI(head, 50, 4);
    head = insertAtI(head, 60, 5);
    print(head);
    cout << search(head, 10) << endl;
    return 0;
}