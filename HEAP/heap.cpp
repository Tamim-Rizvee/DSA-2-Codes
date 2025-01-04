#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

int time_ = 0;

class customer
{
public:
    string name;
    int bill, timestamp;
    customer() {}
    customer(string name, int bill, int time) : name(name), bill(bill), timestamp(time) {}
};

class Priority_queue
{
    customer c_arr[100];
    int size;
    void swap_(customer &a, customer &b);
    void heapify_up(int i);
    void heapify_down(int i);

public:
    Priority_queue() : size(0) {}
    void insert(customer &c);
    void extract_max();
    void display()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << c_arr[i].name << " Amount: " << c_arr[i].bill << " Timestamp: " << c_arr[i].timestamp << uwu;
        }
    }
};

using p = Priority_queue;

void p::insert(customer &c)
{
    size++;
    c_arr[size] = c;
    heapify_up(size);
}

void p::swap_(customer &a, customer &b)
{
    customer temp = a;
    a = b;
    b = temp;
}

void p::heapify_down(int i)
{
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;
    if (left <= size && c_arr[left].bill > c_arr[largest].bill)
        largest = left;
    if (right <= size && c_arr[right].bill > c_arr[largest].bill)
        largest = right;

    if (largest != i)
    {
        swap_(c_arr[i], c_arr[largest]);
        heapify_down(largest);
    }
}

void p::heapify_up(int i)
{
    if (i == 1)
        return;
    if (c_arr[i].bill > c_arr[i / 2].bill)
    {
        swap_(c_arr[i], c_arr[i / 2]);
        heapify_up(i / 2);
    }
}

void p::extract_max()
{
    if (size == 0)
        cout << "The queue is empty" << uwu;
    customer max_ = c_arr[1];
    swap_(c_arr[1], c_arr[size]);
    size--;
    heapify_down(1);
    cout << max_.bill << uwu;
}

int main()
{
    string name;
    int bill;
    Priority_queue q;
    while (true)
    {
        time_++;
        cout << "Customer Number : " << time_ << uwu;
        cout << "Enter customer name: ";
        cin >> name;
        if (name == "Q")
            break;
        cout << "Enter Bill: ";
        cin >> bill;
        customer c(name, bill, time_);
        q.insert(c);
    }
    q.display();
    return 0;
}
