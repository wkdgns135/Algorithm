#include<bits/stdc++.h>
using namespace std;

bool is_all_equal(const vector<int>& candies)
{
    for (int i = 1; i < candies.size(); i++)
        if (candies[i] != candies[0]) return false;
    return true;
}

int distribute_candies(vector<int>& candies)
{
    int n = candies.size();
    int rounds = 0;

    while (!is_all_equal(candies))
    {
        vector<int> half(n);
        for (int i = 0; i < n; i++)
            half[i] = candies[i] / 2;
        for (int i = 0; i < n; i++)
            candies[i] = half[i] + half[(i - 1 + n) % n];
        for (int i = 0; i < n; i++)
            if (candies[i] % 2 == 1) candies[i]++;
        rounds++;
    }

    return rounds;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] % 2 == 1)v[i]++;
        }
        cout << distribute_candies(v) << '\n';
	}
}