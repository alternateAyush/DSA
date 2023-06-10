#include <bits/stdc++.h>
using namespace std;

void frequency(int arr[], int n)
{
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(0);
    }
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map[arr[i]]++;
    }
    for (auto x : map)
    {
        cout << x.first << " : " << x.second << endl;
    }
    cout << endl;
    return;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    frequency(arr, n);
    return 0;
}