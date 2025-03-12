#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

int time_count = 0;

class customer
{
public:
    string name;
    int bill, time;
    customer() {}
    customer(string name, int bill, int time) : name(name), bill(bill), time(time) {}
    bool operator>(const customer &c)
    {
        if (this->bill == c.bill)
            return this->time < c.time;
        else
            return this->bill > c.bill;
    }
    bool operator<(const customer &c)
    {
        if (this->bill == c.bill)
            return this->time < c.time;
        else
            return this->bill < c.bill;
    }
};

class Priority_queue
{
    vector<customer> max_heap;
    void heapify_up(int i);
    void heapify_down(int i);

public:
    void Push(customer &cus);
    customer peek();
    void Pop();
    bool empty();
    bool update(customer &c);
    void delete_at(int i);
    int find_min();
    void process_bill();
};

void Priority_queue::heapify_up(int i)
{
    if (i <= 0 || max_heap[i / 2 + 1] > max_heap[i])
        return;
    if (max_heap[(i - 1) / 2] < max_heap[i])
        swap(max_heap[(i - 1) / 2], max_heap[i]);
    heapify_up((i - 1) / 2);
}

void Priority_queue::heapify_down(int i)
{
    int left = 2 * i + 1, right = 2 * i + 2, largest = i;
    if (left < max_heap.size() && max_heap[left] > max_heap[largest])
        largest = left;
    if (right < max_heap.size() && max_heap[right] > max_heap[largest])
        largest = right;
    if (largest != i)
    {
        swap(max_heap[i], max_heap[largest]);
        heapify_down(largest);
    }
}

void Priority_queue::Push(customer &cus)
{
    max_heap.push_back(cus);
    heapify_up(max_heap.size() - 1);
}

void Priority_queue::Pop()
{
    swap(max_heap[0], max_heap[max_heap.size() - 1]);
    max_heap.pop_back();
    heapify_down(0);
}

bool Priority_queue::empty()
{
    return max_heap.size() == 0;
}

customer Priority_queue::peek()
{
    return max_heap[0];
}

bool Priority_queue::update(customer &c)
{
    for (int i = 0; i < max_heap.size(); i++)
    {
        if (c.name == max_heap[i].name)
        {
            max_heap[i].bill = c.bill;
            heapify_up(i);
            heapify_down(i);
            return true;
        }
    }
    return false;
}

void Priority_queue::delete_at(int i)
{
    if (i == 0)
    {
        Pop();
        return;
    }
    swap(max_heap[i], max_heap[max_heap.size() - 1]);
    max_heap.pop_back();
    heapify_down(i);
    heapify_up(i);
}

int Priority_queue::find_min()
{
    int n = max_heap.size(), index;
    int min_ = 1e9;
    for (int i = n / 2; i < max_heap.size(); i++)
    {
        if (max_heap[i].bill < min_)
        {
            min_ = max_heap[i].bill;
            index = i;
        }
    }
    return index;
}

void Priority_queue::process_bill()
{
    int mod = 202314113 % 9;
    customer c;
    int customer_count = 0;
    while (!empty())
    {
        if (customer_count == mod)
        {
            int i = find_min();
            c = max_heap[i];
            delete_at(i);
            customer_count = 0;
        }
        else
        {
            customer_count++;
            c = peek();
            Pop();
        }
        cout << "Name: " << c.name << " Amount: " << c.bill << " Time: " << c.time << uwu;
    }
}

int main()
{
    // Onii_chan;
    Priority_queue pq;
    string name;
    int bill;
    while (true)
    {
        time_count++;
        cout << "Enter Customer " << time_count << " :" << uwu;
        cout << "Name: ";
        cin >> name;
        if (name == "Q" || name == "q")
            break;
        cout << "Amount: ";
        cin >> bill;
        customer c(name, bill, time_count);
        if (!pq.update(c))
            pq.Push(c);
    }
    pq.process_bill();
    return 0;
}
