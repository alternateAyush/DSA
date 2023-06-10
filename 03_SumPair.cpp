#include <bits/stdc++.h>
using namespace std;

bool sumPair(int arr[], int n, int sum)
{
    unordered_set<int> set(arr, arr + n);
    for (auto x : set)
    {
        if (set.find(x - sum) != set.end() || set.find(sum - x) != set.end())
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cout << boolalpha;
    int sum;
    cin >> sum;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << sumPair(arr, n, sum) << endl;
    return 0;
}