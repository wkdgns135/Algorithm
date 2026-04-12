#include <cmath>

using namespace std;

int answer;

void dfs(long long x, int divCnt, int minusCnt) {
    if (minusCnt > 2 * divCnt || x == 0 || divCnt < 0 || minusCnt < 0) return;
    if (x == 1 && divCnt == 0 && minusCnt == 0) {
        answer++;
        return;
    }

    dfs(x - 1, divCnt, minusCnt - 1);

    if (x % 3 == 0) {
        dfs(x / 3, divCnt - 1, minusCnt);
    }
}

int solution(int n) {
    answer = 0;
    int depth = log(n) / log(3);
    dfs(n - 2, depth, depth * 2 - 2);
    return answer;
}