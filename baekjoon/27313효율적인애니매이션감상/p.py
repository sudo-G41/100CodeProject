from sys import stdin

input = stdin.readline

def solution():
    N,M,K = map(int, input().strip().split())
    ani = list(map(int,input().strip().split()))
    times = []
    ani.sort()
    for i,v in enumerate(ani):
        if i<K:
            if ani[i]>M:
                return i
            times.append(ani[i])
        else:
            if times[i-K]+ani[i] > M:
                return i
            times.append(times[i-K]+ani[i])
    return N

print(solution())
