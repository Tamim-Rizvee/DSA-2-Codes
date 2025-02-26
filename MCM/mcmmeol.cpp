#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

int mcmMemo(vector<int> &arr, int i, int j, vector<vector<int>> &dp, vector<vector<int>> &bracket)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int cost1 = mcmMemo(arr, i, k, dp, bracket);
        int cost2 = mcmMemo(arr, k + 1, j, dp, bracket);
        int curr_cost = cost1 + cost2 + arr[i - 1] * arr[k] * arr[j];
        if(curr_cost < ans)
        {
            ans = curr_cost;
            bracket[i][j] = k;
        }
    }
    return dp[i][j] = ans;
}

void print_order(int i , int j , int n , vector<vector<int>> &bracket , char name)
{
    if(i == j)
    {
        cout << name++;
        return;
    }
    cout << "(";
    print_order(i , bracket[i][j] , n , bracket , name);
    print_order(bracket[i][j] + 1 , j , n , bracket , name);
    cout << ")";
}

int main()
{
    Onii_chan;
    vector<int> arr = {1, 2, 3, 4, 3};
    int n = arr.size();
    vector<vector<int>> dp(n , vector<int>(n , -1));
    vector<vector<int>> bracket(n, vector<int>(n, -1)); // to printing the sequcnce
    cout << mcmMemo(arr, 1, n - 1, dp, bracket) << uwu;
    print_order(1 , n - 1 , n , bracket , 'A');
    return 0;
}