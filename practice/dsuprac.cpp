#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

class Disjoint_set
{
    int n, par;
    vector<int> parent, rank;

public:
    Disjoint_set(int n)
    {
        this->n = n;
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
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
        {
            par = parA;
            parent[parB] = parA;
            rank[parA] += rank[parB];
        }

        if (rank[parB] > rank[parA])
        {
            par = parB;
            parent[parA] = parB;
            rank[parB] += parA;
        }

        if (rank[parA] == rank[parB])
        {
            par = parA;
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

    int size()
    {
        cout << par << uwu;
        return rank[par];
    }
};

int main()
{
    Onii_chan;
    int cities, q;
    cin >> cities >> q;
    Disjoint_set d(cities);
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        d.Union(a, b);
        cout << d.total_set() << " " << d.size() << uwu;
    }
    return 0;
}