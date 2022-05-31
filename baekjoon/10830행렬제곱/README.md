# 백준[11660](https://www.acmicpc.net/problem/10830)번
## 문제
 크기가 N*N인 행렬 A가 주어진다. 이때, A의 B제곱을 구하는 프로그램을 작성하시오. 수가 매우 커질 수 있으니, A^B의 각 원소를 1,000으로 나눈 나머지를 출력한다.

## 입력
 첫째 줄에 행렬의 크기 N과 B가 주어진다. (2 ≤ N ≤  5, 1 ≤ B ≤ 100,000,000,000)

 둘째 줄부터 N개의 줄에 행렬의 각 원소가 주어진다. 행렬의 각 원소는 1,000보다 작거나 같은 자연수 또는 0이다.


## 출력
 첫째 줄부터 N개의 줄에 걸쳐 행렬 A를 B제곱한 결과를 출력한다.

## 내 풀이
 $X$라는 행렬이 있을때 $X$<sup>$2n$</sup>은 ($X^n$)<sup>$2$</sup>으로 치환이 가능하고 $X$<sup>$2n+1$</sup>은 $X$<sup>$2n$</sup> x $X$로 치환이 가능하다는 점을 이용하면 된다.

 즉 $X^8$은 8개의 $X$를 서로 곱하느라 7번의 계산을 하는 것 보다 (($X$<sup>$2$</sup>)<sup>$2$</sup>)<sup>$2$</sup>을 통해 3번만 계산하는게 빠르다는 것이다. 그러므로 $X$<sup>$2n$</sup>이 주어졌을때는 $X$<sup>$n$</sup> x $X$<sup>$n$</sup>, $X$<sup>$2n+1$</sup>은 $X$<sup>$n$</sup> x $X$<sup>$n$</sup> x $X$로 나누어 주어 X부터 올라오면서 계산을 해 주는 것이다.

## 구현([전체 코드 파일](/baekjoon/10830행렬제곱/c.py))
``` python
def conv(A:list, B:list)->list:
	result = []
	for m in range(len(A)):
		tmpL = []
		for n in range(len(B)):
			tmp = 0
			for k in range(len(A)):
				tmp += A[m][k]*B[k][n]
				tmp %= 1000
			tmpL.append(tmp)
		result.append(tmpL)
	return result

def con(A:list, B:int):
	if B==1:
		return A
	else:
		tmp = con(A,B//2)
		tmp = conv(tmp,tmp)
		if B%2==1:
			tmp = conv(tmp,A)
		return tmp

def solution(N:int, B:int):
	A = [list(map(int,input().strip().split())) for _ in range(N)]
	A = [[v%1000 for v in a] for a in A]
	tmp = con(A,B)
	return tmp

def printM(A:list)->None:
	for v in A:
		print(" ".join(map(str,v)))
```

## 잡담
 아니 이 문제.. 1000을 원소로 주면... 처음부터 나머지 계산 하고 시작하라는건가..? 이것 때문에 얼마나 틀린겨...

    1 1
    1000
이런식으로 주어지면 하.... 하..................