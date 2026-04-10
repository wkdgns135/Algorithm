#include <string>
#include <vector>

using namespace std;

bool check(string& s)
{
    int cnt1 = 0, cnt2 = 0;
    for (char& c : s)
    {
        if (c == '(')cnt1++;
        else cnt2++;
        if (cnt2 > cnt1) return false;
    }
    return true;
}

pair<string, string> split(string& w)
{
    string u, v;

    int cnt1 = 0, cnt2 = 0;
    for (char& c : w)
    {
        if (c == '(')cnt1++;
        else cnt2++;
        u.push_back(c);
        if (cnt1 == cnt2) break;
    }
    for (int i = cnt1 + cnt2; i < w.size(); i++) v.push_back(w[i]);

    return { u, v };
}

void reverse(string &s){
    for(char &c : s){
        if(c == '(') c = ')';
        else c = '(';
    }
}

string function(string& w)
{
    if (w == "") return w;

    auto [u, v] = split(w);

    if (check(u)) return u + function(v);
    else
    {
        string temp = "(";
        temp += function(v);
        temp.push_back(')');
        u.erase(u.begin());
        u.pop_back();
        reverse(u);
        return temp + u;
    }
}

string solution(string p)
{
    return function(p);
}