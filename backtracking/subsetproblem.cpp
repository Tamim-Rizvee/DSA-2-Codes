#include<bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

void print_arr(vector<int> &arr)
{
    for(int x : arr)
        cout << x << " ";
    cout << uwu;
}

void print_subset(int i , int n ,int target ,vector<int> &arr , vector<int> subset = {})
{
    if(target == 0)
    {
        print_arr(subset);
        return;
    }

    if(i == n)
        return;

    print_subset(i + 1, n, target, arr, subset);
    if(arr[i] <= target )
    {
        subset.push_back(arr[i]);
        print_subset(i + 1, n, target - arr[i], arr, subset);
        subset.pop_back();
    }
}

int main()
{
    Onii_chan;
    vector<int> arr = {1, 2, 1};
    int target = 3;
    int n = arr.size();
    print_subset(0, n,target ,arr);
    return 0;
}