import java.util.*;

class Solution {
    public int solution(int[] numbers, int target) {
        int answer = 0;
        Stack<int[]> dfs = new Stack<>();
        dfs.push(new int[]{0, 0}); // {index, value}
        
        while (!dfs.isEmpty()) {
            int[] current = dfs.pop();
            int index = current[0];
            int value = current[1];
            
            if (index == numbers.length) {
                if (value == target) {
                    answer++;
                }
            } else {
                dfs.push(new int[]{index + 1, value + numbers[index]});
                dfs.push(new int[]{index + 1, value - numbers[index]});
            }
        }
        
        return answer;
    }
}