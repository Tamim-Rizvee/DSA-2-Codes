#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
#define vp vector<pair<int, int>>
using namespace std;

void dijsktra(vector<vp> &graph, vector<int> &dist, int node, vector<int> &parent, int src = 1)
{
    dist[src] = 0;
    vector<bool> visited(node + 1, false);
    visited[src] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
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

void print_parent(vector<int> &parent, int node)
{
    if (parent[node] == -1)
    {
        cout << node << " ";
        return;
    }
    print_parent(parent, parent[node]);
    cout << node << " ";
}

int main()
{
    Onii_chan;
    int node, edge;
    cin >> node >> edge;
    vector<vp> graph(node + 1);
    vector<int> dist(node + 1, INT_MAX), parent(node + 1, -1);
    while (edge--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    dijsktra(graph, dist, node, parent);
    if(dist[node] == INT_MAX)
    {
        cout << "-1" << uwu;
        return 0;
    }
    else
        print_parent(parent, node);
    return 0;
}