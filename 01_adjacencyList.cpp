#include <bits/stdc++.h>
using namespace std;

void addAdj(vector<int> v[], int x, int y)
{
    v[x].push_back(y);
    v[y].push_back(x);
}

void print(vector<int> v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (auto j : v[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 4;
    vector<int> v[n];
    addAdj(v, 0, 1);
    addAdj(v, 0, 2);
    addAdj(v, 1, 2);
    addAdj(v, 2, 3);
    print(v, n);
    return 0;
}