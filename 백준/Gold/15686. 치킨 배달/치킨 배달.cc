#include<bits/stdc++.h>
using namespace std;
int m, answer = INT_MAX;
vector<pair<int, int>> houses, chickens, remainChickens;

int Distance(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int Calc() {
    int sum = 0;
    for (auto house : houses) {
        int minVal = INT_MAX;
        for (auto chicken : remainChickens) {
            minVal = min(minVal, Distance(house, chicken));
        }
        sum += minVal;
    }
    return sum;
}

void BackTracking(int depth, int index) {
    if (m == depth) {
        answer = min(answer, Calc());
        return;
    }

    for (int i = index; i < chickens.size(); i++) {
        remainChickens[depth] = chickens[i];
        BackTracking(depth + 1, i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n >> m;
    remainChickens = vector<pair<int, int>>(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int input; cin >> input;
            if (input == 1)houses.push_back({ i,j });
            if (input == 2)chickens.push_back({ i,j });
        }
    }
    BackTracking(0, 0);
    cout << answer;
}
