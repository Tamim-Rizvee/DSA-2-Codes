#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

void heapify(int i, vector<int> &arr, int n)
{
    int left = 2 * i + 1, right = 2 * i + 2, largest = i;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(largest, arr, n);
    }
}

void heap_sort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(i, arr, n);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(0, arr, i); // i = n - 1
    }
}

int main()
{
    //Onii_chan;
    vector<int> arr = {5, 2, 8, 1, 9, 3, 7};
    heap_sort(arr);
    for(auto &x : arr)
        cout << x << uwu;
    return 0;
}