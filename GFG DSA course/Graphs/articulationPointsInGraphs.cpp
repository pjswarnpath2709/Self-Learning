#include <bits/stdc++.h>
using namespace std;

void dfsHelper(vector<int> adj[], vector<bool> &visited, vector<int> &disc, vector<int> &low, int parent, int node, int &timer, set<int> &artPoints)
{
    visited[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;
    for (auto nbr : adj[node])
    {
        if (visited[nbr] && parent == nbr)
        {
            // ignore
            continue;
        }
        if (!visited[nbr])
        {
            // agar nbr visited hi nahi hai toh bhai ke liye dfs call kardo
            dfsHelper(adj, visited, disc, low, node, nbr, timer, artPoints);
            low[node] = min(low[node], low[nbr]);

            if (low[nbr] >= disc[node] && parent != -1)
            {
                // yaha pe it's a
                artPoints.insert(node);
            }
            child++;
        }
        else
        {
            // backEdge
            low[node] = min(low[node], disc[nbr]);
        }
    }
    if (parent == -1 && child > 1)
    {
        artPoints.insert(node);
    }
}
set<int> articulationPoints(vector<int> adj[], int V)
{
    vector<int> disc(V, -1);
    vector<bool> visited(V, false);
    vector<int> low(V, -1);
    int timer = 0;
    set<int> artPoints;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfsHelper(adj, visited, disc, low, -1, i, timer, artPoints);
        }
    }
    return artPoints;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 0, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);

    set<int> ap = articulationPoints(adj, V);
    for (auto &ele : ap)
    {
        cout << ele << " ";
    }
    cout << "\n";
    return 0;
}
