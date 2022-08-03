#include <bits/stdc++.h>
using namespace std;

void DFSRec(vector<int> adj[], int source, vector<bool> &visited)
{
    visited[source] = true;
    cout << source << " ";

    for (auto ele : adj[source])
    {
        if (visited[ele] == false)
        {
            DFSRec(adj, ele, visited);
        }
    }
}

void DFS(vector<int> adj[], int V)
{
    vector<bool> visited(V);
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            DFSRec(adj, i, visited);
        }
    }
    cout << "\n";
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
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 3, 4);

    cout << "Following is Depth First Traversal for disconnected graphs: " << endl;
    DFS(adj, V);

    return 0;
}