#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

bool bfs(vector<vector<int>> &rgraph, int source, int sink, vector<int> &parent)
{
    queue<int> q;
    q.push(source);
    vector<bool> visited(rgraph.size(), false);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int i = 0; i < rgraph[node].size(); i++)
        {
            if (!visited[i] && rgraph[node][i] > 0)
            {
                q.push(i);
                parent[i] = node;
                visited[i] = true;
            }
        }
    }
    return visited[sink];
}

int ford_fulkerson(vector<vector<int>> &graph, int source, int sink)
{
    vector<vector<int>> rgraph = graph;
    vector<int> parent(graph.size());
    int max_flow = 0;

    while (bfs(rgraph, source, sink, parent))
    {
        int path_flow = INT_MAX;
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            path_flow = min(path_flow, rgraph[u][v]);
        }
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            rgraph[u][v] -= path_flow;
            rgraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main()
{
    Onii_chan;
    vector<vector<int>> graph = {{0, 16, 13, 0, 0, 0},
                                 {0, 0, 10, 12, 0, 0},
                                 {0, 4, 0, 0, 14, 0},
                                 {0, 0, 9, 0, 0, 20},
                                 {0, 0, 0, 7, 0, 4},
                                 {0, 0, 0, 0, 0, 0}};

    cout <<"Max Flow : " <<ford_fulkerson(graph, 0, 5) << uwu;

    return 0;
}