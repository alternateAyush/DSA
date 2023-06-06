// amximum rectangular area in a histogram

#include <bits/stdc++.h>
using namespace std;

// naive
// int histogram(int n, int arr[])
// {
//     int ans = INT32_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         int temp = arr[i];
//         int t = 0;
//         int j = i;
//         while (j < n && arr[j] >= temp)
//         {
//             t += temp;
//             j++;
//         }
//         j = i - 1;
//         while (j >= 0 && arr[j] >= temp)
//         {
//             t += temp;
//             j--;
//         }
//         ans = max(ans, t);
//     }
//     return ans;
// }

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

vector<int> pre(int n, int arr[])
{
    stack<int> s;
    s.push(0);
    vector<int> v;
    v.push_back(-1);
    for (int i = 1; i < n; i++)
    {
        while (s.empty() == false && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        if (s.empty() == true)
        {
            v.push_back(-1);
        }
        else
        {
            v.push_back(s.top());
        }
        s.push(i);
    }
    return v;
}

vector<int> next(int n, int arr[])
{
    vector<int> v;
    stack<int> s;
    s.push(n - 1);
    v.push_back(n);
    for (int i = n - 2; i >= 0; i--)
    {
        while (s.empty() == false && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        if (s.empty() == true)
        {
            v.push_back(n);
        }
        else
        {
            v.push_back(s.top());
        }
        s.push(i);
    }
    reverse(v.begin(), v.end());
    return v;
}

int histogram(int n, int arr[])
{
    int ans = INT32_MIN;
    vector<int> nextSmall = next(n, arr);
    vector<int> preSmall = pre(n, arr);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        curr += (i - preSmall[i] - 1) * arr[i];
        curr += (nextSmall[i] - i - 1) * arr[i];
        ans = max(curr, ans);
    }
    return ans;
}

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

void print(int n, vector<int> v)
{
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
    // cout << histogram(n, arr) << endl;
    vector<int> v = pre(n, arr);
    print(n, v);
    v = next(n, arr);
    print(n, v);
    cout << histogram(n, arr) << endl;

    return 0;
}