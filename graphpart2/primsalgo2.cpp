#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

void print(map<int, list<pair<int, int>>> &adjlist)
{
    for (auto &x : adjlist)
    {
        cout << x.first << " -> ";
        for (auto &y : x.second)
            cout << y.first << " " << y.second << " , ";
        cout << uwu;
    }
}

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
    //print(adjlist);
    // pair<weight , node>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<bool> mst_set(node, false);
    vector<int> parent(node, -1), key(node, INT_MAX);

    parent[0] = -1;
    key[0] = 0;
    pq.push({0, 0});

    while(!pq.empty())
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
9 11
0 1 30
1 2 60
2 3 30
3 4 30
4 2 60
2 5 80
5 6 30
0 7 30
8 0 40
0 4 20
7 1 20




*/