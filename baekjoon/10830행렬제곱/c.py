from sys import stdin
input = stdin.readline

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

if __name__ == "__main__":
	isinput = "start"
	while isinput:
		N, B = list(map(int,input().strip().split()))
		printM(solution(N,B))
		isinput = input()
