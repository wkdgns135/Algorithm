#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

set<char> getDigitSet(const string& s)
{
    set<char> digits;
    for (char c : s)
        digits.insert(c);
    return digits;
}

bool canBeAlmostFriends(const string& x, const set<char>& otherDigits)
{
    int n = x.size();
    for (int i = 0; i < n - 1; i++)
    {
        {
            if (x[i] > '0' && x[i + 1] < '9')
            {
                string temp = x;
                temp[i] = char(temp[i] - 1);
                temp[i + 1] = char(temp[i + 1] + 1);
                if (temp[0] == '0' && temp.size() > 1);
                else if (getDigitSet(temp) == otherDigits)
                    return true;
            }
        }

        {
            if (x[i] < '9' && x[i + 1] > '0')
            {
                string temp = x;
                temp[i] = char(temp[i] + 1);
                temp[i + 1] = char(temp[i + 1] - 1);
                if (temp[0] == '0' && temp.size() > 1);
                else if (getDigitSet(temp) == otherDigits)
                    return true;
            }
        }
    }
    return false;
}

void calc(string a, string b)
{
    set<char> setA = getDigitSet(a);
    set<char> setB = getDigitSet(b);

    if (setA == setB)
    {
        cout << "friends" << "\n";
        return;
    }

    if (canBeAlmostFriends(a, setB) || canBeAlmostFriends(b, setA))
        cout << "almost friends" << "\n";
    else
        cout << "nothing" << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    for (int t = 0; t < 3; t++)
    {
        string a, b;
        cin >> a >> b;
        calc(a, b);
    }
}