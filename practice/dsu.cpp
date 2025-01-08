#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

class Disjoint_set
{
    int n;
    vector<int> parent, rank;

public:
    Disjoint_set(int n)
    {
        this->n = n;
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool Union(int a, int b)
    {
        int parA = find(a);
        int parB = find(b);

        if (parA == parB)
            return false;
        if (rank[parA] > rank[parB])
            parent[parB] = parA;

        if (rank[parB] > rank[parA])
            parent[parA] = parB;

        if (rank[parA] == rank[parB])
        {
            parent[parB] = parA;
            rank[parA]++;
        }
        return true;
    }

    int total_set()
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (parent[i] == i)
                ans++;
        }
        return ans;
    }

    int kruskal(vector<pair<int , pair<int , int >>> &edges)
    {
        sort(edges.begin() , edges.end());
        int ans = 0;
        for(auto &x : edges)
        {
            if(Union(x.second.first , x.second.second))
                ans += x.first;
        }
        return ans;
    }
};

int main()
{
    Onii_chan;
    int nodes, edge, a, b, w;
    cin >> nodes >> edge;
    Disjoint_set dsu(nodes);
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < edge; i++)
    {
        cin >> a >> b >> w;
        edges.push_back({w, {a, b}});
    }
    cout << dsu.kruskal(edges) << uwu;
    return 0;
}

/*

6 9
0 5 10
5 4 20
4 1 40
1 0 30
0 2 50
2 1 30
1 3 70
3 2 10
3 4 10

*/