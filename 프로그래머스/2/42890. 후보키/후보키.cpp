#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// cols(선택된 컬럼 인덱스들)로 각 행을 묶었을 때 유일성 검사
static bool isUnique(const vector<vector<string>>& relation, const vector<int>& cols) {
    unordered_set<string> seen;
    seen.reserve(relation.size() * 2);

    for (const auto& row : relation) {
        string key;
        key.reserve(cols.size() * 16);
        for (int c : cols) {
            key += row[c];
            key += '\x1f'; // 구분자(UNIT SEPARATOR)
        }
        if (!seen.insert(key).second) return false; // 중복 발생 → 유일성 실패
    }
    return true;
}

// 현재 조합(cur)에 대해, 이미 찾은 후보키들(keys)이 부분집합이면 최소성 실패
static bool isMinimal(const vector<int>& cur, const vector<vector<int>>& keys) {
    for (const auto& key : keys) {
        bool subset = true;
        // key ⊆ cur ?
        for (int k : key) {
            if (!binary_search(cur.begin(), cur.end(), k)) { // cur은 정렬되어 있음
                subset = false;
                break;
            }
        }
        if (subset) return false;
    }
    return true;
}

// 크기 고정 조합 생성(dfs): start부터 남은 left개를 더 뽑아 cur을 완성
static void dfs(const vector<vector<string>>& relation,
                int start, int left, vector<int>& cur,
                vector<vector<int>>& candidateKeys, int& answer) {
    if (left == 0) {
        // 유일성 → 최소성
        if (isUnique(relation, cur) && isMinimal(cur, candidateKeys)) {
            candidateKeys.push_back(cur);
            answer++;
        }
        return;
    }
    const int m = relation[0].size();
    // 가지치기: i는 남은 칸으로 left개를 채울 수 있어야 함
    for (int i = start; i <= m - left; ++i) {
        cur.push_back(i);
        dfs(relation, i + 1, left - 1, cur, candidateKeys, answer);
        cur.pop_back();
    }
}

int solution(vector<vector<string>> relation) {
    const int m = relation[0].size();
    vector<vector<int>> candidateKeys; // 이미 확정된 후보키(인덱스 조합)
    vector<int> cur;
    int answer = 0;

    // 크기 1 → m 순서로 전수조사
    for (int size = 1; size <= m; ++size) {
        dfs(relation, 0, size, cur, candidateKeys, answer);
    }
    return answer;
}
