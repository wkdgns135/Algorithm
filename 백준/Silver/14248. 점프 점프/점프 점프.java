import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int count = 0;
        
        int[] a = new int[n];
        boolean[] visit = new boolean[n];
        
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        
        int s = sc.nextInt();  // 시작 지점 입력
        
        Stack<Integer> dfs = new Stack<>();
        dfs.push(s - 1);
        visit[s - 1] = true;
        
        while (!dfs.isEmpty()) {
            int i = dfs.pop();
            count++;
            int left = i - a[i];
            int right = i + a[i];
            
            if (left >= 0 && !visit[left]) {
                visit[left] = true;
                dfs.push(left);
            }
            if (right < n && !visit[right]) {
                visit[right] = true;
                dfs.push(right);
            }
        }
        
        System.out.println(count);
    }
}
