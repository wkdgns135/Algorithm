#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n; cin >> t;
    string p;

    while (t--) {
        cin >> p; cin >> n;
        cin.ignore();
        deque<int> dq;
        
        string input; getline(cin, input);
        input = input.substr(1, input.size() - 2);
        int num = 0;
        string temp = "";
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == ',') {
                dq.push_back(stoi(temp));
                temp = "";
            }
            else {
                temp += input[i];
            }
        }
        bool flag = false;

        if (!temp.empty())dq.push_back(stoi(temp));

        int left = 0, right = 0;
        bool toggle = true;
        for (int i = 0; i < p.size(); i++) {
            if (p[i] == 'R')toggle = !toggle;
            else {
                if (toggle)left++;
                else right++;
                if (left + right > dq.size())flag = true;
            }
        }
        if (flag) cout << "error";

        else {
            for (int i = 0; i < left; i++) dq.pop_front();
            for (int i = 0; i < right; i++)dq.pop_back();
            cout << '[';
            if (toggle) {
                for (int i = 0; i < dq.size(); i++) {
                    cout << dq[i];
                    if (i != dq.size() - 1)cout << ',';
                }
            }
            else {
                for (int i = dq.size()-1; i >= 0; i--) {
                    cout << dq[i];
                    if (i != 0)cout << ',';
                }
            }
            
            cout << ']';
        }
        cout << '\n';
    }
}
