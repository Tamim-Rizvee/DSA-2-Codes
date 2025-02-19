#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

string find_lcs(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string ans = "";
    int i = n, j = m;
    while(i> 0 && j > 0)
    {
        if(s1[i - 1] == s2[j - 1])
        {
            ans += s1[i - 1];
            i--, j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    return reverse(ans.begin(), ans.end()), ans;
}

int main()
{
    Onii_chan;
    string a, b;
    cin >> a >> b;
    cout << find_lcs(a, b) << uwu;
    return 0;
}