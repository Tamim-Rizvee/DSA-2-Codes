#include<bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

class Node 
{
public:
    Node *children[26];
    bool end;
    Node()
    {
        end = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }

    void add(string s)
    {
        Node *curr = root;
        for (int i = 0; i < s.size(); i++)
        {
            int index = s[i] - 'a';
            if (curr->children[index] == NULL)
                curr->children[index] = new Node();
            curr = curr->children[index];
        }
        curr->end = true;
    }

    bool search(string s)
    {
        Node *curr = root;
        for (int i = 0; i < s.size(); i++)
        {
            int index = s[i] - 'a';
            if (curr->children[index] == NULL)
                return false;
            curr = curr->children[index];
        }
        return curr->end;
    }

    void print(Node *curr, string s = "")
    {
        if (curr->end)
            cout << s << uwu;
        for (int i = 0; i < 26; i++)
        {
            if (curr->children[i] != NULL)
                print(curr->children[i], s + char(i + 'a'));
        }
    }
};

int main()
{
    Onii_chan;
    return 0;
}