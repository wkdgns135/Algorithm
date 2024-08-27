#include <bits/stdc++.h>
using namespace std;

vector<int> numbers;
vector<bool> visited;
vector<char> operators;

vector<int> maxNumbers;
vector<int> minNumbers;

bool checkCondition(char oper, int a, int b) {
    return (oper == '>') ? a > b : a < b;
}

void updateNumbers(const vector<int>& currentNumbers, vector<int>& targetNumbers, bool isMax) {
    for (int i = 0; i < currentNumbers.size(); i++) {
        if ((isMax && targetNumbers[i] < currentNumbers[i]) || (!isMax && targetNumbers[i] > currentNumbers[i])) {
            copy(currentNumbers.begin(), currentNumbers.end(), targetNumbers.begin());
            break;
        } else if (targetNumbers[i] != currentNumbers[i]) {
            break;
        }
    }
}

void backtrack(int idx, int limit) {
    if (idx == limit) {
        updateNumbers(numbers, maxNumbers, true);
        updateNumbers(numbers, minNumbers, false);
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (visited[i]) continue;
        if (idx > 0 && !checkCondition(operators[idx-1], numbers[idx-1], i)) continue;
        
        visited[i] = true;
        numbers[idx] = i;
        backtrack(idx + 1, limit);
        visited[i] = false;
    }
}

int main() {
    int n;
    cin >> n;

    operators.resize(n);
    numbers.resize(n + 1);
    maxNumbers.resize(n + 1, 0);
    minNumbers.resize(n + 1, 9);
    visited.resize(10, false);

    for (int i = 0; i < n; i++) cin >> operators[i];

    backtrack(0, n + 1);

    for (int num : maxNumbers) cout << num;
    cout << '\n';
    for (int num : minNumbers) cout << num;
    cout << '\n';

    return 0;
}
