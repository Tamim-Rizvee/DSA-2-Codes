#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

class Node
{
public:
    Node *child[26];
    bool end;
    Node()
    {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
        end = false;
    }
};

class Trie
{
    bool delete_helper(Node *curr, string s, int curr_size);
    bool is_leaf(Node *curr);
    void remove_edge(Node *curr, int indx);

public:
    Node *root;
    Trie()
    {
        root = new Node();
    }
    void add(string s, bool reverse);
    void print(Node *curr, string s);
    bool search(string s);
    void remove(string s);
};

void Trie::add(string s, bool reverse = false)
{
    Node *curr = root;
    for (int i = 0; i < s.size(); i++)
    {
        int indx = s[i] - 'a';
        if (curr->child[indx] == NULL)
        {
            curr->child[indx] = new Node();
        }
        curr = curr->child[indx];
    }
    curr->end = true;
}

void Trie::print(Node *curr, string s = "")
{
    if (curr->end)
        cout << s << uwu;
    for (int i = 0; i < 26; i++)
    {
        if (curr->child[i] != NULL)
        {
            char a = i + 'a';
            print(curr->child[i], s + a);
        }
    }
}

void Trie::remove(string s)
{
    delete_helper(root, s, 0);
}

bool Trie::delete_helper(Node *curr, string s, int curr_size)
{
    if (curr == NULL)
        return false;
    if (s.size() == curr_size)
    {
        if (!curr->end)
            return false;
        if (!is_leaf(curr))
        {
            curr->end = false;
            return false;
        }
        return true;
    }

    int indx = s[curr_size] - 'a';
    bool can_delete = delete_helper(curr->child[indx], s, curr_size + 1);
    if (can_delete)
        remove_edge(curr, indx);

    if (curr->end || !is_leaf(curr))
        return false;
    return can_delete;
}

bool Trie::search(string s)
{
    Node *curr = root;
    for (int i = 0; i < s.size(); i++)
    {
        int indx = s[i] - 'a';
        if (curr->child[indx] == NULL)
            continue;
        curr = curr->child[indx];
    }
    return curr->end;
}

bool Trie::is_leaf(Node *curr)

{
    for (int i = 0; i < 26; i++)
    {
        if (curr->child[i] != NULL)
            return false;
    }
    return true;
}

void Trie::remove_edge(Node *curr, int indx)
{
    Node *del = curr->child[indx];
    curr->child[indx] = NULL;
    delete del;
}

int main()
{
    Onii_chan;
    Trie trie;
    trie.add("alice");
    trie.add("bella");
    trie.add("claire");
    trie.add("diana");
    trie.add("eva");
    trie.add("fiona");
    trie.add("grace");
    trie.print(trie.root);
    cout << boolalpha << trie.search("eva");
    return 0;
}
