#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

void print_arr(vector<int> &arr)
{
    for (int &x : arr)
        cout << x << " ";
    cout << uwu;
}

bool isSafe(vector<vector<int>> &graph, vector<int> &path, int v, int pos)
{
    if (graph[path[pos - 1]][v] == 0)
        return false;
    for (int i = 0; i < pos; i++)
    {
        if (path[i] == v)
            return false;
    }
    return true;
}

bool hamilton_cycle(vector<vector<int>> &graph, vector<int> &path, int pos)
{
    int n = graph.size();
    if (pos == graph.size())
    {
        if (graph[path[pos - 1]][path[0]] == 1)
        {
            print_arr(path);
            return true;
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (isSafe(graph, path, i, pos))
        {
            path[pos] = i;
            if (hamilton_cycle(graph, path, pos + 1))
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

int main()
{
    Onii_chan;
    vector<vector<int>> graph = {{0, 1, 0, 1, 0},
                                 {1, 0, 1, 1, 1},
                                 {0, 1, 0, 0, 1},
                                 {1, 1, 0, 0, 1},
                                 {0, 1, 1, 1, 0}};
    vector<int> path(graph.size(), -1);
    path[0] = 0;
    hamilton_cycle(graph, path, 1);

    return 0;
}