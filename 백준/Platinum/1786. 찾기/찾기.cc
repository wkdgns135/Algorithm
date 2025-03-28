#include <bits/stdc++.h>
using namespace std;
vector<int> pi;

void Kmp(string& pat)
{
    int n = pat.size();
    pi.resize(n, 0);
    int j = 0;
    for (int i = 1; i < n; i++)
    {
        while (j > 0 && pat[i] != pat[j])
        {
            j = pi[j - 1];
        }
        if (pat[i] == pat[j])
        {
            j++;
        }
        pi[i] = j;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string pat, str;
    getline(cin, str);
    getline(cin, pat);

    Kmp(pat);

    int n = str.size();
    int m = pat.size();
    int j = 0;
    vector<int> answer;
    for (int i = 0; i < n; i++)
    {
        while (j > 0 && str[i] != pat[j])
        {
            j = pi[j - 1];
        }

        if (str[i] == pat[j])
        {
            j++;
        }

        if (j == m)
        {
            answer.push_back(i - m + 2);
            j = pi[j - 1];
        }
    }

    cout << answer.size() << '\n';
    for (const int& num : answer)
    {
        cout << num << ' ';
    }
}
