#include<iostream>
using namespace std; int main() { int a[41] = { 1,1 }, i; for (i = 2; i < 41; i++)a[i] = a[i - 1] + a[i - 2]; while (cin >> i && i)cout << a[i] << '\n'; }
