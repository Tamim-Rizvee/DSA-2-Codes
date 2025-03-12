#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

//to fimd the length of the longest common subsequence
int lcs(string s1, string s2, vector<vector<int>> &dp)
{
    int n = s1.size(), m = s2.size();
    if (n == 0 || m == 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];
    if (s1[n - 1] == s2[m - 1])
        dp[n][m] = 1 + lcs(s1.substr(0, n - 1), s2.substr(0, m - 1), dp);
    else
    {
        int ans1 = lcs(s1.substr(0, n - 1), s2, dp);
        int ans2 = lcs(s1, s2.substr(0, m - 1), dp);
        dp[n][m] = max(ans1, ans2);
    }
    return dp[n][m];
}

//to find the longest common subsequence in reverse
string lcs2(string s1, string s2, vector<vector<string>> &dp)
{
    int n = s1.size(), m = s2.size();
    if (n == 0 || m == 0)
        return "";

    if (dp[n][m] != "-1")
    {
        return dp[n][m];
    }

    if (s1[n - 1] == s2[m - 1])
        dp[n][m] = s1[n - 1] + lcs2(s1.substr(0, n - 1), s2.substr(0, m - 1), dp);
    else
    {
        string name1 = lcs2(s1.substr(0, n - 1), s2, dp);
        string name2 = lcs2(s1, s2.substr(0, m - 1), dp);
        dp[n][m] =  ((name1.size() > name2.size()) ? name1 : name2);
    }
    return dp[n][m];
}

int main()
{
    Onii_chan;
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    vector<vector<string>> dp2(n + 1, vector<string>(m + 1, "-1"));
    cout << lcs(s1, s2, dp) << uwu;
    string ans = lcs2(s1, s2, dp2);
    reverse(ans.begin(), ans.end());
    cout << ans << uwu;
    return 0;
}

/*
abcdge
abedg

*/