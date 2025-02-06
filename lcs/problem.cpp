#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

int min_square(int n)
{
    static int count = 1;
    int m = sqrt(n);

    if(m * m == n)
        return count;
    else 
    {
        count++;
        return min_square(n - m * m);
    }
}

int min_square(int n , vector<int> &dp)
{
    if(n == 0)
        return 0;
    if(dp[n] != 0)
        return dp[n];
    int ans = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + min_square(n - i * i, dp));
    }

    return dp[n] = ans;
}


int main()
{
    Onii_chan;
    int n;
    cin >> n;
    vector<int> dp(n + 1 , 0);
    cout << min_square(n, dp) << uwu;
    return 0;
}