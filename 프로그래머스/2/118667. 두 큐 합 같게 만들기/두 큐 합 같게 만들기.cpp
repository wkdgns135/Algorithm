#include <vector>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2)
{
	int answer = 0;
    int n = queue1.size();
	long long sum1 = 0, sum2 = 0;
	queue1.reserve(n * 3);
	queue2.reserve(n * 3);
	for (int i : queue1) sum1 += i;
	for (int i : queue2) sum2 += i;

	auto it1 = queue1.begin(), it2 = queue2.begin();
	while (answer < n * 3)
	{
		if (sum1 == sum2)
		{
			return answer;
		}
		else if (sum1 > sum2)
		{
			sum1 -= *it1;
			sum2 += *it1;
			queue2.push_back(*it1);
			it1++;
		}
		else
		{
			sum1 += *it2;
			sum2 -= *it2;
			queue1.push_back(*it2);
			it2++;
		}
		answer++;
	}

	return -1;
}