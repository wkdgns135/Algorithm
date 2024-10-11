#include <bits/stdc++.h>
using namespace std;

int n;

void print(const char *s, int depth) {
    for (int i = 0; i < depth * 4; i++)cout << '_';
    cout << s << '\n';
}

void func(int depth) {
    print("\"재귀함수가 뭔가요?\"", depth);
    if (depth == n) {
        print("\"재귀함수는 자기 자신을 호출하는 함수라네\"", depth);
        print("라고 답변하였지.", depth);
        return;
    }
    print("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.", depth);
    print("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.", depth);
    print("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"", depth);
    func(depth + 1);
    print("라고 답변하였지.", depth);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << '\n';
    func(0);
}
