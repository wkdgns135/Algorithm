#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector<bool> temp;

bool check1(vector<vector<string>>& relation)
{
	map<vector<string>, bool> um;
	for (int i = 0; i < relation.size(); i++)
	{
		vector<string> v;
		for (int j = 0; j < relation[i].size(); j++)
		{
			if (temp[j]) v.push_back(relation[i][j]);
		}
		if (um[v]) return false;
		else um[v] = true;
	}

	return true;
}

bool check2(vector<int>& bitmask)
{
	int curMask = 0;
	for (int i = 0; i < temp.size(); i++)
		if (temp[i]) curMask |= (1 << i);

	for (int bit : bitmask)
	{
		if ((curMask & bit) == bit && bit != 0)
			return false;
	}
	bitmask.push_back(curMask);
	return true;
}

int solution(vector<vector<string>> relation)
{
	int colSize = relation[0].size();
	temp.assign(colSize, false);

	int answer = 0;

	vector<int> bitmask;
	queue<pair<vector<bool>, int>> q;
	q.push({ temp, 0 });

	while (!q.empty())
	{
		auto [cur, idx] = q.front();
		q.pop();

		temp = cur;
		if (check1(relation) && check2(bitmask))
		{
			answer++;
			continue;
		}

		for (int i = idx; i < colSize; i++)
		{
			if (!cur[i])
			{
				auto next = cur;
				next[i] = true;
				q.push({ next, i + 1 });
			}
		}
	}
	return answer;
}