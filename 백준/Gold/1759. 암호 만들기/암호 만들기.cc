#include <bits/stdc++.h>
using namespace std;

int l, c;
vector<char> input, output;

int CountVowel(vector<char>& v) {
    char vowels[5] = { 'a', 'e', 'i', 'o', 'u' };
    int result = 0;
    for (auto ch : v)for (auto vowel : vowels)if (ch == vowel)result++;
    return result;
}

void BackTracking(int depth, int index) {
    if (depth == l) {
        int vowel = CountVowel(output);
        if (vowel > 0 && l - vowel > 1) {
            for (auto ch : output)cout << ch;
            cout << '\n';
        }
        return;
    }

    for (int i = index; i < c; i++) {
        output[depth] = input[i];
        BackTracking(depth + 1, i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> l >> c;
    input = vector<char>(c), output = vector<char>(l);
    for (int i = 0; i < c; i++) cin >> input[i];
    sort(input.begin(), input.end());
    BackTracking(0, 0);
}