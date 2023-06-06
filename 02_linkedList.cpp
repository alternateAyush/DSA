#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *next;
    int data;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Queue
{
    Node *front;
    Node *rear;
    int size;

    Queue()
    {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    void push(int x)
    {
        Node *temp = new Node(x);
        if (front == NULL)
        {
            front = temp;
            rear = temp;
            size++;
            return;
        }
        rear->next = temp;
        rear = rear->next;
        size++;
        return;
    }

    int pop()
    {
        if (front == NULL)
        {
            return INT32_MIN;
        }
        int temp = front->data;
        Node *t = front;
        front = front->next;
        delete t;
        size--;
        return temp;
    }
};

int main()
{
    int n;
    Queue myQueue;
    cout << myQueue.pop() << endl;
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    myQueue.push(40);
    myQueue.push(50);
    cout << myQueue.pop() << " " << myQueue.front->data << " " << myQueue.rear->data << endl;
    return 0;
}