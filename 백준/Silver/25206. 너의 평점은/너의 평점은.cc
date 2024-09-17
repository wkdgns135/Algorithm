#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    unordered_map<string, float> gradeDict = { {"A+", 4.5},{"A0", 4.0} ,{"B+", 3.5} ,{"B0", 3.0} ,{"C+", 2.5} ,{"C0", 2.0} ,{"D+", 1.5} ,{"D0", 1.0},{"F", 0.0} };
    float creditSum = 0, gradeSum = 0;
    for (int i = 0; i < 20; i++) {
        string name, grade; cin >> name;
        float credit; cin >> credit >> grade;
        if (grade == "P")continue;
        creditSum += credit;
        gradeSum += gradeDict[grade] * credit;
    }
    cout << gradeSum / creditSum;
}