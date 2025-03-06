#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;


void find_pattern(vector<vector<int>> &arr , int n )
{
    int count = 1;
    for (int len = 0; len < n; len++)
    {
        for (int i = len; i < n; i++)
        {
            int j = i - len;
            arr[i][j] = count++;
        }
    }
}


int main()
{
    Onii_chan;
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    find_pattern(matrix, n);
    for (auto x : matrix)
    {
        for (auto y: x)
        {
            if (y != 0)
                cout << y << " ";
        }
        cout << uwu;
    }
    return 0;
}