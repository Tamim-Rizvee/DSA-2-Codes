#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

void prims_algo(unordered_map<int, list<pair<int, int>>> &graph, int node)
{
    vector<int> parent(node + 1, -1), key(node + 1, INT_MAX);
    vector<bool> visited(node + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    visited[1] = true;
    key[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();
        visited[node] = true;
        list<pair<int, int>>::iterator it;
        for (it = graph[node].begin(); it != graph[node].end(); it++)
        {
            int v = it->first, w = it->second;
            if (key[v] > w && !visited[v])
            {
                key[v] = w;
                parent[v] = node;
                pq.push({w, v});
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= node; i++)
    {
        cout << i << " " << parent[i] << uwu;
        ans += key[i];
    }
    cout << ans << uwu;
}

int main()
{
    Onii_chan;
    int node, edges;
    cin >> node >> edges;
    unordered_map<int, list<pair<int, int>>> adjlist;
    while (edges--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjlist[u].push_back({v, w});
        adjlist[v].push_back({u, w});
    }
    prims_algo(adjlist, node);
    return 0;
}