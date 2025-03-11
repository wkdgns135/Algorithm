#include <bits/stdc++.h>
using namespace std;

template <typename Iterator>
bool Check(Iterator start, Iterator end)
{
    for (; start != end; ++start)
    {
        if (*start) return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int h, w; cin >> h >> w;
    vector<vector<bool>> v(h, vector<bool>(w));
    for (int i = 0; i < w; i++)
    {
        int input; cin >> input;
        for (int j = 0; j < input; j++)
        {
            v[j][i] = true;
        }
    }
    int answer = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (v[i][j] == true)continue;
            if (Check(v[i].begin() + j, v[i].end()) && Check(v[i].rbegin() + (w - j), v[i].rend()))answer++;
        }
    }
    cout << answer;
}
