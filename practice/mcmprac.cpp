#include<bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

int mcm(vector<int> arr, vector<vector<int>> &bracket)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;
    for (int len = 2; len < n; len++)
    {
        for (int i = 1; i <= n - len; i++)
        {
            int j = len + i - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int cost1 = dp[i][k];
                int cost2 = dp[k + 1][j];
                int total_cost = cost1 + cost2 + arr[i - 1] * arr[k] * arr[j];
                if(dp[i][j] > total_cost)
                {
                    dp[i][j] = total_cost;
                    bracket[i][j] = k;
                }
            }
        }
    }
    return dp[1][n - 1];
}


void print_bracket(vector<vector<int>> &bracket , int i , int j)
{
    if(i ==j)
    {
        cout << "A" << i;
        return;
    }
    cout << "(";
    print_bracket(bracket, i, bracket[i][j]);
    print_bracket(bracket, bracket[i][j] + 1, j);
    cout << ")";
}



int main()
{
    Onii_chan;
    vector<int> arr = {30 , 35 , 15 , 5 , 10 , 20 , 25};
    int n = arr.size();
    vector<vector<int>> bracket(n, vector<int>(n, 0));
    cout << mcm(arr, bracket);
    print_bracket(bracket, 1, n - 1);
    return 0;
}