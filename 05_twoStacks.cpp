// implement two stacks in one array.
#include <bits/stdc++.h>
using namespace std;

struct Stack
{
    int *arr;
    int cap;
    int top1;
    int top2;
    Stack(int n)
    {
        cap = n;
        top1 = -1;
        top2 = n;
        arr = new int[n];
    }
    bool push1(int x)
    {
        if (top1 + 1 < top2)
        {
            top1++;
            arr[top1] = x;
            return true;
        }
        return false;
    }
    bool push2(int x)
    {
        if (top2 - 1 > top1)
        {
            top2--;
            arr[top2] = x;
            return true;
        }
        return false;
    }
    int pop1()
    {
        if (top1 >= 0)
        {
            int temp = arr[top1];
            top1--;
            return temp;
        }
        return INT32_MIN;
    }
    int pop2()
    {
        if (top2 < cap)
        {
            int temp = arr[top1];
            top2++;
            return temp;
        }
        return INT32_MIN;
    }
    int getTop1()
    {
        if (top1 >= 0)
        {
            return arr[top1];
        }
        return INT32_MIN;
    }
    int getTop2()
    {
        if (top2 < cap)
        {
            return arr[top2];
        }
        return INT32_MIN;
    }
    int isFull()
    {
        if (top1 + 1 == top2)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    return 0;
}