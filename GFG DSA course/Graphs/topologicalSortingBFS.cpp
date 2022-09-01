#include <bits/stdc++.h>
using namespace std;

vector<int> getInDegrees(vector<int> adj[], int V)
{
    vector<int> inDegrees(V);
    for (int i = 0; i < V; i++)
    {
        inDegrees[i] = 0;
    }
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            int vertex = adj[i][j];
            inDegrees[vertex]++;
        }
    }
    return inDegrees;
}

void topologicalSort(vector<int> adj[], int V)
{
    vector<bool> visited(V);
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }
    vector<int> inDegrees = getInDegrees(adj, V);

    queue<int> qt;
    for (int i = 0; i < V; i++)
    {
        if (inDegrees[i] == 0)
        {
            visited[i] = true;
            qt.push(i);
        }
    }

    while (!qt.empty())
    {
        int vertex = qt.front();
        cout << vertex << " ";
        qt.pop();

        // decrement the inDegrees for the adjacent vertexes
        for (auto adjVert : adj[vertex])
        {
            if (inDegrees[adjVert] > 0 && !visited[adjVert])
            {
                inDegrees[adjVert]--;
                if (inDegrees[adjVert] == 0)
                {
                    visited[adjVert] = true;
                    qt.push(adjVert);
                }
            }
        }
    }
    cout << "\n";
}

// add and Edge from u to v
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    int V = 5;
    vector<int> adj[5];
    addEdge(adj, 0, 2); // 0 to 2
    addEdge(adj, 0, 3); // 0 to 3
    addEdge(adj, 2, 3); // 2 to 3
    addEdge(adj, 1, 3); // 1 to 3
    addEdge(adj, 1, 4); // 1 to 4

    // for (int i = 0; i < V; i++)
    // {
    //     for (int j = 0; j < adj[i].size(); j++)
    //     {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    topologicalSort(adj, V);
}