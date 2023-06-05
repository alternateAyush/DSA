// Clone a linked list that also has a random pointer.

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *ran;
    Node(int a)
    {
        data = a;
        next = NULL;
        ran = NULL;
    }
};

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

void setRan(Node *head, int x, int y)
{
    Node *curr = head;
    for (int i = 0; i < x - 1 && curr != NULL; i++)
    {
        curr = curr->next;
    }
    Node *node1 = curr;
    curr = head;
    for (int i = 0; i < y - 1 && curr != NULL; i++)
    {
        curr = curr->next;
    }
    node1->ran = curr;
    return;
}

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

void printRan(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " -> ";
        if (curr->ran != NULL)
        {
            cout << curr->ran->data << endl;
        }
        else
        {
            cout << "NULL" << endl;
        }
        curr = curr->next;
    }
    cout << endl;
    return;
}

// GFG optimum solution
Node *cloning(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        Node *temp = new Node(head->data);
        if (head->ran == head)
        {
            temp->ran = temp;
        }
        return temp;
    }
    Node *curr = head;
    while (curr != NULL)
    {
        Node *temp = new Node(curr->data);
        temp->next = curr->next;
        curr->next = temp;
        curr = curr->next->next;
    }
    bool flag = true;
    curr = head;
    while (curr != NULL)
    {
        if (curr->ran != NULL)
        {
            curr->next->ran = curr->ran->next;
        }
        curr = curr->next->next;
    }
    Node *newHead = head->next;
    curr = head->next->next;
    head->next = head->next->next;
    Node *curr2 = newHead;
    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr2->next = temp;
        curr->next = curr->next->next;
        curr = curr->next;
        curr2 = curr2->next;
    }

    return newHead;
}

int main()
{
    Node *head = NULL;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    //  head = insert(head, 30);
    setRan(head, 1, 2);
    setRan(head, 2, 4);
    // setRan(head, 3, 1);
    //  setRan(head, 4, 3);
    //  setRan(head, 5, 4);
    Node *clone = NULL;
    clone = cloning(head);
    print(head);
    printRan(head);
    print(clone);
    printRan(clone);
    print(head);
    printRan(head);
    return 0;
}