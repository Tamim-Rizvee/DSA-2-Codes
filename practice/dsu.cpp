#include<bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;


class Disjoint_set
{
    int node;
    vector<int> parent, rank;
public:
    Disjoint_set(int node){
        this->node = node;
        parent.resize(node);
        rank.resize(node, 0);
        for (int i = 0; i < node; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool Union(int a , int b)
    {
        int parA = find(a);
        int parB = find(b);

        if(parA == parB)
            return false;

        if
    }
};

int main()
{
    Onii_chan;
    return 0;
}

/*

6 9
0 5 10
5 4 20
4 1 40
1 0 30
0 2 50
2 1 30
1 3 70
3 2 10
3 4 10

*/