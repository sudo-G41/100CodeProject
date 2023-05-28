from sys import stdin
input = stdin.readline

def solution():
	n = int(input().strip())
	for _ in range(n):
		a,b,c = map(int, input().strip().split())
		print(min(a,b,c))

solution()
