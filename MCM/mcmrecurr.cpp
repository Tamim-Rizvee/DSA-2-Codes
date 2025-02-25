#include<bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

int mcmRecurr(vector<int> &arr , int i , int j)
{
    if(i == j)
        return 0;
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int cost1 = mcmRecurr(arr, i, k);
        int cost2 = mcmRecurr(arr, k + 1, j);
        int curr_cost = cost1 + cost2 + arr[i - 1] * arr[k] * arr[j];
        ans = min(ans , curr_cost);
    }
    return ans;
}


int main()
{
    Onii_chan;
    vector<int> arr ={ 1, 2, 3, 4, 3};
    int n = arr.size();
    cout << mcmRecurr(arr, 1, n - 1) << uwu;
    return 0;
}