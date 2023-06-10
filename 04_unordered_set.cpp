#include <bits/stdc++.h>
using namespace std;

void print(unordered_set<int> s)
{
    if (s.begin() != s.end())
    {
        cout << *(s.begin()) << ",";
        for (auto x : s)
        {
            cout << x << " ";
        }
    }
    cout << " : " << s.size() << endl;
}

int main()
{
    unordered_set<int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        s.insert(temp);
    }
    print(s);
    s.erase(35);

    if (s.end() != s.find(35))
    {
        cout << "found " << *(s.find(35)) << endl;
    }
    auto x = s.find(20);
    s.erase(x);
    print(s);
    s.erase(s.begin(), s.end());
    print(s);
    vector<int> v = {10, 20, 30, 40, 50};
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}