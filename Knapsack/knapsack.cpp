#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

class item
{
public:
    int value, weight,serial;
    float ratio_;
    item(int value, int weight, int serial) : value(value), weight(weight), serial(serial), ratio_((float)value / weight) {}
};

void print(vector<item> &items)
{
    cout << "------------------------------------------------------------" << uwu;
    for (auto x : items)
    {
        cout << x.value << " " << x.weight << " " << x.ratio_ << uwu;
        cout << uwu;
    }
}

bool comp(item &a, item &b)
{
    return a.ratio_ > b.ratio_;
}

float fractional_knapsck(int n, int w, vector<item> &items)
{
    sort(items.begin(), items.end(), comp);
    float profit = 0;
    for (auto x : items)
    {
        if (w > x.weight)
        {
            profit += x.value;
            w -= x.weight;
            cout << "Taking " << x.serial << " th item of weight " << x.weight << " and value "<< x.value << uwu;
        }
        else
        {
            profit += (w * x.ratio_);
            cout << "Taking " << x.serial << " th item of weight " << w << " and value "<< w * x.ratio_ << uwu;
            break;
        }
    }
    return profit;
}

int main()
{
    // Onii_chan;
    int n, w;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter the size of the knapsack: ";
    cin >> w;
    vector<item> items;
    for (int i = 0; i < n; i++)
    {
        int value, weight;
        cout << "Enter the value and the weight of the " << i + 1 << "th item: ";
        cin >> value >> weight;
        items.push_back(item(value, weight, i+1));
    }
    print(items);
    float profit = fractional_knapsck(n, w, items);
    cout << "Maximum profit is: " << profit << uwu;
    return 0;
}
