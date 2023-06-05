// A singly linked list is given
// partition between odd and even data even first.

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
void intersect(Node *head1, Node *head2)
{
    Node *curr = head1;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    Node *end1 = curr;
    curr->next = head2;
    curr = head1;
    Node *slow = head1;
    Node *fast = head1;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    if (slow != fast)
    {
        cout << "Not intersect" << endl;
        return;
    }
    slow = head1;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    cout << fast->data << endl;
    end1->next = NULL;
    return;
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
    head = insert(head, 7);
    head = insert(head, 8);
    Node *head2 = new Node(11);
    head2->next = head->next->next->next;
    print(head);
    print(head2);
    Node *head3 = NULL;
    head3 = insert(head3, 10);
    head3 = insert(head3, 20);
    head3 = insert(head3, 30);
    head3->next->next->next = head;
    print(head3);
    intersect(head, head2);
    intersect(head, head3);

    return 0;
}