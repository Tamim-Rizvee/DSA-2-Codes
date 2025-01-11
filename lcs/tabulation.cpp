#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

int lcsTab(string str1, string str2)
{
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

string lcsTab2(string str1, string str2)
{
    int n = str1.size(), m = str2.size();
    vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = str1[i - 1] + dp[i - 1][j - 1];
            else 
                dp[i][j] = (dp[i - 1][j].size() > dp[i][j -1].size() ? dp[i - 1][j] : dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int main()
{
    Onii_chan;
    string str1 = "abcdge";
    string str2 = "abedg";
    cout << lcsTab(str1, str2) << uwu;
    string ans = lcsTab2(str1, str2);
    reverse(ans.begin(), ans.end());
    cout << ans << uwu;
    return 0;
}