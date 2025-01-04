#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;
int main()
{
    Onii_chan;
    int node, edges;
    cin >> node >> edges;
    map<int, list<pair<int, int>>> adjlist; // pair<weight , node>
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjlist[u].push_back({w, v});
        adjlist[v].push_back({w, u});
    }

    // pair<weight , node>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<bool> mst_set(node, false);
    vector<int> parent(node, -1), key(node, INT_MAX);

    parent[0] = -1;
    key[0] = 0;
    pq.push({0, 0});

    for (int i = 0; i < node; i++)
    {
        int temp = pq.top().second;
        pq.pop();
        mst_set[temp] = true;
        for (auto &x : adjlist[temp])
        {
            int weight = x.first;
            int node = x.second;

            if (weight < key[node] && !mst_set[node])
            {
                key[node] = weight;
                parent[node] = temp;
                pq.push({weight, node});
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
9 12
0 1 10
0 3 40
0 6 90
1 6 40
1 4 60
1 2 20
2 8 30
3 4 50
4 5 70
2 5 80
2 7 50
6 7 10




*/