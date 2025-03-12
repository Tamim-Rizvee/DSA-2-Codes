#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

int partition(vector<int> &arr, int si, int ei)
{
    int pivot = arr[si];
    int i = si;
    for (int j = si + 1; j <= ei; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i], arr[si]);
    return i;
}

void quick_sort(vector<int> &arr, int si, int ei)
{
    if (si >= ei)
        return;
    int pivot = partition(arr, si, ei);
    quick_sort(arr, si, pivot - 1);
    quick_sort(arr, pivot + 1, ei);
}

int main()
{
    Onii_chan;
    vector<int> arr = {2, 3, 4, 1, 0};
    quick_sort(arr, 0, arr.size() - 1);
    for (auto x : arr)
        cout << x << " ";
    return 0;
}