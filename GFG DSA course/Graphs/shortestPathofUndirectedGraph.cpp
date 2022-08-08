#include <bits/stdc++.h>
using namespace std;

void getShortestPath(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &distances, int source, int V)
{
    queue<int> qt;

    while (!qt.empty())
    {
        int vertex = qt.front();
        qt.pop();

        //////+++++++++++++++++++++++++++++++++++++++++//////

        for (auto ele : adj[vertex])
        {
            if (!visited[ele])
            {
                visited[ele] = true;
                distances[ele] = distances[vertex] + 1;
                qt.push(ele);
            }
        }

        //////+++++++++++++++++++++++++++++++++++++++++//////
    }
}

void shortestPathOfUndirectedGraph(vector<vector<int>> &adj, int source, int V)
{
    vector<bool> visited(V);
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    //////+++++++++++++++++++++++++++++++++++++++++//////

    vector<int> distances(V);
    for (int i = 0; i < V; i++)
    {
        distances[i] = INT_MAX;
    }
    distances[source] = 0;

    //////+++++++++++++++++++++++++++++++++++++++++//////

    getShortestPath(adj, visited, distances, source, V);

    for (int i = 0; i < V; i++)
    {
        cout << distances[i] << "\n";
    }

    //////+++++++++++++++++++++++++++++++++++++++++//////
}

int main()
{

    return 0;
}