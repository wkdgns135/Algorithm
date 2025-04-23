#include <bits/stdc++.h>
using namespace std;

int offset[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };
vector<vector<bool>> grid(101, vector<bool>(101));

vector<pair<int, int>> Rotation(vector<pair<int, int>> Curve)
{
    auto [ox, oy] = Curve.back();

    for (auto& [x, y] : Curve)
    {
        int dx = x - ox;
        int dy = y - oy;
        tie(x, y) = make_pair(ox - dy, oy + dx);
    }
    reverse(Curve.begin(), Curve.end());
    return Curve;
}

void MakeDrangonCurve(int x, int y, int d, int g)
{
    vector<pair<int, int>> DragonCurve;
    DragonCurve.push_back({ x, y });
    DragonCurve.push_back({ x + offset[d][1], y + offset[d][0] });

    grid[y][x] = true, grid[y + offset[d][0]][x + offset[d][1]] = true;

    while (g--)
    {
        vector<pair<int, int>> RotationCurve = Rotation(DragonCurve);
        auto [offsetX, offsetY] = DragonCurve.back();
        for (int i = 1; i < RotationCurve.size(); i++)
        {
            auto& [x, y] = RotationCurve[i];
            DragonCurve.push_back({ x , y });
            grid[y][x] = true;
        }
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    int answer = 0;
    while (n--)
    {
        int x, y, d, g; cin >> x >> y >> d >> g;
        MakeDrangonCurve(x, y, d, g);
    }
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            answer += grid[i][j] && grid[i][j + 1] && grid[i + 1][j] && grid[i + 1][j + 1];
        }
    }
    cout << answer;
}
