#include <bits/stdc++.h>
using namespace std;

bool isPallindrome(string s)
{
    int begin = 0;
    int end = s.length() - 1;
    while (begin <= end)
    {
        if (s[begin] != s[end])
        {
            return false;
        }
        begin++;
        end--;
    }
    return true;
}

int main()
{
    cout << boolalpha;
    string s;
    cin >> s;
    cout << isPallindrome(s) << endl;
    return 0;
}