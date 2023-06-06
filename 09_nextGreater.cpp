#include <bits/stdc++.h>
using namespace std;

void nextGreat(int n, int arr[])
{
    stack<int> s;
    s.push(n - 1);
    vector<int> v;
    v.push_back(-1);
    for (int i = n - 2; i >= 0; i--)
    {
        while (s.empty() == false && arr[s.top()] <= arr[i])
        {
            s.pop();
        }
        if (s.empty() == true)
        {
            v.push_back(-1);
        }
        else
        {
            v.push_back(arr[s.top()]);
        }
        s.push(i);
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
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
    nextGreat(n, arr);
    return 0;
}
