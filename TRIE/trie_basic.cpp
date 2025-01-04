#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

int rel_pos(char i)
{
    return i - 'a';
}

class Node
{
public:
    bool EoW;
    Node *children[26];
    Node()
    {
        EoW = false;
        for (int i = 0; i < 26; i++)
        {
            this->children[i] = NULL;
        }
    }
};

Node *root;

class Trie
{
    bool delete_helper(Node *curr, string word, int curr_size);
    bool is_leaf(Node *curr);
    bool is_junction(Node *curr);
    void remove_edge(Node *curr, int index);

public:
    Trie()
    {
        root = new Node();
    }
    void insert(string s);
    void print_trie(Node *, string);
    bool find(string);
    int delete_word(string word);
};

bool Trie::delete_helper(Node *curr, string word, int curr_size)
{
    if(curr == NULL)
        return false;
    if(curr_size == word.size())
    {
        if(!curr-> EoW)
            return false;
        if(!is_leaf(curr))
        {
            curr->EoW = false;
            return false;
        }
        return true;
    }
    int index = word[curr_size] - 'a';
    bool flag = delete_helper(curr->children[index], word, curr_size + 1);
    if(flag)
        remove_edge(curr, index);
    if(is_junction(curr))
        return false;
    return flag;
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

void Trie::remove_edge(Node *curr, int index)
{
    Node *del = curr->children[index];
    curr->children[index] = NULL;
    delete del;
}

void Trie::insert(string s)
{
    Node *curr = root;
    for (int i = 0; i < (int)s.size(); i++)
    {
        int j = rel_pos(s[i]);
        if (curr->children[j] == NULL)
        {
            curr->children[j] = new Node;
        }
        curr = curr->children[j];
    }
    curr->EoW = true;
}

void Trie::print_trie(Node *curr = root, string s = "")
{
    if (curr->EoW)
    {
        cout << s << uwu;
    }
    for (int i = 0; i < 26; i++)
    {
        if (curr->children[i] == NULL)
            continue;
        char a = i + 'a';
        print_trie(curr->children[i], s + a);
    }
}

bool Trie::find(string s)
{
    Node *curr = root;
    for (int i = 0; i < s.size(); i++)
    {
        int j = rel_pos(s[i]);
        if (curr->children[j] == NULL)
            return false;
        curr = curr->children[j];
    }
    return curr->EoW;
}

int Trie::delete_word(string word)
{
    return delete_helper(root , word , 0);
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
    t.print_trie();
    cout << uwu;
    t.delete_word("buet");
    t.print_trie();
    return 0;
}
