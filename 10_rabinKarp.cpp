#include <bits/stdc++.h>
using namespace std;

void isFound(string s, string p)
{

    int n = s.length();
    int m = p.length();
    long pHash = 0;
    long sHash = 0;
    int tens = 1;
    int k = 0;
    while (k < m - 1)
    {
        tens *= 10;
        k++;
    }
    cout << "Found at: ";
    for (int i = 0; i < m; i++)
    {
        int temp = p[i];
        int temp2 = s[i];
        pHash = pHash * 10 + temp;
        sHash = sHash * 10 + temp2;
    }
    for (int i = 0; i <= n - m; i++)
    {
        // cout << sHash << " == " << pHash << endl;
        if (sHash == pHash)
        {
            int j;
            cout << " /in for loop/ " << endl;
            for (j = 0; j < m; j++)
            {
                if (p[j] != s[i + j])
                {
                    break;
                }
            }
            if (j == m)
            {
                cout << i << " ";
            }
        }
        sHash = sHash - (s[i] * tens);
        sHash = (sHash * 10) + s[i + m];
    }
    return;
}

int main()
{
    string s;
    cin >> s;
    string p;
    cin >> p;
    isFound(s, p);
    return 0;
}