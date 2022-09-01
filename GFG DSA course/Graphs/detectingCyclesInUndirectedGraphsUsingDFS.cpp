#include <bits/stdc++.h>
using namespace std;
bool dfsRec(vector<int> adj[], vector<bool> &visited, int source, int parent)
{
    // mark the source as visited
    visited[source] = true;

    for (auto ele : adj[source])
    {

        // either it's adjacent is not visited
        if (visited[ele] == false)
        {
            // if it contain any cycle
            if (dfsRec(adj, visited, ele, source))
            {
                return true;
            }
        }
        // either it's visited , but it's not parent
        else if (visited[ele] && ele != parent)
        {
            return true;
        }
        // either it's visited , but it's the parent node only
        else
        {
            continue;
        }
    }
    return false;
}
bool detectCycle(vector<int> adj[], int v)
{
    vector<bool> visited(v);

    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    // to handle disconnected graphs
    for (int i = 0; i < v; i++)
    {
        // if a node is not visited
        if (visited[i] == false)
        {
            // if the node contains a cycle
            if (dfsRec(adj, visited, i, -1))
            {
                return true;
            }
        }
    }
    return false;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

int main()
{
    int V = 6;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);

    if (detectCycle(adj, V))
        cout << "Cycle found";
    else
        cout << "No cycle found";

    return 0;
}