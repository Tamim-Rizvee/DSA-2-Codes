#include<bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

int knap_sack_tab(vector<pair<int , int>> items , int n , int w)
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= w; j++)
        {
            int item_wt = items[i - 1].second , item_val = items[i - 1].first;
            if(item_wt <= j)
            {
                int ans1 = item_val + dp[i - 1][j - item_wt]; // item included 
                int ans2 = dp[i - 1][j]; // item excluded
                dp[i][j] = max(ans1, ans2);
            }
            else
                dp[n][w] = dp[i - 1][j]; // ittem excluded
        }
    }
    return dp[n][w];
}

vector<int> knapsack(vector<pair<int , int>> items , int n , int w)
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= w; j++)
        {
            int item_wt = items[i - 1].second , item_val = items[i - 1].first;
            if(item_wt <= j)
            {
                int ans1 = item_val + dp[i - 1][j - item_wt]; // item included 
                int ans2 = dp[i - 1][j]; // item excluded
                dp[i][j] = max(ans1, ans2);
            }
            else
                dp[n][w] = dp[i - 1][j]; // ittem excluded
        }
    }
    int i = n, j = w;
    vector<int> res;
    while(i > 0 && j > 0)
    {
        if(dp[i][j] == dp[i - 1][j])
        {
            i--;
        }
        else
        {
            res.push_back(items[i - 1].first);
            j -= items[i - 1].second;
            i--;
        }
    }
    return res;
}


int main()
{
    Onii_chan;
    vector<pair<int , int>> items = {{15, 2} , {14 , 5} , {10 , 1} , {45 , 3} , {30 , 4}};
    int n = 5, w = 7;
    cout << knap_sack_tab(items , n , w) << uwu;

    vector<int> res = knapsack(items , n , w);
    for(auto i : res)
        cout << i << " ";
    return 0;
}