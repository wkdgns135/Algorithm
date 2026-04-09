#include <string>
#include <vector>
#include <list>
#include <set>

using namespace std;

long long answer = 0;
vector<char> opers;
set<char> baseOpers;

void extract(string& expression, list<string>& split)
{
	string num = "";
	for (char& c : expression)
	{
		if (c >= '0')num.push_back(c);
		else
		{
			split.push_back(num);
			num = c;
			split.push_back(num);
			baseOpers.insert(c);
			num = "";
		}
	}
	split.push_back(num);
}

bool isUsed(char c, int end)
{
	for (int i = 0; i < end; i++)
	{
		if (c == opers[i]) return true;
	}
	return false;
}

void combination(const list<string>& split, int depth)
{
	if (depth == baseOpers.size())
	{
		list<string> cur = split;

		for (char c : opers)
		{
			string oper(1, c);

			for (auto iter = cur.begin(); iter != cur.end(); )
			{
				if (*iter == oper)
				{
					long long a = stoll(*prev(iter));
					long long b = stoll(*next(iter));
					long long res = 0;

					switch (c)
					{
					case '*': res = a * b; break;
					case '+': res = a + b; break;
					case '-': res = a - b; break;
					}

					auto pos = cur.erase(prev(iter), next(next(iter)));
					iter = cur.insert(pos, to_string(res));
				}
				else
				{
					++iter;
				}
			}
		}

		answer = max(answer, llabs(stoll(cur.front())));
		return;
	}

	for (auto iter = baseOpers.begin(); iter != baseOpers.end(); ++iter)
	{
		if (isUsed(*iter, depth)) continue;
		opers[depth] = *iter;
		combination(split, depth + 1);
	}
}


long long solution(string expression)
{
	list<string> split;
	extract(expression, split);
	opers.resize(baseOpers.size());

	combination(split, 0);

	return answer;
}