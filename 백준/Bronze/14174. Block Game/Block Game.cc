#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<string, string>> boards(N);

    for (int i = 0; i < N; ++i) {
        cin >> boards[i].first >> boards[i].second;
    }

    vector<int> result(26, 0);

    for (int ch = 0; ch < 26; ++ch) {
        char letter = 'a' + ch;
        int max_need = 0;

        for (int mask = 0; mask < (1 << N) && N <= 20; ++mask) {
            int cnt = 0;
            for (int i = 0; i < N; ++i) {
                string word = (mask & (1 << i)) ? boards[i].first : boards[i].second;
                cnt += count(word.begin(), word.end(), letter);
            }
            max_need = max(max_need, cnt);
        }

        if (N > 20) {
            int cnt = 0;
            for (int i = 0; i < N; ++i) {
                int c1 = count(boards[i].first.begin(), boards[i].first.end(), letter);
                int c2 = count(boards[i].second.begin(), boards[i].second.end(), letter);
                cnt += max(c1, c2);
            }
            max_need = cnt;
        }

        result[ch] = max_need;
    }

    for (int i = 0; i < 26; ++i) {
        cout << result[i] << '\n';
    }

    return 0;
}
