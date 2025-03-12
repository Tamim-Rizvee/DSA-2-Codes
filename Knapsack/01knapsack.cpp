#include<bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

int knapsack(vector<int> &weight , vector<int> &value , int w , int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w ; j++)
        {
            if(weight[i - 1] <= j)
            {
                dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
            }
            else 
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][w];
}


int main()
{
    Onii_chan;
    int n = 3, w = 50;
    vector<int> value = {60 , 100 , 120};
    vector<int> weight = {10 , 20 , 30};

    cout << knapsack(weight , value , w, n) << uwu;
    return 0;
}