#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

class Graph
{
    int node, edge;
    map<int, list<pair<int, int>>> adj_list;
    vector<bool> mst_set;

public:
    Graph(int n)
    {
        node = n;
        mst_set.resize(n, false);
    }
    void AddEdge(int u, int v, int w)
    {
        adj_list[u].push_back({w, v});
        adj_list[v].push_back({w, u});
    }

    void print_list()
    {
        for (auto x : adj_list)
        {
            cout << x.first << "->" << uwu;
            for (auto y : x.second)
            {
                cout << y.first << " " << y.second << uwu;
            }
            cout << ".................." << uwu;
        }
    }

    int prims(int src)
    {
        int ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while(!pq.empty())
        {
            int cost = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if(!mst_set[u])
            {
                ans += cost;
                mst_set[u] = true;
                for(auto &x : adj_list[u])
                {
                    if(!mst_set[x.second])
                        pq.push(x);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Onii_chan;
    int n, e;
    cin >> n >> e;
    Graph g(n);
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.AddEdge(u, v, w);
    }
    // g.print_list();
    cout << g.prims(0) << uwu;
    return 0;
}

/*
4 5
0 1 10
0 2 15
0 3 30
1 3 40
2 3 50



*/