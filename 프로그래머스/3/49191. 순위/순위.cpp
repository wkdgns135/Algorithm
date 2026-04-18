#include <vector>
#include <queue>

using namespace std;

struct Node
{
	int n = 0;
	vector<Node*> parents, childs;

	Node(int x) : n(x) {};
};

int solution(int n, vector<vector<int>> results)
{
	int answer = 0;
	vector<Node> graph;
	graph.reserve(n + 1);
	for (int i = 0; i <= n; i++)
	{
		graph.push_back(Node(i));
	}

	for (auto& result : results)
	{
		graph[result[0]].childs.push_back(&graph[result[1]]);
		graph[result[1]].parents.push_back(&graph[result[0]]);
	}

	for (int i = 1; i <= n; i++)
	{
		Node& node = graph[i];
		int parentCount = 0, childCount = 0;
		vector<bool> visited(n + 1);
		visited[i] = true;
		queue<Node*> bfs;
		bfs.push(&node);

		while (!bfs.empty())
		{
			Node* curr = bfs.front();
			bfs.pop();
			for (Node* next : curr->parents)
			{
				if (visited[next->n]) continue;
				parentCount++;
				visited[next->n] = true;
				bfs.push(next);
			}
		}

		visited = vector<bool>(n + 1);
		bfs.push(&node);
		visited[i] = true;

		while (!bfs.empty())
		{
			Node* curr = bfs.front();
			bfs.pop();
			for (Node* next : curr->childs)
			{
				if (visited[next->n]) continue;
				childCount++;
				visited[next->n] = true;
				bfs.push(next);
			}
		}
		if (parentCount + childCount == n - 1) answer++;
	}

	return answer;
}