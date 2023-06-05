#include <bits/stdc++.h>
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

struct Stack
{
    int size;
    Node *head;
    bool empty;
    Stack()
    {
        head = NULL;
        empty = true;
        size = 0;
    }
    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
        empty = false;
        size++;
    }
    int pop()
    {
        if (empty == false)
        {
            Node *temp = head;
            head = head->next;
            size--;
            if (size == 0)
            {
                empty = true;
            }
            int res = temp->data;
            delete temp;
            return res;
        }
        return INT32_MIN;
    }
    int peek()
    {
        if (empty == false)
        {
            return head->data;
        }
        return INT32_MIN;
    }
    void print()
    {
        if (empty == false)
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << "| " << temp->data << " |" << endl;
                temp = temp->next;
            }
            cout << "|"
                 << "___"
                 << "|\n"
                 << endl;
        }
        else
        {
            cout << "|"
                 << "___"
                 << "|\n"
                 << endl;
        }
    }
    bool isEmpty()
    {
        return empty;
    }
    int currSize()
    {
        return size;
    }
};

int main()
{
    cout << boolalpha;
    int n;
    cin >> n;
    Stack MyStack;
    MyStack.print();
    cout << MyStack.currSize() << endl;
    cout << MyStack.isEmpty() << endl;
    cout << MyStack.peek() << " " << MyStack.pop() << endl;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        MyStack.push(temp);
    }
    MyStack.print();

    MyStack.pop();
    MyStack.print();
    cout << MyStack.currSize() << endl;
    cout << MyStack.isEmpty() << endl;
    cout << MyStack.peek() << " " << MyStack.pop() << endl;
    MyStack.print();
    return 0;
}