#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

class Prioroty_queue
{
    vector<int> max_heap;
    void heapify_up(int i);
    void heapify_down(int i);

public:
    void Push(int value);
    int Top();
    void Pop();
    bool Empty();
};

void Prioroty_queue::heapify_up(int i)
{
    int parent = (i - 1) / 2;
    if (i == 0 || max_heap[parent] >= max_heap[i])
        return;
    if (max_heap[parent] < max_heap[i])
    {
        swap(max_heap[parent], max_heap[i]);
        heapify_up(parent);
    }
}

void Prioroty_queue::heapify_down(int i)
{
    int left = 2 * i + 1, right = 2 * i + 2, largest = i;
    if(left < max_heap.size() && max_heap[left] > max_heap[largest])
        largest = left;
    
    if(right < max_heap.size() && max_heap[right] > max_heap[largest])
        largest = right;
    if(largest != i)
    {
        swap(max_heap[i], max_heap[largest]);
        heapify_down(largest);
    }
}

void Prioroty_queue::Push(int value)
{
    max_heap.push_back(value);
    heapify_up(max_heap.size() - 1);
}

int Prioroty_queue::Top()
{
    return max_heap[0];
}

void Prioroty_queue::Pop()
{
    swap(max_heap[0], max_heap[max_heap.size() - 1]);
    max_heap.pop_back();
    heapify_down(0);
}

bool Prioroty_queue::Empty()
{
    if(max_heap.size() == 0)
        return true;
    return false;
}

int main()
{
    Onii_chan;
    vector<int> arr = {0, 4, 5, 6, 3};
    Prioroty_queue pq;
    for (int i = 0; i < arr.size(); i++)
    {
        pq.Push(arr[i]);
    }
    while (!pq.Empty())
    {
        cout << pq.Top() << " ";
        pq.Pop();
    }
    return 0;
}
