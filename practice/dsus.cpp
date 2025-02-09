#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

class dsu
{
    vector<int> parent, rank;
    int node;

public:
    dsu(int node)
    {
        this->node = node;
        parent.resize(node + 1);
        rank.resize(node + 1);
        for (int i = 1; i <= node; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }

    void union_(int a , int b)
    {
        int para = find(a);
        int parb = find(b);
        if(para == parb)
            return;
        if(rank[para] > rank[parb])
            parent[parb] = para;
        else if(rank[parb] > rank[para])
            parent[para] = parb;
        else
            parent[parb] = para , rank[para]++;
    }

    int total_set()
    {
        int count = 0;
        for (int i = 1; i <=node; i++)
        {
            if(parent[i] == i)
                count++;
        }
        return count;
    }
};

int main()
{
    Onii_chan;
    int node, edge, a, b;
    cin >> node >> edge;
    dsu d(node);
    while (edge--)
    {
        cin >> a >> b;
        d.union_(a, b);
    }
    cout << d.total_set() << uwu;
    return 0;
}
/*
10 10
10 9
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
*/