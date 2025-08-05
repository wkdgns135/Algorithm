#include <bits/stdc++.h>
using namespace std;

struct Num
{
	int num;
	bool deleted;
};

struct NumCmpMax
{
	bool operator()(const Num* a, const Num* b) const
	{
		return a->num < b->num;
	}
};
struct NumCmpMin
{
	bool operator()(const Num* a, const Num* b) const
	{
		return a->num > b->num;
	}
};

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	while (t--)
	{
		int k; cin >> k;
		priority_queue <Num*, vector<Num*>, NumCmpMax> maxHeap;
		priority_queue <Num*, vector<Num*>, NumCmpMin> minHeap;

		for (int i = 0; i < k; i++)
		{
			char d;
			int n;
			cin >> d >> n;
			if (d == 'I')
			{
				Num* newNum = new Num();
				newNum->num = n;

				maxHeap.push(newNum);
				minHeap.push(newNum);
			}
			else if (n == 1)
			{
				while (!maxHeap.empty() && maxHeap.top()->deleted) maxHeap.pop();

				if (!maxHeap.empty())
				{
					maxHeap.top()->deleted = true;
					maxHeap.pop();
				}
			}
			else
			{
				while (!minHeap.empty() && minHeap.top()->deleted) minHeap.pop();

				if (!minHeap.empty())
				{
					minHeap.top()->deleted = true;
					minHeap.pop();
				}
			}
		}

		while (!maxHeap.empty() && maxHeap.top()->deleted) maxHeap.pop();
		while (!minHeap.empty() && minHeap.top()->deleted) minHeap.pop();

		if (maxHeap.empty()) cout << "EMPTY" << '\n';
		else cout << maxHeap.top()->num << ' ' << minHeap.top()->num << '\n';
	}
}