#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        for (auto x : nums)
            sum += x;

        if (sum % 2 == 1)
        {
            return false;
        }
        sum /= 2;

        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (nums[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
};

int main()
{
    Onii_chan;
    vector<int> nums = {1, 5, 11, 5};
    Solution s;
    cout << boolalpha << s.canPartition(nums) << uwu;
    return 0;
}