import java.util.*;

class Solution {
    public int solution(String[] board) {
        int[][] offset = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        int rows = board.length;
        int cols = board[0].length();
        boolean[][] visited = new boolean[rows][cols];
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i].charAt(j) == 'R') {
                    Queue<int[]> bfs = new LinkedList<>();
                    bfs.offer(new int[]{i, j, 0});
                    visited[i][j] = true;
                    
                    while (!bfs.isEmpty()) {
                        int[] current = bfs.poll();
                        int x = current[1];
                        int y = current[0];
                        int count = current[2];
                        
                        if (board[y].charAt(x) == 'G') {
                            return count;
                        }
                        
                        for (int k = 0; k < 4; k++) {
                            int xx = x;
                            int yy = y;
                            
                            while (xx >= 0 && xx < cols && yy >= 0 && yy < rows) {
                                if (board[yy].charAt(xx) == 'D') break;
                                xx += offset[k][1];
                                yy += offset[k][0];
                            }
                            
                            xx -= offset[k][1];
                            yy -= offset[k][0];
                            
                            if (visited[yy][xx]) continue;
                            visited[yy][xx] = true;
                            bfs.offer(new int[]{yy, xx, count + 1});
                        }
                    }
                    
                    break;
                }
            }
        }
        
        return -1;
    }
}