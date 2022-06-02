# 백준[25196](https://www.acmicpc.net/problem/25196)번
## 문제
 곰곰이는 바위에 앉아 새 3마리가 숲 주변을 비행하는 것을 구경하고 있다. 곰곰이는 새들을 관찰하면서 아래와 같은 사실들을 알아냈다.

* 첫 번째 새는 $A_v$ 초, 두 번째 새는 $B_v$ 초, 세 번째 새는
$C_v$ 초 주기로 숲을 한 바퀴 돈다.
* 현재로부터 $t\ (t \ge 0)$ 초가 지났다고 할 때, 곰곰이는...

    $A_v \times k_a + A_s \le t \le A_v \times k_a + A_e$ 일 때 첫 번째 새를 볼 수 있다. ($k_a$ 는 $0$ 이상의 정수)

    $B_v \times k_b + B_s \le t \le B_v \times k_b + B_e$ 일 때 두 번째 새를 볼 수 있다. ($k_b$ 는 $0$ 이상의 정수)

    $C_v \times k_c + C_s \le t \le C_v \times k_c + C_e$ 일 때 세 번째 새를 볼 수 있다. ($k_c$ 는 $0$ 이상의 정수)

곰곰이가 새 3마리를 한번에 볼 수 있는 최초의 시각은 현재로부터 몇 초 뒤인지 구해보자.

## 입력
 첫 번째 줄에 정수 $A_v$, $A_s$, $A_e$ 가 공백을 사이에 두고 주어진다. ($1 \le A_v \le 2\,000, 0 \le A_s \le A_e \lt A_v$)

두 번째 줄에 정수 $B_v$, $B_s$, $B_e$ 가 공백을 사이에 두고 주어진다. (\le 2\,000, 0 \le B_s \le B_e \lt B_v$)

세 번째 줄에 정수$C_v$, $C_s$, $C_e$ 가 공백을 사이에 두고 주어진다. ($1 \le C_v \le 2\,000, 0 \le C_s \le C_e \lt C_v$)

## 출력
 현재로부터 $t$ 초 뒤에 곰곰이가 새 3마리를 최초로 한번에 볼 수 있다고 할 때, $t$ 를 첫 번째 줄에 출력하라.

만약 그런 순간이 영원히 오지 않는다면 -1 을 출력하라.

## 내 풀이
 일정 주기로 도는 새들이 같은 지점에서 출발해서 같이 도착하는데 시간은 최소 공배수를 통해 알 수 있으므로 최소공배수를 구해주는 함수를 하나 만들었다.

 모두 하나씩 비교하기에는 최악 $1999$ x $1997$ x $1993$의 시간이 걸리기에 시간초과가 일어난다.

 그러므로 좀더 좋은 방법을 찾아야 하는데 이는 A와 B, C를 기준으로 각각 자신이 한바퀴 돌때 다른 새와 겹치는 부분이 언제 나오나를 체크를 하여 가장 짧은 시간을 출력하는 것이다.
 이럼 $1999$ x $1997$ + $1999$ x $1993$ + $1997$ x $1993$의 속도로 찾을 수 있다.
 무슨 차이인가 싶을텐데 이를 BigO로 표현하면 첫 방법으로는 O($N$<sup>3</sup>)이지만 두번째 방법은 O($3N$<sup>2</sup>)이므로$N$이 3보다 크면 무조건 짧다.

 그리고 만약 각각 최소공배수의 시간만큼이 지났는데도 못만나면 그냥 못난난것이다. 그러므로 이때는 그냥 -1을 출력하여 죽어도 못 만난다는 것을 알려주자.

## 구현([전체 코드 파일](/baekjoon/25196숲속에서새구경하기/c.py))
``` python
def gdc(a:int, b:int):
    while a%b>0:
        a,b=b,a%b
    return b

def lcm(a:int,b:int):
    return a*b//gdc(a,b)

def times(a:list,b:list,c:list,lst:list,max:int,bSize:int,cSize:int):
    next, now, end = lst
    while max>=now:
        if a[now%next] and b[now%bSize] and c[now%cSize]:
            break
        now+=next
    return now

A=list(map(int,stdin.readline().strip().split()))
B=list(map(int,stdin.readline().strip().split()))
C=list(map(int,stdin.readline().strip().split()))

a=[A[1]<=i and i<=A[2] for i in range(A[0])]
b=[B[1]<=i and i<=B[2] for i in range(B[0])]
c=[C[1]<=i and i<=C[2] for i in range(C[0])]

max=lcm(lcm(A[0],B[0]),C[0])
now = [times(a,b,c,A,max,B[0],C[0]), times(b,c,a,B,max,C[0],A[0]), times(c,a,b,C,max,A[0],B[0])]
now = min(now)
print(-1 if now>max else now)
```

## 잡담
 최소 공배수까진 알았는데 어떻게 해야 줄일 수 있을까 하다가 좀 특이한 방식으로 슥 훑어봤는데 일단 무작정 확인하는 것 보다 빠르지만 그래도 O($N$<sup>3</sup>)보다 조금 작은 정도라 처음에는 틀렸다.

 그리고 힌트를 얻고 처음 방식에서 필요한 부분만 따와서 변경하니 풀렸다. 빅오를 계산하는 능력좀 길러야 할 것 같다...