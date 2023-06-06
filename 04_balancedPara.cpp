// balanced : (({[]}))
// unbalanced : ([)] or (())) or [)

#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string a)
{
    int len = a.length();
    stack<char> s;
    for (int i = 0; i < len; i++)
    {
        char t = a[i];
        if (t == '[' || t == '{' || t == '(')
        {
            s.push(t);
        }
        else
        {
            if (s.empty())
            {
                return false;
            }
            int top = s.top();
            if ((t == ']' && top == '[') || (t == '}' && top == '{') || (t == ')' && top == '('))
            {
                s.pop();
            }
        }
    }
    if (s.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    cout << boolalpha;
    string a;
    cin >> a;
    cout << isBalanced(a) << endl;
    return 0;
}