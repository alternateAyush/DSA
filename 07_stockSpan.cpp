// arr[] = 30 20 25 28 27 29
// output= 1 1 2 3 1 5

#include <bits/stdc++.h>
using namespace std;

// naive
// void span(int n, int arr[])
// {
//     for (int i = 0; i < n; i++)
//     {
//         int count = 1;
//         for (int j = i - 1; j >= 0; j--)
//         {
//             if (arr[j] <= arr[i])
//             {
//                 count++;
//             }
//             else
//             {
//                 break;
//             }
//         }
//         cout << count << " ";
//     }
//     cout << endl;
// }

void span(int n, int arr[])
{
    stack<int> myStack;
    myStack.push(0);
    cout << 1 << " ";
    for (int i = 1; i < n; i++)
    {
        while (myStack.empty() == false && arr[myStack.top()] <= arr[i])
        {
            myStack.pop();
        }
        if (myStack.empty() == true)
        {
            cout << i + 1 << " ";
        }
        else
        {
            cout << i - myStack.top() << " ";
        }
        myStack.push(i);
    }
    cout << endl;
    return;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    span(n, arr);
    return 0;
}