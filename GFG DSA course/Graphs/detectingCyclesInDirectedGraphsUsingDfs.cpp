#include <bits/stdc++.h>
using namespace std;
bool dfsRec(vector<int> adj[], vector<bool> &visited, vector<bool> &recStack, int source)
{
    // mark the current vertex as visited
    visited[source] = true;

    // mark the recursion stack for the current vertex as it's started
    recStack[source] = true;

    // mark all the vertexes as
    for (auto ele : adj[source])
    {
        if (visited[ele] == false && dfsRec(adj, visited, recStack, ele))
        {
            // if it already have a cycle
            return true;
        }

        // if it's already visited and it's recursion call is active then it's a cycle
        else if (recStack[ele])
        {
            return true;
        }
    }

    // mark the recursion call for the current vertex as it's over
    recStack[source] = false;
    return false;
}
bool detectCycleDirected(vector<int> adj[], int V)
{
    vector<bool> recStack(V);
    for (int i = 0; i < V; i++)
    {
        recStack[i] = false;
    }
    vector<bool> visited(V);
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    // handling disconnected graphs
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            // if the graph contains cycle
            if (dfsRec(adj, visited, recStack, i))
            {
                return true;
            }
        }
    }
    return false;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    int V = 6;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 3);

    if (detectCycleDirected(adj, V))
        cout << "Cycle found";
    else
        cout << "No cycle found";

    return 0;
}
