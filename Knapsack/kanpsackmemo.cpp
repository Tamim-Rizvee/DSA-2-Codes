#include<bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

int knap_sack_recurr(vector<pair<int , int>> items , int n , int w, vector<vector<int>> &dp)
{
    if(n == 0 || w == 0)
        return 0;
    int item_wt = items[n - 1].second , item_val = items[n - 1].first;
    if(dp[n][w] != -1) return dp[n][w];
    if(item_wt <= w)
    {
        // include the item
        int ans1 = item_val + knap_sack_recurr(items, n - 1, w - item_wt, dp);

        // exclude the item
        int ans2 = knap_sack_recurr(items, n - 1, w, dp);
        dp[n][w] = max(ans1, ans2);
    }
    else
        dp[n][w] =  knap_sack_recurr(items, n - 1, w, dp);

    return dp[n][w];
}


int main()
{
    Onii_chan;
    vector<pair<int , int>> items = {{15, 2} , {14 , 5} , {10 , 1} , {45 , 3} , {30 , 4}};
    int n = 5, w = 7;
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, - 1));
    cout << knap_sack_recurr(items , n , w, dp) << uwu;
    return 0;
}