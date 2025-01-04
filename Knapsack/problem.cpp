#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

int main()
{
    Onii_chan;
    int node, edge;
    cin >> node >> edge;
    map<int, list<pair<int, int>>> adjlist;
    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjlist[u].push_back({w, v});
        adjlist[v].push_back({w, u});
    }

    vector<bool> mst_set(node, false);
    vector<int> parent(node, -1);
    vector<int> key(node, INT_MAX);
    
    //pair<weight, node>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    key[0] = 0;
    parent[0] = -1;

    pq.push({0, 0});
    for (int i = 0; i < node; i++)
    {
        int tmp = pq.top().second;
        pq.pop();
        mst_set[tmp] = true;
        for (auto &x : adjlist[tmp])
        {
            int weight = x.first;
            int node = x.second;

            if (weight < key[node] && !mst_set[node])
            {
                key[node] = weight;
                parent[node] = tmp;
                pq.push({key[node], node});
            }
        }
    }
    int ans = 0;
    for (auto &x : key)
        ans += x;

    cout << ans << uwu;
return 0;
}

/*
4 5
0 1 10
1 2 5
0 2 4
2 3 6
3 1 8



*/