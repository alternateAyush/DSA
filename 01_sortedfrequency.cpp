#include <bits/stdc++.h>
using namespace std;

void freq(string s)
{
    int arr[26];
    for (int i = 0; i < 26; i++)
    {
        arr[i] = 0;
    }
    for (char x : s)
    {
        int temp = x;
        arr[temp - 97]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != 0)
        {
            char x = (97 + i);
            cout << x << " " << arr[i] << endl;
        }
    }
}

int main()
{
    string s;
    cin >> s;
    freq(s);
    return 0;
}