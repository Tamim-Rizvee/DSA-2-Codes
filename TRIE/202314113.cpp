#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

class Node
{
public:
    bool EoW;
    int count;
    Node *children[26];
    Node()
    {
        EoW = false;
        count = 0;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie
{
public:
    Node *root;
    string best_dna;
    int max_dna_count;
    Trie()
    {
        best_dna = "";
        root = new Node();
        max_dna_count = -1;
    }
    void insert(string s);
    void find_best_dna(Node *curr, string s);
    void print_best_dna();
};

void Trie::insert(string s)
{
    Node *curr = root;
    for (int i = 0; i < (int)s.size(); i++)
    {
        int idx = s[i] - 'A';
        if (curr->children[idx] == NULL)
        {
            curr->children[idx] = new Node();
            curr->children[idx]->count = 1;
        }
        else
            curr->children[idx]->count++;
        max_dna_count = max(max_dna_count, curr->children[idx]->count);
        curr = curr->children[idx];
    }
    curr->EoW = true;
}

void Trie::find_best_dna(Node *curr, string s = "")
{
    if (best_dna.size() < s.size())
        best_dna = s;
    if (curr == NULL)
        return;
    for (int i = 0; i < 26; i++)
    {
        if (curr->children[i] != NULL && curr->children[i]->count == max_dna_count)
        {
            char c = i + 'A';
            find_best_dna(curr->children[i], s + c);
        }
    }
}

void Trie::print_best_dna()
{
    find_best_dna(root);
    cout << best_dna << uwu;
}

int main()
{
    Onii_chan;
    int t;
    cin >> t;
    Trie trie;
    while (t--)
    {
        int choice;
        string dna;
        cin >> choice;
        if (choice == 1)
        {
            cin >> dna;
            trie.insert(dna);
        }
        else if (choice == 2)
            trie.print_best_dna();
        else
            cout << "Invalid choice" << uwu;
    }
    return 0;
}