import java.util.*;

public class Solution {
    public int[] solution(String[] maps) {
        List<Integer> answer = new ArrayList<>();
        int[][] visited = new int[maps.length][maps[0].length()];
        int[][] offset = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int i = 0; i < maps.length; i++) {
            for (int j = 0; j < maps[i].length(); j++) {
                if (visited[i][j] == 1 || maps[i].charAt(j) == 'X') continue;
                Stack<int[]> dfs = new Stack<>();
                dfs.push(new int[]{i, j});
                visited[i][j] = 1;
                int count = maps[i].charAt(j) - '0';

                while (!dfs.isEmpty()) {
                    int[] pos = dfs.pop();
                    int x = pos[1];
                    int y = pos[0];

                    for (int k = 0; k < 4; k++) {
                        int xx = x + offset[k][0];
                        int yy = y + offset[k][1];

                        if (xx >= 0 && xx < maps[0].length() && yy >= 0 && yy < maps.length) {
                            if (visited[yy][xx] == 0 && maps[yy].charAt(xx) != 'X') {
                                dfs.push(new int[]{yy, xx});
                                visited[yy][xx] = 1;
                                count += maps[yy].charAt(xx) - '0';
                            }
                        }
                    }
                }
                answer.add(count);
            }
        }

        if (answer.isEmpty()) {
            return new int[]{-1};
        }
        
        Collections.sort(answer);
        return answer.stream().mapToInt(i -> i).toArray();
    }
}
