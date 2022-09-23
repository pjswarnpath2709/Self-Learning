#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;
void printSSCUtil(vi adj[], vb &visited, vi &disc, vi &low, stack<int> &st, int parent, int src, int &timer, vector<vi> &ssc)
{
    visited[src] = true;
    disc[src] = low[src] = timer;
    timer++;

    // ab sarre neighbour ko visit karenge
    for (auto nbr : adj[src])
    {
        if (!visited[nbr])
        {
            printSSCUtil(adj, visited, disc, low, st, src, nbr, timer, ssc);
            // update the low
            low[src] = min(low[src], low[nbr]);
        }
        // if already visited and it's a backEdge
        if (visited[src] && parent != src)
        {
            // backEdge
            low[src] = min(low[src], disc[nbr]);
        }
    }
    st.push(src);
    if (low[src] == disc[src])
    {
        vi ssc_ele;
        while (!st.empty())
        {
            ssc_ele.push_back(st.top());
            st.pop();
        }
        ssc.push_back(ssc_ele);
    }
}
void printSSC(vi adj[], int V)
{
    // disc , low , visited , parent , vector<vector<int>> result ,stack
    vi disc(V, -1);
    vi low(V, -1);
    vb visited(V, false);
    stack<int> st;
    vector<vi> ssc;
    int timer = 0;
    // for all the edges
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {

            printSSCUtil(adj, visited, disc, low, st, -1, i, timer, ssc);
        }
    }

    for (auto list : ssc)
    {
        for (auto ele : list)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}
int main()
{
    int V = 11;
    vi adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 6);
    addEdge(adj, 3, 2);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 6);
    addEdge(adj, 5, 7);
    addEdge(adj, 5, 8);
    addEdge(adj, 5, 9);
    addEdge(adj, 6, 4);
    addEdge(adj, 7, 9);
    addEdge(adj, 8, 9);
    addEdge(adj, 9, 8);

    printSSC(adj, V);
    return 0;
}