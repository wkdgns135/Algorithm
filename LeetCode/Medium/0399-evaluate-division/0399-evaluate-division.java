import java.util.*;

class Solution {
    static class Edge {
        String name;
        double value;

        Edge(String name, double value) {
            this.name = name;
            this.value = value;
        }
    }

    static class Node {
        String name;
        boolean isVisit = false;
        List<Edge> neighbors = new ArrayList<>();

        Node(String name) {
            this.name = name;
        }
    }

    public double bfs(Map<String, Node> map, String start, String target) {
        if (!map.containsKey(start) || !map.containsKey(target)) return -1.0;

        Queue<Edge> bfsQueue = new LinkedList<>();
        bfsQueue.add(new Edge(start, 1.0));
        map.get(start).isVisit = true;

        while (!bfsQueue.isEmpty()) {
            Edge currentEdge = bfsQueue.poll();
            String node = currentEdge.name;
            double value = currentEdge.value;

            if (node.equals(target)) return value;

            for (Edge edge : map.get(node).neighbors) {
                if (!map.get(edge.name).isVisit) {
                    map.get(edge.name).isVisit = true;
                    bfsQueue.add(new Edge(edge.name, edge.value * value));
                }
            }
        }

        return -1.0;
    }

    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        double[] answer = new double[queries.size()];
        Map<String, Node> map = new HashMap<>();

        for (int i = 0; i < equations.size(); i++) {
            String parent = equations.get(i).get(0);
            String child = equations.get(i).get(1);
            double value = values[i];

            map.putIfAbsent(parent, new Node(parent));
            map.putIfAbsent(child, new Node(child));

            map.get(parent).neighbors.add(new Edge(child, value));
            map.get(child).neighbors.add(new Edge(parent, 1.0 / value));
        }

        for (int i = 0; i < queries.size(); i++) {
            String start = queries.get(i).get(0);
            String target = queries.get(i).get(1);

            for (Node node : map.values()) {
                node.isVisit = false;
            }

            answer[i] = bfs(map, start, target);
        }

        return answer;
    }
}
