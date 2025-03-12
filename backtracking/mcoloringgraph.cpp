#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

void print_color(vector<int> &color)
{
    for (int &x : color)
        cout << x << " ";
    cout << uwu;
}

bool isSafe(vector<vector<int>> &graph, vector<int> &color, int v, int c)
{
    int n = graph[v].size();
    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] && color[i] == c)
            return false;
    }
    return true;
}

bool graph_coloring(vector<vector<int>> &graph, int m, vector<int> &color, int v)
{
    int n = graph.size();
    if (v == n)
    {
        print_color(color);
        return true;
    }
    for (int c = 1; c <= m; c++)
    {
        if(isSafe(graph, color, v, c))
        {
            color[v] = c;
            if(graph_coloring(graph, m, color, v + 1))
                return true;
            color[v] = 0;
        }
    }
    return false;
}

int main()
{
    Onii_chan;
    vector<vector<int>> graph = {{0, 1, 1, 1},
                                 {1, 0, 1, 0},
                                 {1, 1, 0, 1},
                                 {1, 0, 1, 0}};
    int m = 3;
    int n = graph.size();
    vector<int> color(n, 0);
    graph_coloring(graph, m, color, 0);
    return 0;
}