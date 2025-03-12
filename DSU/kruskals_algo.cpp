#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

vector<int> parent, level;
map<int, list<int>> adj;
void make_(int n)
{
    parent.resize(n + 1);
    level.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        level[i] = 0;
    }
}
int find_(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find_(parent[x]);
}

bool union_(int a, int b)
{
    int parA = find_(a);
    int parB = find_(b);
    if (parA == parB)
        return false;
    if (level[parA] > level[parB])
        parent[parB] = parA;
    else if (level[parA] < level[parB])
        parent[parA] = parB;
    else
    {
        parent[parB] = parA;
        level[parA]++;
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
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        edges.push_back({w, {a, b}});
    }
    sort(edges.begin(), edges.end());
    int sum = 0;
    for (auto &x : edges)
    {
        if (union_(x.second.first, x.second.second))
            sum += x.first;
    }
    cout << sum << uwu;
    for (auto &x : adj)
    {
        cout << "x.first->";
        for (auto &y : x.second)
            cout << y << " ";
    }
    return 0;
}
/*





*/