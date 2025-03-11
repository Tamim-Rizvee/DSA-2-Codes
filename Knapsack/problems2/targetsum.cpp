#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

vector<int> target_sum(vector<int> nums, int target, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (nums[i - 1] <= j)
            {
                dp[i][j] = max(nums[i - 1] + dp[i - 1][j - nums[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int i = n, j = target;
    vector<int> res;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] == dp[i - 1][j])
        {
            i--;
        }
        else
        {
            res.push_back(nums[i - 1]);
            j -= nums[i - 1];
            i--;
        }
    }
    return res;
}

int main()
{
    Onii_chan;
    vector<int> nums = {4, 2, 7, 1, 3};
    int target = 10, n = 5;
    vector<int> res = target_sum(nums, target, n);
    if (res.empty())
        cout << "No such subset found" << uwu;
    else
    {
        for (auto i : res)
            cout << i << " ";
    }
    return 0;
}