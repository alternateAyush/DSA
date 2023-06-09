#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s1, string s2)
{
    int arr1[26] = {0};
    int arr2[26] = {0};
    if (s1.length() != s2.length())
    {
        return false;
    }
    for (int i = 0; i < s1.length(); i++)
    {
        char temp1 = s1[i];
        char temp2 = s2[i];
        arr1[temp1 - 97]++;
        arr2[temp2 - 97]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cout << boolalpha;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    cout << isAnagram(s1, s2) << endl;
    return 0;
}