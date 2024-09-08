#include <bits/stdc++.h>
using namespace std;

class Factorial {
public:
    vector<int> v;
    Factorial(int n) {
        v = vector<int>(n);
        for (int i = 1; i <= n; i++) {
            v[i - 1] = i;
        }
    }

    Factorial operator* (Factorial x) {
        for (int i = 0; i < x.v.size(); i++)v.push_back(x.v[i]);
        return *this;
    }

    Factorial operator / (Factorial x) {
        while (!x.v.empty()) {
            int n = x.v.back();
            x.v.pop_back();

            bool flag = true;
            for (int& i : v) {
                if (i % n == 0) {
                    i = i / n;
                    flag = false;
                    break;
                }
            }

            if (flag) {
                v.push_back(-n);
            }
        }
        return *this;
    }
    void Print() {
        long long sum = 1;
        sort(v.begin(), v.end(), greater<>());
        for (int& i : v) {
            if (i > 0)sum *= i;
            else sum /= abs(i);
        }
        cout << sum << '\n';
    }
    
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    while (n--) {
        int a, b; cin >> a >> b;
        int N = max(a, b), M = min(a, b);
        Factorial fact = Factorial(N) / (Factorial(N - M) * Factorial(M));
        fact.Print();
    }
}