#include <bits/stdc++.h>
using namespace std;

struct Stack
{
    queue<int> q;

    Stack(int x)
    {
        q.push(x);
    }
    void push(int x)
    {
        q.push(x);
    }
    int top()
    {
        if (q.empty() == true)
        {
            return INT32_MIN;
        }
        return q.back();
    }
    int pop()
    {
        if (q.empty() == true)
        {
            return INT32_MIN;
        }
        queue<int> q1;
        int size = q.size();
        int i = 0;
        int temp = q.back();
        while (i < size - 1)
        {
            q1.push(q.front());
            q.pop();
            i++;
        }
        if (q1.empty() == true)
        {
            q.pop();
            return temp;
        }
        i = 0;
        while (i < size - 1)
        {
            q.push(q1.front());
            q1.pop();
            i++;
        }
        return temp;
    }
    int getSize()
    {
        return q.size();
    }
};

int main()
{
    Stack myStack(10);
    cout << myStack.top() << endl;
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);
    myStack.push(60);
    cout << myStack.top() << endl;
    cout << myStack.pop() << endl;
    cout << myStack.pop() << endl;
    cout << myStack.pop() << endl;
    cout << myStack.pop() << endl;
    cout << myStack.pop() << endl;
    cout << myStack.pop() << endl;
    cout << myStack.pop() << endl;
    cout << myStack.pop() << endl;
    cout << myStack.getSize() << endl;
    return 0;
}