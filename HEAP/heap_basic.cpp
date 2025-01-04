#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

class Priority_queue
{
    int max_heap[100];
    int heap_size;
    void heapify_up(int index);
    void heapify_down(int index);

public:
    Priority_queue() : heap_size(0) {}
    void push(int value);
    int Top();
    void Pop();
    bool empty();
};

void Priority_queue::heapify_up(int index)
{
    if (index == 1 || max_heap[index / 2] > max_heap[index])
        return;
    if (max_heap[index / 2] < max_heap[index])
        swap(max_heap[index / 2], max_heap[index]);
    heapify_up(index / 2);
}

void Priority_queue::heapify_down(int index)
{
    if(heap_size == 0)
        return;
    int left = 2 * index, right = 2 * index + 1, largest = index;
    if (left <= heap_size && max_heap[left] > max_heap[largest])
        largest = left;
    if (right <= heap_size && max_heap[right] > max_heap[largest])
        largest = right;
    if (largest != index)
    {
        swap(max_heap[index], max_heap[largest]);
        heapify_down(largest);
    }
}

void Priority_queue::push(int value)
{
    heap_size++;
    max_heap[heap_size] = value;
    heapify_up(heap_size);
}

void Priority_queue::Pop()
{
    if (heap_size == 0) 
    {
        cout << "Priority queue is empty" << uwu;
        return;
    }
    swap(max_heap[1], max_heap[heap_size]);
    heap_size--;
    heapify_down(1);
}

bool Priority_queue::empty()
{
    return heap_size == 0;
}


int Priority_queue::Top()
{
    return max_heap[1];
}

int main()
{
    Onii_chan;
    Priority_queue pq;
    vector<int> v = {5, 2, 8, 1, 9};
    for(auto &x : v)
        pq.push(x);
    while(!pq.empty())
    {
        cout << pq.Top() << uwu;
        pq.Pop();
    }
    return 0;
}
