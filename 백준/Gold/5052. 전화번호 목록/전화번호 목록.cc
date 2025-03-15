#include <bits/stdc++.h>
using namespace std;

class Trie
{
    bool bIsFinish = 0;
    vector<Trie*> next;
    
public:
    Trie()
    {
        next.resize(10, nullptr);
    }
    void Insert(const string::iterator iter, const string &str)
    {
        if (iter == str.end())
        {
            bIsFinish = true;
        }
        else{
            int node = *iter - '0';
            if (next[node] == nullptr)
            {
                next[node] = new Trie();
            }
            next[node]->Insert(iter + 1, str);
        }
    }
    bool Find(const string::iterator iter, const string& str)
    {
        if (iter == str.end())return false;
        if (bIsFinish)return true;
        int node = *iter - '0';
        if (next[node] == nullptr)return false;
        return next[node]->Find(iter + 1, str);
    }
};

bool TryTrie()
{
    Trie root;
    int n; cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), [](const string& a, const string& b) { return a.size() < b.size(); });

    for (string &str : v)
    {
        if (root.Find(str.begin(), str))
        {
            return true;
        }
        root.Insert(str.begin(), str);
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;

    while (t--)
    {
        if (TryTrie()) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
}