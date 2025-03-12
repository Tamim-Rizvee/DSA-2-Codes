#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

class Edge
{
public:
    int src, dest, weight;
};

void bellmanFord(vector<Edge> &edges, int V, int E, int src)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int i = 0; i < E; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            cout << "Graph contains negative weight cycle" << uwu;
            return;
        }
    }

    cout << "Vertex Distance from Source" << uwu;
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << dist[i] << uwu;
}

int main()
{
    Onii_chan;

    int V = 5;
    int E = 8;
    vector<Edge> edges(E);

    edges[0] = {0, 1, -1};
    edges[1] = {0, 2, 4};
    edges[2] = {1, 2, 3};
    edges[3] = {1, 3, 2};
    edges[4] = {1, 4, 2};
    edges[5] = {3, 2, 5};
    edges[6] = {3, 1, 1};
    edges[7] = {4, 3, -3};

    bellmanFord(edges, V, E, 0);

    return 0;
}