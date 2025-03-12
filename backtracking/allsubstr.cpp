#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

void substrings(string str, string ans = "")
{
    int n = str.size();
    if (n == 0)
    {
        if (ans.empty())
            cout << "null" << uwu;
        else
            cout << ans << uwu;
        return;
    }
    substrings(str.substr(1, n - 1), ans + str[0]);
    substrings(str.substr(1, n - 1), ans);
}

int main()
{
    Onii_chan;
    string str = "abc";
    substrings(str);
    return 0;
}