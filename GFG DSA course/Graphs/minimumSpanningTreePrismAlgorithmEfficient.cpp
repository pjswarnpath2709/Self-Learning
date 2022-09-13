#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V, m;
    cin >> V >> m;
    vector<pair<int, int>> adj[V];

    int a, b, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> wt;
        adj[a].push_back(make_pair(b, wt));
        adj[b].push_back(make_pair(a, wt));
    }

    vector<int> parent(V, -1);
    vector<bool> inMst(V, false);
    vector<int> key(V, false);

    // priority queue banani hai
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // { weight/ key , vertex }

    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0}); // { weight/ key , vertex }
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        inMst[u] = true;

        // for all the adjacent of the u do three operations
        for (auto it : adj[u])
        {
            int vert = it.first;
            int weight = it.second;
            if (inMst[vert] == false && weight < key[vert])
            {
                key[vert] = weight;
                parent[vert] = u;
                pq.push({key[vert], vert});
            }
        }
    }

    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \n";
    return 0;
}