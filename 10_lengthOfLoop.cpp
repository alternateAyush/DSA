// From a given singly linked list detect loop i.e. lastNode->next != NULL
// Find length of the loop

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

Node *looper(Node *head, int i)
{
    Node *a = head;
    int k = 0;
    while (k < i - 1)
    {
        a = a->next;
        k++;
    }
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = a;
    return head;
}

// Using floyd cycle

int loopSize(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return 0;
    }
    if (head->next == head)
    {
        return 1;
    }
    Node *slow = head;
    Node *fast = head;
    int listLen = 0;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        listLen++;
        if (slow == fast)
        {
            break;
        }
    }
    if (slow != fast)
    {
        return 0;
    }
    int count = 1;
    slow = slow->next;
    while (slow != fast)
    {
        count++;
        slow = slow->next;
    }
    return count;
}

int main()
{
    Node *head = NULL;
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);
    head = insert(head, 50);
    head = looper(head, 3);
    cout << loopSize(head) << endl;
    return 0;
}