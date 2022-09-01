#include <bits/stdc++.h>
using namespace std;

vector<int> getIndegrees(vector<int> adj[], int V)
{
    vector<int> indegrees(V);
    for (int i = 0; i < V; i++)
    {
        indegrees[i] = 0;
    }

    for (int i = 0; i < V; i++)
    {
        for (auto ele : adj[i])
        {
            indegrees[ele]++;
        }
    }
    return indegrees;
}

bool detectCycleUsingTopoSort(vector<int> adj[], int V)
{

    vector<int> indegrees = getIndegrees(adj, V);

    queue<int> qt;
    for (int i = 0; i < V; i++)
    {
        if (indegrees[i] == 0)
        {

            qt.push(i);
        }
    }
    // topological is for non-acyclic , every vertex got into queue at some point because at some time indegree goes 0 , hence the count of vertexes with indegree zero is exactly equal to total vertex count

    // here in Cyclic graph there is a certain point where some vertex which are in cycle does not reach indegree zero hence the count of vertexes with indegree zero is not equal to total vertex count
    int countVertex = 0;
    while (!qt.empty())
    {
        int vertex = qt.front();
        qt.pop();

        // count the vertex with the indegree zero
        countVertex++;

        for (auto ele : adj[vertex])
        {
            if (indegrees[ele] > 0)
            {
                indegrees[ele]--;
            }
            else if (indegrees[ele] == 0)
            {

                qt.push(ele);
            }
        }
    }
    cout << "\n";
    return countVertex != V;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 4, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    if (detectCycleUsingTopoSort(adj, V))
    {
        cout << "Cycle Found"
             << "\n";
    }
    else
    {
        cout << "Cycle Not Found"
             << "\n";
    }

    return 0;
}
