int solution(int n) {
    int answer = 3, pre_1 = 2, pre_2 = 1;
    if(n < 4) return n;
    for(int i = 3; i <= n; i++){
        answer = (pre_1 + pre_2) % 1000000007;
        pre_2 = pre_1;
        pre_1 = answer;
    }
    return answer;
}