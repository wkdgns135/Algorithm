#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int y, m;
    cin >> y >> m;

    int total_months = 0;

    if (y == 0)
    {
        total_months = m * 15;
    }
    else if (y == 1)
    {
        total_months = 15 * 12 + m * 9;
    }
    else
    {
        total_months = (15 + 9) * 12;
        total_months += (y - 2) * 4 * 12;
        total_months += m * 4;
    }

    int human_years = total_months / 12;
    int human_months = total_months % 12;

    cout << human_years << " " << human_months << "\n";
}
