#include <bits/stdc++.h>
using namespace std;

struct AdjNode
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
    int V;
    Graph(int _V)
    {
        V = _V;
        adj = new vector<AdjNode *>[V];
    }

    void addEdge(int u, int v, int weight)
    {
        AdjNode *node = new AdjNode(v, weight);
        adj[u].push_back(node);
    }

    vector<int> topoLogicalSort();
    vector<int> shortestPathInDAG(int source);
};

vector<int> Graph ::topoLogicalSort()
{

    vector<int> indegrees(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto ele : adj[i])
        {
            indegrees[ele->vertex]++;
        }
    }
    vector<int> topo_sort;
    queue<int> qt;
    for (int i = 0; i < V; i++)
    {
        if (indegrees[i] == 0)
        {
            qt.push(i);
        }
    }
    while (!qt.empty())
    {
        int vertex = qt.front();
        qt.pop();
        topo_sort.push_back(vertex);
        for (auto ele : adj[vertex])
        {
            if (indegrees[ele->vertex] > 0)
            {
                indegrees[ele->vertex]--;
            }
            if (indegrees[ele->vertex] == 0)
            {
                qt.push(ele->vertex);
            }
        }
    }
    return topo_sort;
}

vector<int> Graph::shortestPathInDAG(int source)
{
    vector<int> distances(V, INT_MAX);
    distances[source] = 0;

    vector<int> topological_sorted_vertexes = topoLogicalSort();

    // traverse in topological order as it will help us to move in forward direction
    for (int u : topological_sorted_vertexes)
    {
        // this if chk ensures that the traversing starts from the source only
        if (distances[u] != INT_MAX)
        {
            // any vertex whose distance is finite , then update distances of it's adjacent vertexes
            for (auto ele : adj[u])
            {
                distances[ele->vertex] = min(distances[ele->vertex], distances[u] + ele->weight);
            }
        }
    }

    return distances;
}

int main()
{
    Graph g(6);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 4, 1);
    g.addEdge(1, 2, 3);
    g.addEdge(4, 2, 2);
    g.addEdge(4, 5, 4);
    g.addEdge(2, 3, 6);
    g.addEdge(5, 3, 1);
    int s = 0;
    cout << "Following are shortest distances from source " << s << " \n";
    vector<int> distances = g.shortestPathInDAG(s);
    for (auto ele : distances)
    {
        cout << ele << " ";
    }
    cout << "\n";

    return 0;
}