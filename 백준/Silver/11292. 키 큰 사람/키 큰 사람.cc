#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break; // 학생 수가 0이면 종료

        vector<pair<string, double>> students;
        double maxHeight = 0.0;
        
        for (int i = 0; i < n; i++) {
            string name;
            double height;
            cin >> name >> height;

            students.push_back({name, height});
            maxHeight = max(maxHeight, height); // 현재까지의 최대 키 저장
        }
        
        // 가장 큰 키를 가진 학생 이름 출력
        for (const auto& student : students) {
            if (student.second == maxHeight) {
                cout << student.first << ' ';
            }
        }
        cout << '\n'; // 테스트케이스 끝에 줄바꿈
    }
}
