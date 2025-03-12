#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

void bellmanFord(vector<vector<pair<int, int>>> &graph, vector<int> &dist, int node, int src = 1)
{
    dist[src] = 0;
    for (int i = 1; i <= node - 1; i++)
    {
        for (int j = 1; j <= node; j++)
        {
            for (auto &x : graph[j])
            {
                int v = x.first, w = x.second;
                if (dist[j] != INT_MAX && dist[j] + w < dist[v])
                {
                    dist[v] = dist[j] + w;

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
    vector<int> dist(node + 1, INT_MAX);
    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    bellmanFord(graph, dist, node);
    for (int i = 1; i <= node; i++)
    {
        if (dist[i] == INT_MAX)
            cout << i << "->" << "INF" << " ";
        else
            cout << i << "->" << dist[i] << " ";
    }
    return 0;
}

/*
5 6
1 2 2
1 3 4
2 3 -4
3 4 2
4 5 4
5 2 -1
*/