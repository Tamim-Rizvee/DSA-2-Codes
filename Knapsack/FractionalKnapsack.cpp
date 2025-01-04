#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

class item
{
public:
    int value, weight;
    float ratio;
    item(int value, int weight) : value(value), weight(weight), ratio((float)value / weight) {}
};

bool comp(item &a, item &b) { return a.ratio > b.ratio; }

float fractional_knapsack(vector<item> &items, int w)
{
    float ans = 0;
    sort(items.begin(), items.end(), comp);
    for (int i = 0; i < items.size(); i++)
    {
        if(items[i].weight <= w)
        {
            ans += items[i].value;
            w -= items[i].weight;
        }
        else 
        {
            ans += w * items[i].ratio;
            break;
        }
    }
    return ans;
}

int main()
{
    Onii_chan;
    int w = 50;
    vector<int> value = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    vector<item> items;
    for (int i = 0; i < value.size(); i++)
    {
        items.push_back(item(value[i], weight[i]));
    }
    cout << fractional_knapsack(items, w) << uwu;
    return 0;
}