#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Stage {
    double mass;    // 각 스테이지의 질량 (kg)
    double time;    // 스테이지 지속 시간 (s)
    double thrust;  // 스테이지가 발생하는 추력 (kg m/s^2)
};

double calculateRocketHeight(int n, double M, const vector<Stage>& stages) {
    // 변수 초기화
    double height = 0.0;      // 현재 로켓 높이
    double velocity = 0.0;    // 현재 로켓 속도
    double currentTime = 0.0; // 현재까지 경과 시간
    const double g = 9.81;    // 중력 가속도 (m/s^2)
    
    // 로켓의 초기 질량 계산 (로켓 + 모든 스테이지)
    double currentMass = M;
    for (const auto& stage : stages) {
        currentMass += stage.mass;
    }
    
    // 각 스테이지를 순서대로 처리
    for (int i = 0; i < n; i++) {
        double stageMass = stages[i].mass;    // 현재 스테이지 질량
        double stageTime = stages[i].time;    // 현재 스테이지 지속 시간
        double stageThrust = stages[i].thrust; // 현재 스테이지 추력
        
        // 추력과 중력에 의한 가속도 계산
        double aThrust = stageThrust / currentMass;
        double aNet = aThrust - g;
        
        // 운동 방정식을 사용하여 높이와 속도 업데이트
        height += velocity * stageTime + 0.5 * aNet * stageTime * stageTime;
        velocity += aNet * stageTime;
        
        // 시간과 질량 업데이트 (현재 스테이지 폐기)
        currentTime += stageTime;
        currentMass -= stageMass;
    }
    
    return height;
}

int main() {
    int K;
    cin >> K;  // 테스트 케이스 수 읽기
    
    for (int caseNum = 1; caseNum <= K; caseNum++) {
        int n;
        double M;
        cin >> n >> M;  // 스테이지 수와 로켓 자체 질량 읽기
        
        vector<Stage> stages(n);
        for (int i = 0; i < n; i++) {
            cin >> stages[i].mass >> stages[i].time >> stages[i].thrust;
        }
        
        // 최종 높이 계산
        double height = calculateRocketHeight(n, M, stages);
        
        // 결과 출력
        cout << "Data Set " << caseNum << ":" << endl;
        cout << fixed << setprecision(2) << height << endl;
    }
    
    return 0;
}