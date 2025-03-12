#include<bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;


void solve()
{
    string a , b , c;
    cin >> a >> b >> c;
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if(i<n) dp[i+1][j]=min(dp[i+1][j], dp[i][j]+(a[i]!=c[i+j]));
			if(j<m) dp[i][j+1]=min(dp[i][j+1], dp[i][j]+(b[j]!=c[i+j]));
        }
    }
    cout << dp[n][m] << uwu;
}


int main()
{
    Onii_chan;
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}