#include <bits/stdc++.h>
using namespace std;

// pro
void preGreat(int n, int arr[])
{
    stack<int> s;
    s.push(0);
    cout << "-1 ";
    for (int i = 1; i < n; i++)
    {
        while (s.empty() == false && arr[s.top()] <= arr[i])
        {
            s.pop();
        }
        if (s.empty() == true)
        {
            cout << "-1 ";
        }
        else
        {
            cout << arr[s.top()] << " ";
        }
        s.push(i);
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
    preGreat(n, arr);
    return 0;
}