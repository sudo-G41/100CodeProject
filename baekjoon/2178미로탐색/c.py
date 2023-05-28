from sys import stdin
input = stdin.readline

def solution():
    N, M = map(int, input().strip().split())
    l = [list(map(int, list(input().strip()))) for _ in range(N)]
    move = [(0,1),(0,-1),(1,0),(-1,0)]
    que = [(l[:], 1, 0, 0)]
    while(que):
        m, n, x, y = que.pop(0)
        if x == N-1 and y == M-1:
            return n
        for xx, yy in move:
            xx += x
            yy += y
            if -1<xx<N and -1<yy<M:
                if(m[xx][yy] == 1):
                    tmp = m[:]
                    tmp[xx][yy] = 0
                    que.append((tmp, n+1, xx, yy))

print(solution())
