#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end)
{
	int answer = 0;
	vector<int> s(data.size());

	sort(data.begin(), data.end(), [col](const vector<int>& a, const vector<int>& b)
		{
			if (a[col - 1] != b[col - 1]) return a[col - 1] < b[col - 1];
			return a[0] > b[0];
		});

	for (int i = row_begin - 1; i < row_end; i++)
	{
		int sum = 0;
		for (int num : data[i]) sum += num % (i + 1);
		answer = answer xor sum;
	}
	return answer;
}