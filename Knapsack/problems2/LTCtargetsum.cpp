#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;
class Solution
{
public:
    int offset = 1000; // to handle negative values;

    int solve(vector<int> nums, int target, int ind, vector<vector<int>> &dp)
    {
        if (ind >= nums.size())
        {
            return target == 0 ? 1 : 0;
        }

        if (dp[ind][target + offset] != -1)
        {
            return dp[ind][target + offset];
        }

        int ans = 0;
        ans += solve(nums, target - nums[ind], ind + 1, dp);
        ans += solve(nums, target + nums[ind], ind + 1, dp);

        return dp[ind][target + offset] = ans;
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = 21, m = 3002;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(nums, target, 0, dp);
    }
};

int main()
{
    Onii_chan;
    return 0;
}