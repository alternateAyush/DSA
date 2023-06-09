#include <bits/stdc++.h>
using namespace std;

void find(string mainStr, string pattern)
{
    int n = mainStr.length();
    int m = pattern.length();
    cout << "Found at: ";
    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (mainStr[i + j] != pattern[j])
            {
                break;
            }
        }
        if (j == m)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    string mainStr, pattern;
    cin >> mainStr;
    cin >> pattern;
    find(mainStr, pattern);
}