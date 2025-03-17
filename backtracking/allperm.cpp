#include<bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

void print_perm(string name , string ans = "")
{
    if(name.empty())
    {
        cout << ans << uwu;
        return;
    }
    for (int i = 0; i <(int) name.size(); i++)
    {
        print_perm(name.substr(0, i) + name.substr(i + 1), ans + name[i]);
    }
}


int main()
{
    Onii_chan;
    string name = "abc";
    print_perm(name);
    return 0;
}