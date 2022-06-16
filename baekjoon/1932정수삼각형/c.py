from sys import stdin
input = stdin.readline

def make_triangle(N):
	triangle = [list(map(int,input().strip().split())) for _ in range(N)]
	return triangle

def sum_move(triangle):
	i = 1
	while i < len(triangle):
		j = 0
		while j<len(triangle[i]):
			if j>0:
				if j != len(triangle[i-1]):
					triangle[i][j] += max(triangle[i-1][j],triangle[i-1][j-1])
				else:
					triangle[i][j] += triangle[i-1][j-1]
			else:
				triangle[i][j] += triangle[i-1][j]
			j+=1
		i+=1

N = int(input())
triangle = make_triangle(N)
sum_move(triangle)
print(max(triangle[N-1]))
