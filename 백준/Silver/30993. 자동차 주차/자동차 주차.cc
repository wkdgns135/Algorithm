#include <bits/stdc++.h>
using namespace std;

long long fact(int x) {
  if (x == 0) return 1;
  return x * fact(x - 1);
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  cout << fact(n) / fact(a) / fact(b) / fact(c);
}
