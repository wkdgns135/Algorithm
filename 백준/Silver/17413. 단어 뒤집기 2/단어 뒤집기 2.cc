#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);

    string str;
    getline(cin, str);
    str += ' ';
    stack<char> s;
    queue<char> q;
    bool parentheses = false;
    for (const char& ch : str)
    {
        if (ch == '<')
        {
            while (!s.empty())
            {
                cout << s.top();
                s.pop();
            }
            parentheses = true;
            cout << '<';
        }
        else if (ch == '>')
        {
            parentheses = false;
            while (!q.empty())
            {
                cout << q.front();
                q.pop();
            }
            cout << '>';
        }
        else if (parentheses)
        {
            q.push(ch);
        }
        else
        {
            if (ch == ' ')
            {
                while (!s.empty())
                {
                    cout << s.top();
                    s.pop();
                }
                cout << ' ';
            }
            else
            {
                s.push(ch);
            }
        }
    }
}
