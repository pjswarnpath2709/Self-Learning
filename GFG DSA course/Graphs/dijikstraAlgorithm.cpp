#include <bits/stdc++.h>
using namespace std;

void dijkstraAlgorithm(vector<pair<int, int>> adj[], int V, int src)
{
    vector<int> distance(V, INT_MAX);
    distance[src] = 0;
    vector<bool> isFinalized(V, false);

    // yeh minimum wali cheej ab sambhal lega
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < distance.size(); i++)
    {
        pq.push({distance[i], i});
    }

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        isFinalized[u] = true;

        // relax all the adjacent vertexes
        for (auto p : adj[u])
        {
            int vert = p.first;
            int wht = p.second;
            if (isFinalized[vert] == false)
            {
                distance[vert] = min(distance[vert], distance[u] + wht);
                pq.push({distance[vert], vert});
            }
        }
    }

    for (int i = 0; i < distance.size(); i++)
    {
        cout << i << " " << distance[i] << "\n";
    }
    cout << "\n";
}

void addEdge(vector<pair<int, int>> adj[], int u, int v, int weight)
{
    adj[v].push_back(make_pair(u, weight));
    adj[u].push_back(make_pair(v, weight));
}
int main()
{
    int V = 9;
    vector<pair<int, int>> adj[V]; // { vertex , weight }
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);
    // for (int i = 0; i < V; i++)
    // {
    //     for (auto p : adj[i])
    //     {
    //         cout << p.first << " " << p.second << "\n";
    //     }
    // }
    dijkstraAlgorithm(adj, V, 0);

    return 0;
}