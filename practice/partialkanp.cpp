#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

class item
{
public:
    int weight, value;
    float ratio;
    item(int weight, int value) : weight(weight), value(value), ratio((float)value / weight) {}
};

bool comp(item &a, item &b) { return a.ratio > b.ratio; }

int partial_knapsack(vector<item> &items, int w)
{
    sort(items.begin(), items.end(), comp); // nlogn
    int ans = 0;
    for (auto &x : items) // n times O(n + nlogn)
    {
        if (x.weight <= w)
        {
            ans += x.value;
            w -= x.weight;
        }
        else
        {
            ans += x.ratio * w;
            w = 0;
            break;
        }
    }
    return ans;
}

int main()
{
    Onii_chan;
    int n = 3, w = 50;
    vector<int> value = {100, 60, 120};
    vector<int> weight = {20, 10, 30};
    vector<item> items;
    for (int i = 0; i < n; i++)
        items.push_back(item(weight[i], value[i]));
    cout << partial_knapsack(items, w) << uwu;
    return 0;
}