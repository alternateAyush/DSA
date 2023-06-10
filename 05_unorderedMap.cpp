#include <bits/stdc++.h>
using namespace std;

void print(unordered_map<string, int> map)
{
    for (auto x = map.begin(); x != map.end(); x++)
    {
        cout << x->first << " -> " << x->second << " ";
    }
    cout << endl;
    for (auto x : map)
    {
        cout << x.first << " -> " << x.second << " ";
    }
    cout << endl;
    return;
}

void findValue(unordered_map<string, int> map, string key)
{
    auto x = map.find(key);
    if (x != map.end())
    {
        cout << "Found: " << x->first << " -> " << x->second << endl;
        return;
    }
    cout << "Not found" << endl;
    return;
}

int main()
{
    unordered_map<string, int> map;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string key;
        cin >> key;
        int value;
        cin >> value;
        map.insert({key, value});
    }
    print(map);
    string key;
    cin >> key;
    findValue(map, key);
    map.erase("a");
    print(map);
    cout << map.size() << endl;
    map.erase(map.begin(), map.end());
    cout << map.size() << " " << map.empty() << endl;
    return 0;
}