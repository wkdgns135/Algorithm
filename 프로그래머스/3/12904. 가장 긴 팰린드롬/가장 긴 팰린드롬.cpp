#include <iostream>
#include <string>
#include <vector>

using namespace std;
int solution(string s)
{
    int answer = 1;
    int n = s.size();
    for(int i = 0; i < n - 1; i++){
        int count1 = 1, count2 = 0;
        for(int j = 1; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; j++, count1+=2);
        for(int j = 1; i - j + 1 >= 0 && i + j < n && s[i - j + 1] == s[i + j]; j++, count2+=2);
        answer = max(answer, count1);
        answer = max(answer, count2);
    }

    return answer;
}