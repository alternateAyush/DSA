#include <bits/stdc++.h>
using namespace std;

// int count(int arr[], int n)
// {
//     unordered_set<int> set;
//     for (int i = 0; i < n; i++)
//     {
//         set.insert(arr[i]);
//     }
//     return set.size();
// }
// pro
int count(int arr[], int n)
{
    unordered_set<int> set(arr, arr + n);
    return set.size();
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
    cout << count(arr, n) << endl;
    return 0;
}