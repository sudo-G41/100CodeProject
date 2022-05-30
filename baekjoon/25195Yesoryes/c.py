import sys
from sys import stdin
sys.setrecursionlimit(10**5)
N, M = list(map(int,stdin.readline().strip().split()))
G = [[] for _ in range(N+1)]

for _ in range(M):
	x, y = list(map(int, stdin.readline().strip().split()))
	G[x].append(y)

S = int(stdin.readline().strip())
S = list(map(int, stdin.readline().strip().split()))

def solu(G:list, S:list, idx:int):
	if len(G[idx])==0:
		return True
	for i in G[idx]:
		if i not in S:
			if solu(G,S,i):
				return True
	return False
if 1 in S:
	print("Yes")
else:
	print("yes" if solu(G,S,1) else "Yes")
