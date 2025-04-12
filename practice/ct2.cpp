#include<bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

int distance(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void reset_queue(priority_queue<pair<int , pair<int , int>>> &pq)
{
    while(!pq.empty())
    {
        pq.pop();
    }
}

int prims(vector<pair<int , int>> &arr)
{
    int ans = 0;
    int n = arr.size();
    map<pair<int, int>, bool> visited;
    priority_queue<pair<int , pair<int , int>>> pq;
    pq.push({0, arr[0]});
    visited[arr[0]] = true;
    while(!pq.empty())
    {
        pair<int , pair<int , int>> x = pq.top();
        pq.pop();
        ans -= x.first;
        pair<int, int> node = x.second;
        visited[node] = true;
        reset_queue(pq);
        for(int i = 0; i < n; i++)
        {
            if(!visited[arr[i]])
            {
                int dist = distance(node, arr[i]);
                pq.push({-dist, arr[i]});
            }
        }
    }
    return ans;
}

int main()
{
    Onii_chan;
    vector<pair<int, int>> arr = {{1, 5}, {7, 6}, {12, 11}, {13, 1}, {25, 16}};
    cout << prims(arr) << uwu;
    return 0;
}