#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

vector<int> parent, rankk;
map<int, list<int>> adj;

void make_(int n)
{
    parent.resize(n + 1);
    rankk.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        rankk[i] = 0;
    }
}

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

bool union_(int a, int b)
{
    int parA = find(a);
    int parB = find(b);
    if (parA == parB)
        return false;
    if (rankk[parA] > rankk[parB])
        parent[parB] = parA;
    else if (rankk[parA] < rankk[parB])
        parent[parA] = parB;
    else
    {
        parent[parB] = parA;
        rankk[parA]++;
    }
    adj[a].push_back(b);
    adj[b].push_back(a);
    return true;
}

int main()
{
    Onii_chan;
    int n, m, a, b, w;
    cin >> n >> m;
    make_(n);
    vector<pair<int, pair<int, int>>> edges(n);
    adj.clear();
    while (m--)
    {
        cin >> a >> b >> w;
        edges.push_back({w, {a, b}});
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    for (auto x : edges)
    {
        if (union_(x.second.first, x.second.second))
            ans += x.first;
    }
    cout << ans << uwu;
    for (auto x : adj)
    {
        cout << x.first << "->";
        for (auto y : x.second)
            cout << y << " ";
        cout << uwu;
    }
    return 0;
}

/*
7 11
1 2 2
1 4 8
4 5 21
1 5 14
2 5 25
5 6 13
6 7 1
3 7 9
3 6 5
2 3 19
5 3 17




*/