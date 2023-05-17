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

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
}