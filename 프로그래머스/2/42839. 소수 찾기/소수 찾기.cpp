#include <bits/stdc++.h>
using namespace std;

vector<bool> isPrime, used;
int answer, len;
string s;

void CalcPrime(int n)
{
	isPrime.resize(n, true);
    isPrime[0] = false, isPrime[1] = false;
	for (int i = 2; i < sqrt(n); i++)
	{
		if (!isPrime[i]) continue;
		for (int j = i + i; j < n; j += i) isPrime[j] = false;
	}
}

void BT(int depth, string &number){
    if(!s.empty() && isPrime[stoi(s)]){
        isPrime[stoi(s)] = false;
        answer++;
    }
    if(depth == len) return;
    
    for(int i = 0; i < len; i++){
        if(used[i]) continue;
        used[i] = true;
        s.push_back(number[i]);
        BT(depth + 1, number);
        s.pop_back();
        used[i] = false;
    }
}

int solution(string numbers)
{
	sort(numbers.begin(), numbers.end(), greater<>());
    len = numbers.size();
    used.resize(len);
	CalcPrime(stoi(numbers) + 1);
    BT(0, numbers);
    
	return answer;
}