#include <bits/stdc++.h>
using namespace std;

void addEgde(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        for (auto ele : adj[i])
        {
            cout << ele << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    int v = 4;
    vector<int> adj[v];
    addEgde(adj, 0, 1);
    addEgde(adj, 0, 2);
    addEgde(adj, 1, 2);
    addEgde(adj, 1, 3);

    printGraph(adj, v);

    return 0;
}