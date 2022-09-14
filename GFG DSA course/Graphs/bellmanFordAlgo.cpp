#include <bits/stdc++.h>
using namespace std;

void bellManFordAlgorithm(vector<pair<int, int>> adj[], int V, int src)
{

    vector<int> distance(V, INT_MAX);
    distance[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        // for every vertex u -> v , relax it
        for (int i = 0; i < V; i++)
        {
            int u = i;
            for (auto ele : adj[u])
            {
                int vert = ele.first;
                int wht = ele.second;
                distance[vert] = min(distance[vert], distance[u] + wht);
            }
        }
    }

    for (int i = 0; i < distance.size(); i++)
    {
        cout << i << " " << distance[i] << "\n";
    }
}
void addEdge(vector<pair<int, int>> adj[], int u, int v, int w)
{
    adj[u].push_back({v, w});
}
int main()
{
    int V = 4;
    vector<pair<int, int>> adj[V];
    addEdge(adj, 0, 1, 1);
    addEdge(adj, 0, 2, 4);
    addEdge(adj, 1, 2, -3);
    addEdge(adj, 1, 3, 2);
    addEdge(adj, 2, 3, 3);

    bellManFordAlgorithm(adj, V, 0);

    return 0;
}