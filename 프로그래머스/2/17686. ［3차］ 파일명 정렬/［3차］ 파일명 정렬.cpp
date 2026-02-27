#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Split
{
public:
	string head;
	int number;
	string* origin;

	Split(string& s)
	{
		head = "";
		auto it = s.begin();
		while (*it < '0' || *it > '9') head.push_back(toupper(*(it++)));

		string temp = "";
		while (it != s.end() && *it >= '0' && *it <= '9') temp.push_back(*(it++));
		number = stoi(temp);

		origin = &s;
	}

	bool operator< (const Split& x) const
	{
		if (head != x.head) return head < x.head;
		if (number != x.number) return number < x.number;

		return false;
	}
};

vector<string> solution(vector<string> files)
{
	vector<string> answer;
	vector<Split> v;
	for (string& file : files)
	{
		v.push_back(Split(file));
	}

	stable_sort(v.begin(), v.end());

	for (Split& s : v)
	{
		answer.emplace_back(move(*s.origin));
	}

	return answer;
}