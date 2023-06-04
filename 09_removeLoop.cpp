// From a given singly linked list detect loop i.e. lastNode->next != NULL
// Remove the loop.

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

bool detectAndRemove(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }
    if (head->next == head)
    {
        head->next = NULL;
        return true;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    if (fast == NULL || fast->next == NULL)
    {
        return false;
    }
    if (fast == head)
    {
        Node *curr = fast;
        curr = curr->next;
        while (curr->next != head)
        {
            curr = curr->next;
        }
        curr->next = NULL;
        return true;
    }
    slow = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    cout << slow->next->data << endl;
    cout << fast->data << endl;
    fast->next = NULL;
    return true;
}

int main()
{
    cout << boolalpha;
    Node *head = NULL;
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);
    head = insert(head, 50);
    head = looper(head, 2);
    cout << detectAndRemove(head) << endl;
    print(head);
    return 0;
}