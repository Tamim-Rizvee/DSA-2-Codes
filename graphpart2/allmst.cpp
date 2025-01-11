#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;
int main()
{
    Onii_chan;
    int nodes, edges;
    cin >> nodes >> edges;
    map<int, list<pair<int, int>>> adjlist;
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjlist[u].push_back({w, v});
        adjlist[v].push_back({w, u});
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> par(1, vector<int>(nodes));
    vector<vector<int>> key(1, vector<int>(nodes, INT_MAX));
    vector<bool> mst(nodes, false);

    par[0][0] = 0;
    key[0][0] = 0;
    pq.push({0, {0, 0}});
    while (!pq.empty())
    {
        int weight = pq.top().first;
        int vertex = pq.top().second.first;
        int repo_num = pq.top().second.second; 
        pq.pop();
        mst[vertex] = true;
        for(auto &x : adjlist[vertex])
        {
            int node = x.second, weight = x.first;
            if(!mst[node] && weight < key[repo_num][node])
            {
                key[repo_num][node] = weight;
                par[repo_num][node] = vertex;
                pq.push({weight, {node, repo_num}});
            }

            else if(!mst[node] && weight == key[repo_num][node])
            {
                int new_repo = repo_num + 1;
                key.push_back(key[repo_num]);
                par.push_back(par[repo_num]);
                key[new_repo][node] = weight;
                par[new_repo][node] = vertex;
                pq.push({weight, {node, new_repo}});
            }
        }
    }

    return 0;
}