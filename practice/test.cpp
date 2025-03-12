#include<bits/stdc++.h>
 
 
using namespace std;
 
 
 
int main()
{
 
 
    int n, e;
    cin >> n >> e;
 
    vector<pair<int,int> >g[n];
 
    for (int i=0; i<e; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
 
    int key[n],par[n],mst[n];
 
    for (int i=0; i<n; i++)
    {
        key[i] = INT_MAX;
        par[i] = -1;
        mst[i] = 0;
    }
 
    /// {weight, vertex};
 
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >pq;
 
    key[0] = 0;
    par[0] = -1;
 
    pq.push({0,0});
 
    for (int i=0; i<n-1; i++)
    {
        int tmp = pq.top().second;
        pq.pop();
        mst[tmp] = 1;
 
        for (auto it : g[tmp])
        {
            int vertex = it.first;
            int weight = it.second;
 
            if (weight < key[vertex] && mst[vertex] == 0)
            {
                key[vertex] = weight;
                par[vertex] = tmp;
                pq.push({key[vertex], vertex});
            }
 
        }
    }
 
 
        int cost = 0;
 
        for (int i=0; i<n; i++) cost += key[i];
 
        cout << cost << endl;
 
}