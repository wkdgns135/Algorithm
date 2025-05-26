#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // 개행 문자 제거
    
    for (int test = 0; test < n; test++) {
        vector<string> lines;
        string line;
        
        // 각 테스트 케이스의 모든 줄을 읽기
        while (getline(cin, line)) {
            if (line.empty()) { // 빈 줄이면 테스트 케이스 끝
                break;
            }
            lines.push_back(line);
        }
        
        // 전체 문자 수와 인식한 문자 수 계산
        int total_chars = 0;
        int recognized_chars = 0;
        
        for (const string& current_line : lines) {
            for (char c : current_line) {
                total_chars++;
                if (c != '#') {
                    recognized_chars++;
                }
            }
        }
        
        // 인식률 계산
        double efficiency;
        if (total_chars == 0) {
            efficiency = 100.0;
        } else {
            efficiency = (double)recognized_chars / total_chars * 100.0;
        }
        
        // 반올림 처리
        double rounded_efficiency = round(efficiency * 10.0) / 10.0;
        
        // 출력 형식 처리
        cout << "Efficiency ratio is ";
        if (rounded_efficiency == (int)rounded_efficiency) {
            cout << (int)rounded_efficiency;
        } else {
            cout << fixed << setprecision(1) << rounded_efficiency;
        }
        cout << "%." << endl;
    }
    
    return 0;
}