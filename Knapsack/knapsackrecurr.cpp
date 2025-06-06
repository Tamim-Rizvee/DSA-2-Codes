#include<bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

int knap_sack_recurr(vector<pair<int , int>> items , int n , int w)
{
    if(n == 0 || w == 0)
        return 0;
    int item_wt = items[n - 1].second , item_val = items[n - 1].first;
    if(item_wt <= w)
    {
        // include the item
        int ans1 = item_val + knap_sack_recurr(items, n - 1, w - item_wt);

        // exclude the item
        int ans2 = knap_sack_recurr(items, n - 1, w);
        return max(ans1, ans2);
    }
    else
        return knap_sack_recurr(items, n - 1, w);
}


int main()
{
    Onii_chan;
    vector<pair<int , int>> items = {{15, 2} , {14 , 5} , {10 , 1} , {45 , 3} , {30 , 4}};
    int n = 5, w = 7;
    cout << knap_sack_recurr(items , n , w) << uwu;
    return 0;
}