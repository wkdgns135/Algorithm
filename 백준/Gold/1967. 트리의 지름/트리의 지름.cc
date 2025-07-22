#include <bits/stdc++.h>
using namespace std;

struct Node;

struct Edge
{
	Node* next;
	int cost;
};

struct Node
{
	int n;
	vector<Edge> edges;

	Node(int n)
	{
		this->n = n;
	}
};

pair<int, Node*> Dfs(Node* startNode, vector<Node*>& graph)
{
	stack<Node*> dfs;
	dfs.push(startNode);

	vector<int> visited(graph.size(), -1);

	visited[startNode->n] = 0;
	int maxCost = 0;
	Node* maxNode = 0;

	while (!dfs.empty())
	{
		Node* node = dfs.top();
		int cost = visited[node->n];
		dfs.pop();

		if (maxCost < cost)
		{
			maxCost = cost;
			maxNode = node;
		}

		for (Edge& edge : graph[node->n]->edges)
		{
			if (visited[edge.next->n] == -1)
			{
				visited[edge.next->n] = cost + edge.cost;
				dfs.push(edge.next);
			}
		}
	}

	return { maxCost, maxNode };
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n;
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	vector<Node*> graph(n);
	for (int i = 0; i < n; i++)
	{
		graph[i] = new Node(i);
	}

	for (int i = 0; i < n - 1; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		a--, b--;
		graph[a]->edges.push_back({ graph[b], c });
		graph[b]->edges.push_back({ graph[a], c });
	}

	auto [_, FarNode] = Dfs(graph[0], graph);
	cout << Dfs(FarNode, graph).first;
}
