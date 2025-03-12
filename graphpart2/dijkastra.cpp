#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

void dijkstra(vector<vector<pair<int, int>>> &graph, vector<int> &dist, vector<int> &parent, int source = 1)
{
    vector<bool> visited(dist.size(), false);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    visited[source] = true;
    while (!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();
        visited[node] = true;
        for (auto x : graph[node])
        {
            int v = x.first, w = x.second;
            if (!visited[v])
            {
                // relaxation
                if (dist[v] > dist[node] + w)
                {
                    dist[v] = dist[node] + w;
                    parent[v] = node;
                    pq.push({dist[v], v});
                }
            }
        }
    }
}

int main()
{
    Onii_chan;
    int node, edge;
    cin >> node >> edge;
    vector<vector<pair<int, int>>> graph(node + 1);
    vector<int> dist(node + 1, INT_MAX), parent(node + 1, -1);
    while (edge--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    dijkstra(graph, dist, parent);
    for (int i = 1; i <= node; i++)
    {
        cout << i << "->" << dist[i] << " ";
    }
    return 0;
}

/*
6 10
1 2 50
1 4 10
2 4 15
1 3 45
2 3 10
4 5 15
6 5 3
5 3 35
3 5 30
5 2 20

*/