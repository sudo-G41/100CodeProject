import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

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

if __name__ == "__main__":
	solution()