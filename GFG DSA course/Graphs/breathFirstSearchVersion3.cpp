#include <bits/stdc++.h>
using namespace std;

void printGraph(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        for (auto ele : adj[i])
        {
            cout << ele << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printBFS(vector<int> adj[], int V, int source, vector<bool> &visited)
{
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();

        cout << vertex << " ";

        for (auto ele : adj[vertex])
        {
            if (visited[ele] == false)
            {
                visited[ele] = true;
                q.push(ele);
            }
        }
    }
}

int BFSDis(vector<int> adj[], int V)
{
    vector<bool> visited(V);
    int counter = 0;
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < V; i++)
    {
        if (visited[adj[i][0]] == false)
        {
            counter++;
            visited[adj[i][0]] == true;
            printBFS(adj, V, adj[i][0], visited);
        }
    }
    return counter;
}

int main()
{
    int V = 7;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 4, 6);

    cout << BFSDis(adj, V) << "\n";
    cout << "\n";

    return 0;
}