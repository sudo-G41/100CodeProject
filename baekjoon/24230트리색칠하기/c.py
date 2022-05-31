from sys import stdin
input = stdin.readline

def solution():
	N = int(input().strip())
	colorList = [0] + list(map(int, input().strip().split()))
	G = [set() for _ in range(N+1)]
	for _ in range(1,N):
		a,b = list(map(int,input().strip().split()))
		G[a].add(b)
		G[b].add(a)
	G[0].add(1)
	G[1].add(0)
	count = 0
	for idx, val in enumerate(G):
		if val:
			for v in val:
				if colorList[idx] != colorList[v]:
					count += 1
	
	return count//2
		
if __name__ == "__main__":
	print(solution())
