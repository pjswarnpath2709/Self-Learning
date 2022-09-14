#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    //  edge u -> v
    adj[u].push_back(v);
}
void dfsHelper(vector<int> adj[], vector<bool> &isVisited, stack<int> &st, int src)
{
    isVisited[src] = true;
    for (auto v : adj[src])
    {
        if (!isVisited[v])
        {
            dfsHelper(adj, isVisited, st, v);
        }
    }
    st.push(src);
}
void printDfs(vector<int> adj[], vector<bool> &isVisited, int src)
{
    isVisited[src] = true;
    for (auto v : adj[src])
    {
        if (!isVisited[v])
        {
            printDfs(adj, isVisited, v);
        }
    }
    cout << src << " ";
}
void printConnectedComponents(vector<int> adj[], int V)
{
    // step 1 : arrange the nodes in the decreasing order of their time
    vector<bool> isVisited(V, false);
    stack<int> st;

    // for handling initial not visited vertex
    for (int i = 0; i < V; i++)
    {
        if (!isVisited[i])
        {
            dfsHelper(adj, isVisited, st, i);
        }
    }

    // step 2 : reverse all the edges of the graph
    vector<int> adj_reverse[V];
    for (int i = 0; i < V; i++)
    {
        int u = i;
        for (auto v : adj[u])
        {
            // edges are from u -> v
            // we have to make them v -> u
            addEdge(adj_reverse, v, u);
        }
    }

    // step 3: traverse the reverse graph in the order of stack
    for (int i = 0; i < V; i++)
    {
        isVisited[i] = false;
    }
    while (!st.empty())
    {
        if (!isVisited[st.top()])
        {
            printDfs(adj_reverse, isVisited, st.top());
            cout << "\n";
        }
        if (isVisited[st.top()])
        {
            st.pop();
        }
    }
}

int main()
{
    int V = 5;
    vector<int> adj[5];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);

    printConnectedComponents(adj, V);

    return 0;
}