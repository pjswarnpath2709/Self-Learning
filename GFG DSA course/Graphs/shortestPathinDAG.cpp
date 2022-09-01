#include <bits/stdc++.h>
using namespace std;

class AdjNode
{
public:
    int vertex;
    int weight;
    AdjNode(int _v, int _w)
    {
        this->vertex = _v;
        this->weight = _w;
    }
};
class Graph
{
public:
    vector<AdjNode *> *adj;
    Graph(int V)
    {
        adj = new vector<AdjNode *>[V];
    }

    void addEdge(int u, int v, int weight)
    {
        AdjNode *node = new AdjNode(v, weight);
        adj[u].push_back(node);
    }

    vector<int> topoLogicalSort(vector<AdjNode *> *adj, int V);
};

vector<int> Graph ::topoLogicalSort(vector<AdjNode *> *adj, int V)
{

    vector<int> indegrees(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto ele : adj[i])
        {
            indegrees[ele->vertex]++;
        }
    }

    queue<int> qt;
    for (int i = 0; i < V; i++)
    {
        if (indegrees[i] == 0)
        {
            // TODO: to implement shortestPathInDAG
        }
    }
}

int main()
{
    return 0;
}