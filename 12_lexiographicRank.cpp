#include <bits/stdc++.h>
using namespace std;

int fac(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * fac(n - 1);
}

const int m = 256;

int ranked(string s)
{
    int n = s.length();
    int arr[m] = {0};
    for (int i = 0; i < n; i++)
    {
        arr[s[i]]++;
    }
    for (int i = 1; i < m; i++)
    {
        arr[i] += arr[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        arr[s[i]] -= 1;
    }
    int f = fac(n);
    int res = 1;
    for (int i = 0; i < n - 1; i++)
    {
        f = f / (n - i);
        res = res + (arr[s[i]] * f);
        for (int j = s[i]; j < m; j++)
        {
            arr[j]--;
        }
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << ranked(s) << endl;
    return 0;
}