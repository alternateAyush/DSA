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

void bfs(vector<int> v[], int n, int s)
{
    queue<int> q;
    q.push(s);
    bool visited[n + 1] = {false};
    visited[s] = true;
    cout << s << " ";
    while (q.empty() == false)
    {
        int x = q.front();
        q.pop();
        for (auto i : v[x])
        {
            if (visited[i] == false)
            {
                cout << i << " ";
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int n = 4; // 6
    vector<int> v[n];
    // addAdj(v, 0, 1);
    // addAdj(v, 0, 2);
    // addAdj(v, 0, 5);
    // addAdj(v, 1, 3);
    // addAdj(v, 2, 4);
    // addAdj(v, 3, 5);
    // addAdj(v, 4, 5);
    addAdj(v, 1, 0);
    addAdj(v, 1, 2);
    addAdj(v, 1, 3);
    addAdj(v, 0, 2);
    addAdj(v, 2, 3);
    print(v, n);
    cout << "====" << endl;
    bfs(v, n, 0);
    return 0;
}