#include <bits/stdc++.h>
using namespace std;
#define SIZE 3163

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int x; cin >> x;
    pair<int, int> pos = { 0, 0 };
    int offsets[2] = { -1, 1 };
    int size = 0, offset = 0, count = 1;
    while (count < x) {
        for (int i = 0; i < size; i++) {
            pos.first += offsets[offset];
            pos.second += offsets[!offset];
            count++;
            if (count >= x)break;
        }
        if (count >= x)break;

        if (offset) pos.first++;
        else pos.second++;
        
        offset = !offset;
        size++;
        count++;
    }

    cout << to_string(pos.first + 1) + "/" + to_string(pos.second + 1);
}