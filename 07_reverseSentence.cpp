#include <bits/stdc++.h>
using namespace std;

void rWord(string &s, int low, int high)
{
    while (low <= high)
    {
        swap(s[low], s[high]);
        low++;
        high--;
    }
}

string rSen(string &s)
{
    int start = 0;
    int m = s.length();
    for (int i = 0; i < m; i++)
    {
        if (s[i] == ' ')
        {
            rWord(s, start, i - 1);
            start = i + 1;
        }
    }
    rWord(s, start, m - 1);
    rWord(s, 0, m - 1);
    return s;
}

int main()
{
    string s;
    getline(cin, s);
    cout << rSen(s) << endl;
    return 0;
}