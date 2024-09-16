#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    
    vector<int> preMin(3), preMax(3), nowMin(3), nowMax(3);
    for (int i = 0; i < 3; i++) cin >> preMin[i];
    preMax = preMin;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int num; cin >> num;
            int left = clamp(j - 1, 0, 3), right = clamp(j + 2, 0, 3);
            nowMin[j] = num + *min_element(preMin.begin() + left, preMin.begin() + right);
            nowMax[j] = num + *max_element(preMax.begin() + left, preMax.begin() + right);
        }
        preMin = nowMin;
        preMax = nowMax;
    }

    cout << *max_element(preMax.begin(), preMax.end()) << ' ' << *min_element(preMin.begin(), preMin.end());
}