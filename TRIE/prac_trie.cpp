#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

class Node
{
public:
    bool EoW;
    Node *children[26];
    Node()
    {
        EoW = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie
{
    bool delete_helper(Node *curr, string s, int curr_size);
    bool is_leaf(Node *curr);
    bool is_junction(Node *curr);
    void remove_edge(Node *curr, int index);

public:
    Node *root;

    Trie()
    {
        root = new Node();
    }
    void insert(string s);
    bool search(string s);
    void print_trie(Node *curr, string s);
    bool erase(string s);
};

void Trie::insert(string s)
{
    Node *curr = root;
    for (int i = 0; i < s.size(); i++)
    {
        int idx = s[i] - 'a';
        if (curr->children[idx] == NULL)
        {
            curr->children[idx] = new Node;
        }
        curr = curr->children[idx];
    }
    curr->EoW = true;
}

void Trie::print_trie(Node *curr, string s = "")
{
    if (curr->EoW)
        cout << s << uwu;
    for (int i = 0; i < 26; i++)
    {
        if (curr->children[i] == NULL)
            continue;
        char c = i + 'a';
        print_trie(curr->children[i], s + c);
    }
}

bool Trie::search(string s)
{
    Node *curr = root;
    for (int i = 0; i < s.size(); i++)
    {
        int idx = s[i] - 'a';
        if (curr->children[idx] == NULL)
            return false;
        curr = curr->children[idx];
    }
    return curr->EoW;
}

bool Trie::delete_helper(Node *curr , string s, int curr_size)
{
    if(curr == NULL)
        return false;
    if(curr_size == s.size())
    {
        if(!curr->EoW)
            return false;
        if(!is_leaf(curr))
        {
            curr->EoW = false;
            return false;
        }
        return true;
    }
    int idx = s[curr_size] - 'a';
    bool needed_to_remove_edge = delete_helper(curr->children[idx], s, curr_size + 1);
    if(needed_to_remove_edge)
        remove_edge(curr, idx);
    if(is_junction(curr))
        return false;
    return needed_to_remove_edge;
}

void Trie::remove_edge(Node *curr , int index)
{
    Node *del = curr->children[index];
    curr->children[index] = NULL;
    delete del;
}

bool Trie::is_leaf(Node *curr)
{
    for (int i = 0; i < 26; i++)
    {
        if(curr->children[i] != NULL)
            return false;
    }
    return true;
}

bool Trie::is_junction(Node *curr)
{
    if(curr->EoW || !is_leaf(curr))
        return true;
    return false;
}

bool Trie::erase(string s)
{
    return delete_helper(root, s, 0);
}

int main()
{
    Onii_chan;
    Trie t;
    t.insert("mist");
    t.insert("bubt");
    t.insert("buet");
    t.insert("mit");
    t.insert("exam");
    t.insert("exit");
    t.insert("exi");
    t.insert("apple");
    t.print_trie(t.root);
    cout << "==========" << uwu;
    t.erase("apple");
    t.erase("exi");
    t.erase("buet");
    t.print_trie(t.root);
    return 0;
}