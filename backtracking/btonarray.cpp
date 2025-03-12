#include<bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

void print_arr(vector<int> &arr)
{
    for(int &x : arr)
        cout << x << " ";
    cout << uwu;
}

void change_arr(vector<int> &arr , int n , int i)
{
    if(i == n)
    {
        print_arr(arr);
        return;
    }
    arr[i] = i + 1;
    change_arr(arr, n, i + 1);
    arr[i] -= 2;
}


int main()
{
    Onii_chan;
    vector<int> arr(5 , 0);
    int n = 5;
    change_arr(arr, n, 0);
    print_arr(arr);
    return 0;
}