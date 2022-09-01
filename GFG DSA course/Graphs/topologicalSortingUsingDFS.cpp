#include <bits/stdc++.h>
using namespace std;

// you do normal dfs from any vertex , simple logic is after pushing every descendant of that  vertex push that vertex itself
void DFS(vector<int> adj[], int source, stack<int> &st, vector<bool> &visited)
{
    // jab tak source se related sarre vertexes stack ke andar nahi ajate algorithm calate raho
    visited[source] = true;

    for (auto ele : adj[source])
    {
        if (visited[ele] == false)
        {
            DFS(adj, ele, st, visited);
        }
    }
    st.push(source);
}

void topologicalSortUsingDFS(vector<int> adj[], int V)
{
    stack<int> st;
    vector<bool> visited(V, false);

    // handling for the disconnected graphs
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            DFS(adj, i, st, visited);
        }
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
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
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 2, 4);

    cout << "Following is a Topological Sort of\n";
    topologicalSortUsingDFS(adj, V);
    return 0;
}
