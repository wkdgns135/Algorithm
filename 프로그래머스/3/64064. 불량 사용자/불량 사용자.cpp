#include <string>
#include <vector>
#include <set>

using namespace std;

vector<bool> userUsed;
set<vector<string>> result;

bool cmp(const string& a, const string& b)
{
	if (a.size() != b.size()) return false;

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == '*' || b[i] == '*') continue;
		if (a[i] != b[i]) return false;
	}
	return true;
}

void bt(int depth, vector<string>& user_id, vector<string>& banned_id)
{
	if (depth == banned_id.size())
	{
		vector<string> v;
		for (int i = 0; i < user_id.size(); i++)
		{
			if (userUsed[i]) v.push_back(user_id[i]);
		}
		result.insert(v);
		return;
	}

	for (int i = 0; i < user_id.size(); i++)
	{
		if (userUsed[i]) continue;
		if (cmp(banned_id[depth], user_id[i]))
		{
			userUsed[i] = true;
			bt(depth + 1, user_id, banned_id);
			userUsed[i] = false;
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    userUsed.resize(user_id.size());
    bt(0, user_id, banned_id);    
	return result.size();
}