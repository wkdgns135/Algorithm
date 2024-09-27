#include <bits/stdc++.h>
using namespace std;

class Tetromino {
public :
    vector<vector<int>> shape;
    Tetromino(vector<vector<int>> &shape) {
        this->shape = shape;
    }
    void Rotation() {
        double radian = 3.141592 / 2;
        double sinTheta = sin(radian), cosTheta = cos(radian);
        for (auto &pos : shape) {
            int x = round(pos[1] * cosTheta - pos[0] * sinTheta);
            int y = round(pos[1] * sinTheta + pos[0] * cosTheta);
            pos[0] = y, pos[1] = x;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<vector<int>> paper(n, vector<int>(m));
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) cin >> paper[i][j];
    vector<vector<vector<int>>> shapes = {
        {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
        {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
        {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
        {{0, 0}, {0, 1}, {0, 2}, {-1, 2}},
        {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
        {{0, 1}, {1, 0}, {1, 1}, {2, 0}},
        {{0, 0}, {0, 1}, {0, 2}, {1, 1}}
    };
    vector<int> rotations = { 2, 1, 4, 4, 4, 4, 4 };

    int answer = 0;
    for (int i = 0; i < shapes.size(); i++) {
        Tetromino tetromino(shapes[i]);
        for (int j = 0; j < rotations[i]; j++) {
            for (int y = 0; y < n; y++) {
                for (int x = 0; x < m; x++) {
                    int sum = 0;
                    for (int k = 0; k < 4; k++) {
                        int xx = x + tetromino.shape[k][1];
                        int yy = y + tetromino.shape[k][0];
                        if (xx >= 0 && xx < m && yy >= 0 && yy < n)sum += paper[yy][xx];
                    }
                    answer = max(answer, sum);
                }
            }
            tetromino.Rotation();
        }
    }
    cout << answer;
}