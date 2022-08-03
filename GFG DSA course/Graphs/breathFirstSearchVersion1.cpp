#include <bits/stdc++.h>
using namespace std;

void printGraph(vector<vector<int>> &adj)
{
    for (auto ele : adj)
    {
        for (auto item : ele)
        {
            cout << item << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printBFS(vector<vector<int>> &adj, int v, int source)
{
    vector<bool> visitedVertex(v + 1);

    // set all the values false first
    for (int i = 0; i < v + 1; i++)
    {
        visitedVertex[i] = false;
    }

    queue<int> q;
    q.push(source);
    visitedVertex[source] = true;

    while (!q.empty())
    {
        // take the front of the queue out
        int vertex = q.front();
        q.pop();

        // print the vertex at the front of the queue
        cout << vertex << " ";

        // push al the adjacent nodes int he queue
        for (auto ele : adj[vertex])
        {
            if (!visitedVertex[ele])
            {
                visitedVertex[ele] = true;
                q.push(ele);
            }
        }
    }
}

int main()
{
    int v = 5;

    vector<vector<int>> adj;

    for (int i = 0; i < v; i++)
    {
        vector<int> vec;
        vec.push_back(i);
        adj.push_back(vec);
    }
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 2, 4);

    printGraph(adj);

    printBFS(adj, v, 0);

    return 0;
}