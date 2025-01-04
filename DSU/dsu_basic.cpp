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
        rank.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x)
    {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    void union_(int a, int b)
    {
        int parA = find(a);
        int parB = find(b);
        if (parA == parB)
            return;
        if (rank[parA] > rank[parB])
        {
            parent[parB] = parA;
        }
        else if (rank[parA] < rank[parB])
        {
            parent[parA] = parB;
        }
        else
        {
            parent[parB] = parA;
            rank[parA]++;
        }
    }

    int total_set()
    {
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (parent[i] == i)
                count++;
        }
        return count;
    }
};
int main()
{
    Onii_chan;
    int n, e, a, b;
    cin >> n >> e;
    Disjoint_set dsu(n);
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        dsu.union_(a, b);
    }
    cout << dsu.total_set() << uwu;
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