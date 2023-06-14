#include <bits/stdc++.h>
using namespace std;

void addAdj(vector<int> adj[], int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

void Dfs(vector<int> adj[], int s, bool visited[])
{
    cout << s << " ";
    visited[s] = true;
    for (int i : adj[s])
    {
        if (visited[i] == false)
        {
            Dfs(adj, i, visited);
        }
    }
}

void printDfs(vector<int> adj[], int s, int n)
{
    bool visited[n] = {false};
    Dfs(adj, s, visited);
}

int main()
{
    int n = 5;
    int s = 0;
    vector<int> adj[n];
    addAdj(adj, 0, 1);
    addAdj(adj, 0, 2);
    addAdj(adj, 0, 3);
    addAdj(adj, 1, 3);
    addAdj(adj, 1, 4);
    addAdj(adj, 2, 3);
    addAdj(adj, 3, 4);
    printDfs(adj, s, n);

    return 0;
}