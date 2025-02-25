#include<bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

int mcm_tabul(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;
    for (int len = 2; len < n; len++)
    {
        for (int i = 1; i <= n - len; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int cost1 = dp[i][k];
                int cost2 = dp[k + 1][j];
                int curr_cost = cost1 + cost2 + arr[i - 1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], curr_cost);
            }
        }
    }
    return dp[1][n - 1];
}

int main()
{
    Onii_chan;
    vector<int> arr = {1, 2, 3, 4, 3};
    cout << mcm_tabul(arr) << uwu;
    return 0;
}