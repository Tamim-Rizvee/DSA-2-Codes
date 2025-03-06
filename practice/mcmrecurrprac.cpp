#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

int mc_recurr(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int cost1 = mc_recurr(arr, i, k, dp);
        int cost2 = mc_recurr(arr, k + 1, j , dp);
        int curr_cost = cost1 + cost2 + arr[i - 1] * arr[k] * arr[j];
        ans = min(ans, curr_cost);
    }
    return dp[i][j] = ans;
}

int main()
{
    Onii_chan;
    vector<int> arr = {1, 2, 3, 4, 3};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << mc_recurr(arr, 1, arr.size() - 1, dp) << uwu;
    return 0;
}