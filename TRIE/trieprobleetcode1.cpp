#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int count;
    bool EoW;
    Node *children[26];
    Node()
    {
        EoW = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

int help(Node *curr)
{
    int count = 0, idx;
    for (int i = 0; i < 26; i++)
    {
        if (curr->children[i] != NULL)
        {
            count++;
            idx = i;
        }
    }
    if (count == 1)
        return idx;
    else
        return -1;
}

class Trie
{
public:
    Node *root;
    Trie() { root = new Node(); }
    void insert(string s)
    {
        Node *curr = root;
        for (int i = 0; i < s.size(); i++)
        {
            int idx = s[i] - 'a';
            if (curr->children[idx] == NULL)
            {
                curr->children[idx] = new Node();
            }
            else
                curr->children[idx]->count++;
            curr = curr->children[idx];
        }
        curr->EoW = true;
    }
    string prefix(Node *curr, string s = "")
    {
        int idx = help(curr);
        if (idx == -1)
            return s;
        char a = idx + 'a';
        return prefix(curr->children[idx], s + a);
    }
};

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        Trie t;
        for (auto &s : strs)
        {
            if (s.empty())
                return "";
            t.insert(s);
        }
        return t.prefix(t.root);
    }
};
