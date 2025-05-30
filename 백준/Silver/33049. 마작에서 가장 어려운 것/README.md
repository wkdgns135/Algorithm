# [Silver IV] 마작에서 가장 어려운 것 - 33049 

[문제 링크](https://www.acmicpc.net/problem/33049) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

브루트포스 알고리즘, 수학, 정수론

### 제출 일자

2025년 4월 2일 10:55:20

### 문제 설명

<p>마작에서 가장 어려운 것은 같이 마작을 칠 사람을 구하는 것입니다.</p>

<p>여러분은 이 문제를 해결하기 위해 마작을 칠 사람을 모았고, 굉장히 많은 사람이 와 주었습니다.</p>

<p>또 다른 문제는 사람들이 치는 마작이 한 종류가 아니라는 점입니다. 구체적으로는, $3$명의 사람이 모여서 치는 $3$인 마작과 $4$명의 사람이 모여서 치는 $4$인 마작의 두 종류로 나눠집니다. 여러분이 모은 $N$명의 사람들 중에는 $3$인 마작만 치고 싶어하는 사람도 있고, $4$인 마작만 치고 싶어하는 사람도 있습니다. 어떤 종류든 마작만 칠 수 있으면 상관없다는 사람도 물론 있습니다.</p>

<p>이제 여러분의 새로운 과제는 $N$명의 사람을 $3$명 또는 $4$명의 단위로 적절히 나눠 모두가 원하는 종류의 마작을 칠 수 있도록 하는 것입니다. 또한, 이에 맞춰 테이블을 마작의 종류에 맞춰 세팅해야 합니다. 다만, 여러분은 $3$인 마작을 진정한 마작이 아니라고 생각합니다. 모두가 원하는 마작을 칠 수 있는 세팅이 여러 개라면 $3$인 마작을 치는 테이블을 최대한 적게 만들어야 합니다.</p>

<p>여러분이 몇 개의 $3$인 마작 테이블과 몇 개의 $4$인 마작 테이블을 세팅해야 하는지 구해 주세요.</p>

### 입력 

 <p>첫 번째 줄에 $3$인 마작만 치고 싶은 사람의 수 $P_3$, $4$인 마작만 치고 싶은 사람의 수 $P_4$, 상관없는 사람의 수 $P_0$가 공백으로 구분되어 주어집니다. $(P_3,P_4,P_0 \ge 0;$ $1 \le P_3+P_4+P_0 \le 10^5)$</p>

### 출력 

 <p>세팅해야 할 $3$인 마작 테이블의 수 $T_3$와 $4$인 마작 테이블의 수 $T_4$를 공백으로 구분하여 출력합니다.</p>

<p>만약 모든 사람이 원하는 마작을 칠 수 없다면 대신 <code><span style="color:#e74c3c;">-1</span></code>을 출력합니다.</p>

