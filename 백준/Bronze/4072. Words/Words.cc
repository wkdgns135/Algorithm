#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    string line;

    while (getline(cin, line)) {
        if (line == "#") break;

        stringstream ss(line);
        string word;
        bool first = true;

        while (ss >> word) {
            reverse(word.begin(), word.end());
            if (!first) cout << " ";
            cout << word;
            first = false;
        }
        cout << endl;
    }

    return 0;
}
