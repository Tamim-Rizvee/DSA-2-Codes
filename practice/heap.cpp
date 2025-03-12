#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

class Priority_queue
{
    vector<int> max_heap;
    void heapyfy_up(int i)
    {
        int parent = (i - 1) / 2;
        if (i == 0 || max_heap[parent] >= max_heap[i])
            return;
        else
        {
            swap(max_heap[parent], max_heap[i]);
            heapyfy_up(parent);
        }
    }

    void heapify_down(int i)
    {
        int left = 2 * i + 1, right = 2 * i + 2, largest = i;
        if(left < max_heap.size() && max_heap[left] > max_heap[largest])
            largest = left;
        else if(right < max_heap.size() && max_heap[right] > max_heap[largest])
            largest = right;
        if(largest != i)
        {
            swap(max_heap[i], max_heap[largest]);
            heapify_down(largest);
        }
    }

public:
    void Push(int x)
    {
        max_heap.push_back(x);
        heapyfy_up(max_heap.size() - 1);
    }

    int Top()
    {
        return max_heap[0];
    }

    void Pop()
    {
        if(max_heap.size() == 0)
            return;
        swap(max_heap[0], max_heap[max_heap.size() - 1]);
        max_heap.pop_back();
        heapify_down(0);
    }

    bool Empty()
    {
        return max_heap.size() == 0;
    }
};

void percolate_down(int index, vector<int> &arr, int n)
{
    int left = 2 * index + 1, right = 2 * index + 2, largest = index;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        percolate_down(largest, arr, n);
    }
}

void heap_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        percolate_down(i, arr, n);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        percolate_down(0, arr, i);
    }
}

int main()
{
    Onii_chan;
    vector<int> arr = {0, 4, 5, 6, 3};
    Priority_queue pq;
    for (int i = 0; i < arr.size(); i++)
    {
        pq.Push(arr[i]);
    }
    while (!pq.Empty())
    {
        cout << pq.Top() << " ";
        pq.Pop();
    }
    cout << uwu;
    vector<int> arr2 = {4, 1, 3, 9, 7};
    heap_sort(arr2);
    for (auto &x : arr2)
        cout << x << " ";
    return 0;
}
