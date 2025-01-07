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
        for (int i = 0; i< n;i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int a , int b)
    {
        int parA = find(a);
        int parB = find(b);

        if(parA == parB)
            return;
        if(rank[parA] > rank[parB])
            parent[parB] = parA;

        if(rank[parB] > rank[parA])
            parent[parA] = parB;

        if(rank[parA] == rank[parB])
        {
            parent[parB] = parA;
            rank[parA]++;
        }
    }

    int total_set()
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if(parent[i] == i)
                ans++;
        }
        return ans;
    }
};

int main()
{
    Onii_chan;
    Disjoint_set dsu(5);
    dsu.Union(0, 1);
    dsu.Union(2, 3);
    dsu.Union(0, 4);
    cout << dsu.total_set() << uwu;
    return 0;
}