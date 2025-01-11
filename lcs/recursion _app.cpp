#include<bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

int lcs(string s1 , string s2 , int n , int m)
{
    if(n == 0 || m == 0)
        return 0;
    if (s1[n - 1]==s2[m - 1])
        return 1 + lcs(s1, s2, n - 1, m - 1);
    return max(lcs(s1, s2, n - 1, m), lcs(s1, s2, n, m - 1));
}

string lcs2(string s1 , string s2 , int n , int m)
{
    if(n == 0 || m == 0)
        return "";
    if(s1[n - 1] == s2[m -1])
        return s1[n - 1] + lcs2(s1, s2, n - 1, m - 1);
    string name1 = lcs2(s1, s2, n - 1, m);
    string name2 = lcs2(s1, s2, n, m - 1);
    return ((name1.size() > name2.size()) ? name1 : name2);
}

int main()
{
    Onii_chan;
    string s1 , s2;
    cin >> s1 >> s2;
    cout << lcs(s1 , s2 , s1.size() , s2.size()) << uwu;
    string ans = lcs2(s1, s2, s1.size(), s2.size());
    reverse(ans.begin(), ans.end());
    cout << ans << uwu;
    return 0;
}

/*
abcdge
abedg

*/