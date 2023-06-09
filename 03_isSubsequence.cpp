#include <bits/stdc++.h>
using namespace std;

bool isSub(string mainStr, string subStr)
{
    int i = 0;
    int j = 0;
    int len1 = mainStr.length();
    int len2 = subStr.length();
    while (j < len2 && i < len1)
    {
        if (mainStr[i] == subStr[j])
        {
            j++;
        }
        i++;
    }
    return (j == len2);
}

int main()
{
    cout << boolalpha;
    string mainStr, subStr;
    cin >> mainStr;
    cin >> subStr;
    cout << isSub(mainStr, subStr) << endl;
    return 0;
}