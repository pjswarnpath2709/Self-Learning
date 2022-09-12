

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isCyclicConnected(vector<int> adj[], int s,
                           int V, vector<bool> &visited)
    {
        vector<int> parent(V, -1);

        // Create a queue for BFS
        queue<int> q;
        visited[s] = true;
        q.push(s);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto v : adj[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                    parent[v] = u;
                }
                else if (parent[u] != v)
                    return true;
            }
        }
        return false;
    }

    bool isCyclicDisconnected(vector<int> adj[], int V)
    {
        // Mark all the vertices as not visited
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
            if (!visited[i] && isCyclicConnected(adj, i,
                                                 V, visited))
                return true;
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        return isCyclicDisconnected(adj, V);
    }
};

int main()
{

    return 0;
}