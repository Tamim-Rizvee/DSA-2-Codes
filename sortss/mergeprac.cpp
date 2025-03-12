#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

int ans = 0;

void merge(vector<int> &arr, int si, int ei, int mid)
{
    int n1 = mid - si + 1, n2 = ei - mid;
    vector<int> left(n1 + 1), right(n2 + 1);
    for (int i = 0; i < n1; i++)
        left[i] = arr[si + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + j + 1];
    left[n1] = right[n2] = INT_MAX;
    int i = 0;
    int j = 0;
    int k = si;
    while(i < n1 || j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
            ans+= n1 - i;
        }
        k++;
    }
}

void merge_sort(vector<int> &arr, int si, int ei)
{
    int mid = (si + ei) / 2;
    if (si >= ei)
        return;
    merge_sort(arr, si, mid);
    merge_sort(arr, mid + 1, ei);
    merge(arr, si, ei, mid);
}

int main()
{
    Onii_chan;
    vector<int> v = {4, 3, 2, 1};
    merge_sort(v, 0, v.size() - 1);
    for (auto x : v)
        cout << x << " ";
    cout << uwu;
    cout << ans << uwu;
    return 0;
}