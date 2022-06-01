# 백준[11660](https://www.acmicpc.net/problem/25200)번
## 문제
 곰곰이는 좋아하는 음료수 자판기가 있다. 이 자판기에는 "랜덤" 버튼이 있는데, 이 버튼을 누르면 이세계에서 출발한 음료수가 $M$ 번의 차원 이동 후 자판기 상품 출구로 떨어진다.

하지만 차원 이동은 불안정하기 때문에, 음료수 종류가 도중에 바뀌는 일도 있다. 정확히는 아래와 같은 규칙에 의해 바뀐다.

* $i\ (1 \le i \le M)$ 번째 차원 이동 중에, 음료수 종류 $U_i$ 는 $V_i$ 로 변경된다. $(1 \le U_i, V_i \le N)$ 

곰곰이는 $1$ 부터 $N$ 까지 모든 종류의 음료수에 대해, 각각 $M$ 번의 차원 이동을 거쳐 최종적으로 어떤 종류의 음료수가 되는지 알고 싶다.

## 입력
 첫 번째 줄에 음료수의 종류 개수 $N$, 차원 이동 횟수 $M$ 이 공백을 사이에 두고 주어진다. $(2 \le N, M \le 300\,000)$ 

두 번째 줄부터 $M$개의 줄에 걸쳐 정수 $U_i, V_i$ 가 공백을 사이에 두고 주어진다. $(1 \le i \le M,\ 1 \le U_i, V_i \le N,\ U_i \ne V_i)$ 

## 출력
  $f(k)$ 가 음료수 종류 $k$ 가 $M$ 번의 차원 이동을 거쳐 최종적으로 변하는 음료수 종류라고 할 때, $f(1), f(2), \cdots, f(N)$ 을 첫 번째 줄에 공백을 사이에 두고 출력하라.

## 내 풀이
 음료의 차원 이동을 저장하는 배열 $LJ$와 몇 번째 차원 이동인지를 저장하는 $LI$, 한번이라도 들렸는지를 확인하는 딕셔너리 $S$를 만든다.

$LJ_i$에는 $U_i$를 $LI_i$는 $V_i$를 $S$는 $(i,U_i) : f(i)$형식으로 저장한다.

그 후 $1$번부터 $N$까지 순화하면서 $f(i)$를 찾는데 이때 $S$에 있으면 $S$에서 확인하고 없으면 $Vi$를 통해 찾아가면서 $S$에 저장해 준다.

$f(i)$를 찾을때는 $V_i$ = $U_j$라 할 때 $i<j$ 를 만족해야 된다. 그러르모 $LI_i$의 값중 $j$를 넘는 값을 탐색해야 하는데 이때 이진탐색을 통해 찾아야 시간초과가 발생하지 않는다.

## 구현([전체 코드 파일](/baekjoon/25200곰곰이와자판기/c.py))
``` python
def find(S:dict, iList:list, endList:list, juice:int, idx:int)->int:
	if not endList[juice]:
		return juice
	nowI = iList[juice][idx]
	nextJ = endList[juice][idx]
	nextI = -1

	if (nowI, juice) in S:
		return S[(nowI, juice)]
	elif iList[nextJ]:
		s = 0
		e = len(iList[nextJ])-1
		nextIdx = (e + s) // 2
		nextI = iList[nextJ][nextIdx]
		while s+1 < e:
			if nextI > nowI:
				e = nextIdx
			else:
				s = nextIdx
			nextIdx = (e + s) // 2
			nextI = iList[nextJ][nextIdx]
		if nextI < nowI and nextIdx+1<len(iList[nextJ]):
			nextI = iList[nextJ][nextIdx+1]
			nextIdx += 1
		if nextI > nowI:
			tmp = find(S,iList, endList, nextJ, nextIdx)
			S[(nowI, juice)] = tmp
			return tmp
		return nextJ
	else:
		return nextJ

def solution()->list:
	N,M = list(map(int,input().strip().split()))
	iList = [[] for _ in range(N+1)]
	endList = [[] for _ in range(N+1)]
	S = {}
	for i in range(M):
		U,V = list(map(int,input().strip().split()))
		iList[U].append(i)
		endList[U].append(V)
	for i,l in enumerate(iList):
		if i == 0:
			continue
		if l:
			print(find(S,iList,endList,i,0),end=" ")
		else:
			print(i, end=" ")
```

## 잡담
 아 몰랑... 내가 풀긴 했는데 자꾸 뭔가 틀려서 멘탈 엄청 갈렸다..
 s랑 e가 자꾸 s=e=0인 상황에서 s<e가 맞다고 하니 멘탈 엄청 갈렸다가 그냥 지우고 다시 적어서 고치긴 했는데 나중에 아는 지인을 통해 원인을 찾았는데 내가 s를 두개 출력해서 e를 제대로 못본거였다... 아마 s=0, e=1인 상황이지 않았을까 생각한다...

 그리고 다른 사람들은 이것보다 더 좋은 풀이가 있겠지..? 내가 .... 여기까지... 하...