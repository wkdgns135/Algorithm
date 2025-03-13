#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    unordered_map<int, vector<pair<int, bool>>> dict;
    vector<int> v(n);
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        dict[v[i]].push_back({i, true});
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int key = v[i] + v[j];
            if (dict.contains(key))
            {
                auto& vec = dict[key];

                vector<pair<int, bool>> new_vec;

                for (pair<int, bool>& p : vec)
                {
                    if (p.second && p.first != i && p.first != j)
                    {
                        p.second = false;
                        answer++;
                    }
                    if (p.second) new_vec.push_back(p);
                }

                vec = move(new_vec);
            }
        }
    }

    cout << answer;
}
