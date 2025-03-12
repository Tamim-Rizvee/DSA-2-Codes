#include<bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;


int partition(vector<int> &arr , int si , int ei)
{
    int i = si - 1;
    for (int j = si; j < ei; j++)
    {
        if(arr[j] <= arr[ei]) i++ , swap(arr[i], arr[j]);
    }
    i++;
    swap(arr[i], arr[ei]);
    return i;
}

void quick_sort(vector<int> &arr , int si , int ei)
{
    if(si >= ei)
        return;
    int pivot = partition(arr, si, ei);
    quick_sort(arr, si, pivot - 1);
    quick_sort(arr, pivot + 1, ei);
}

int main()
{
    Onii_chan;
    vector<int> v = {1, 5, 3, 2, 4, 6, 8, 7, 9, 0};
    quick_sort(v, 0, v.size() - 1);
    for(auto &x : v)
        cout << x << " ";
    return 0;
}