#include <bits/stdc++.h>
using namespace std;

struct Stack
{
    int *arr, *next, *top;
    int K, freeTop, cap;
    Stack(int k, int n)
    {
        K = k;
        cap = n;
        arr = new int[n];
        next = new int[n];
        top = new int[K];
        for (int i = 0; i < K; i++)
        {
            top[i] = -1;
        }
        for (int i = 0; i < n - 1; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
        freeTop = 0;
    }

    void push(int x, int k)
    {
        int i = freeTop;
        freeTop = next[i];
        next[i] = top[k];
        top[k] = i;
        arr[i] = x;
    }

    int pop(int k)
    {
        int i = top[k];
        top[k] = next[i];
        next[freeTop] = i;
        freeTop = i;
        return arr[i];
    }
};

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}

int main()
{
    int k;
    cin >> k;
    int n;
    cin >> n;
    Stack myStack = Stack(k, n);
    print(myStack.top, k);
    print(myStack.next, n);
}