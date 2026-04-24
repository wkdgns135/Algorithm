#include <string>
#include <vector>

using namespace std;

class Node;

vector<Node> graph;

struct Node
{
    int x1, y1, x2, y2;
    int limit;
    bool deleted = false;
    vector<Node*> neighbor;

    Node(int x1, int y1, int x2, int y2, int cost) : x1(x1), y1(y1), x2(x2), y2(y2), limit(limit) {}

    void split(Node* center)
    {
        int centerX = center->x1, centerY = center->y1;
        Node left(x1, y1, centerX, centerY, 0), right(centerX, centerY, x2, y2, 0);

        if (x1 == x2)
        {
            left.y2--;
            right.y1++;
        }
        else
        {
            left.x2--;
            right.x1++;
        }

        graph.push_back(right);
        graph.push_back(left);
        left.neighbor.push_back(center);
        right.neighbor.push_back(center);

        for (Node* node : neighbor)
        {
            if (node->deleted) continue;
            if (x1 == centerX)
            {
                if (node->y1 < centerY)
                {
                    left.neighbor.push_back(node);
                    node->neighbor.push_back(&left);
                }
                if (node->y1 > centerY)
                {
                    right.neighbor.push_back(node);
                    node->neighbor.push_back(&right);
                }
            }
            else
            {
                if (node->x1 < centerX)
                {
                    left.neighbor.push_back(node);
                    node->neighbor.push_back(&left);
                }
                if (node->x1 > centerX)
                {
                    right.neighbor.push_back(node);
                    node->neighbor.push_back(&right);
                }
            }
        }
        deleted = true;
    }

    void merge(Node* center)
    {
        for (Node* node : neighbor)
        {
            node->neighbor.push_back(center);
            center->neighbor.push_back(node);
        }
        deleted = true;
    }

    bool isCenter()
    {
        return x1 == x2 && y1 == y2;
    }

    bool isCross(Node* node)
    {
        bool thisVertical = x1 == x2;
        bool nodeVertical = node->x1 == node->x2;

        bool thisHorizontal = y1 == y2;
        bool nodeHorizontal = node->y1 == node->y2;

        if (thisVertical && nodeHorizontal)
        {
            return min(node->x1, node->x2) <= x1 && x1 <= max(node->x1, node->x2) &&
                min(y1, y2) <= node->y1 && node->y1 <= max(y1, y2);
        }

        if (thisHorizontal && nodeVertical)
        {
            return min(x1, x2) <= node->x1 && node->x1 <= max(x1, x2) &&
                min(node->y1, node->y2) <= y1 && y1 <= max(node->y1, node->y2);
        }

        return false;
    }
};

vector<int> solution(vector<vector<int>> city, vector<vector<int>> road)
{
    vector<int> answer;
    int n = road.size() * 3;
    graph.reserve(n);
    for (auto& row : road)
    {
        int x1 = row[0], y1 = row[1], x2 = row[2], y2 = row[3], limit = row[4];
        int centerX = x1 == x2 ? x2 : x2 / 2;
        int centerY = y1 == y2 ? y2 : y2 / 2;

        Node left(x1, y1, centerX, centerY, 0);
        Node center(centerX, centerY, centerX, centerY, limit);
        Node right(centerX, centerY, x2, y2, 0);

        if (x1 == x2)
        {
            left.y2--;
            right.y1++;
        }
        else
        {
            left.x2--;
            right.x1++;
        }

        left.neighbor.push_back(&center);
        center.neighbor.push_back(&left);
        center.neighbor.push_back(&right);
        right.neighbor.push_back(&center);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            Node& node1 = graph[i], & node2 = graph[j];
            if (node1.deleted || node2.deleted) continue;

            if (node1.isCross(&node2))
            {
                if (node1.isCenter() && node2.isCenter())
                {
                    if (node1.limit > node2.limit)
                    {
                        node2.merge(&node1);
                    }
                    else
                    {
                        node1.merge(&node2);
                    }
                }
                else if (node1.isCenter() || node2.isCenter())
                {
                    if (node1.x1 == node2.x1 && node1.y1 == node2.y1)
                    {
                        node2.neighbor.push_back(&node1);
                        node1.neighbor.push_back(&node2);
                    }
                    if (node1.x2 == node2.x2 && node1.y2 && node2.y2)
                    {
                        node2.neighbor.push_back(&node1);
                        node1.neighbor.push_back(&node2);
                    }
                }
                else
                {
                    node2.neighbor.push_back(&node1);
                    node1.neighbor.push_back(&node2);
                }
            }
        }
    }


    return answer;
}