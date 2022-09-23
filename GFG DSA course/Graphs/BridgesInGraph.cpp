#include <bits/stdc++.h>
using namespace std;

void dfsHelper(vector<int> adj[], vector<bool> &visited, vector<int> &discovery, vector<int> &low, vector<vector<int>> &bridges, int parent, int node, int &timer)
{
    // mark the src as visited
    visited[node] = true;
    discovery[node] = low[node] = timer;

    timer++;

    for (auto nbr : adj[node])
    {
        if (visited[nbr] && nbr == parent)
        {
            // ignore
            continue;
        }
        if (!visited[nbr])
        {
            // nbr ke liye dfs call kardo
            dfsHelper(adj, visited, discovery, low, bridges, node, nbr, timer);

            // we will update the low of our node by comapring low of our neighbor
            low[node] = min(low[node], low[nbr]);

            // when the low of the nbr is greater than the discovery time of the node than it will be a bridge
            if (low[nbr] > discovery[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                bridges.push_back(ans);
            }
        }
        else
        {
            // backEdge , here we have to handle special case
            low[node] = min(low[node], discovery[nbr]);
        }
    }
}
void bridgesInGraphs(vector<int> adj[], int V)
{
    vector<int> discovery(V, -1);
    vector<int> low(V, INT_MAX);
    vector<bool> visited(V, false);
    discovery[0] = 0;
    int timer = 0;
    vector<vector<int>> bridges;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfsHelper(adj, visited, discovery, low, bridges, -1, i, timer);
        }
    }
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    return 0;
}