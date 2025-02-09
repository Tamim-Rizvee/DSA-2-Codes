#include<bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;


void dijkstra(unordered_map<int , list<pair<int, int>>> &graph, int node, vector<int> &dist, vector<int> &parent, int src = 1)
{
    dist[src] = 0;
    vector<bool> visited(node + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    visited[src] = true;
    pq.push({0, src});
    while(!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();
        visited[src] = true;
        for(auto &x : graph[node])
        {
            int v = x.first, w = x.second;
            if(!visited[v])
            {
                if(dist[v] > dist[node] + w)
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
    int node, edges;
    cin >> node >> edges;
    unordered_map<int , list<pair<int, int>>> adjlist;
    vector<int> parent(node + 1, -1), dist(node + 1, INT_MAX);
    while(edges--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjlist[u].push_back({v, w});
    }
    dijkstra(adjlist, node, dist, parent);
    for (int i = 1; i <= node; i++)
    {
        cout << i << "->";
        if(dist[i] == INT_MAX)
            cout << "inf";
        else
            cout << dist[i];
        cout << uwu;
    }
        return 0;
}