#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
#define vp vector<pair<int, int>>
using namespace std;

void dijsktra(vector<vp> &graph, vector<int> &dist, int node, vector<int> &slowfact, int src = 1)
{
    int ans = 0;
    int lowest = slowfact[src];
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
        lowest = min(lowest, slowfact[node]);
        for (auto x : graph[node])
        {
            int v = x.first, w = x.second;
            if (!visited[v])
            {
                if (dist[v] > dist[node] + w * lowest)
                {
                    dist[v] = dist[node] + w * lowest;
                    pq.push({dist[v], v});
                }
            }
        }
    }
}

int main()
{
    Onii_chan;
    int t;
    cin >> t;
    while (t--)
    {
        int node, edge;
        cin >> node >> edge;
        vector<vp> graph(node + 1);
        vector<int> dist1(node + 1, INT_MAX), slowfact(node + 1, -1), dist(node + 1, INT_MAX);
        while (edge--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        int minIndex = 1;
        for (int i = 1; i <= node; i++)
        {
            cin >> slowfact[i];
            if (slowfact[i] < slowfact[minIndex])
                minIndex = i;
        }
        dijsktra(graph, dist, node, slowfact);
        dijsktra(graph, dist1, node, slowfact, minIndex);
        int ans = min(dist[node], dist1[node] + dist[minIndex]);
        cout << ans << uwu;
    }
    return 0;
}