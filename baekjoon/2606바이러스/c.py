from sys import stdin
input = stdin.readline

N = int(input().strip())
M = int(input().strip())

comRoot = [i for i in range(N+1)]
comLevel = [0 for _ in range(N+1)]

def find(comRoot:list, a:int):
    if comRoot[a] == a:
        return a
    comRoot[a] = find(comRoot, comRoot[a])
    return comRoot[a]

def union(comRoot:list, comLevel:list, a:int, b:int):
    A = find(comRoot, a)
    B = find(comRoot, b)
    if A!=B:
        if comRoot[A]<comRoot[B]:
            comRoot[B] = A
        else:
            comRoot[A] = B
            if comLevel[A]<comLevel[B]:
                comLevel[A]+=1

if __name__ == "__main__":
    for _ in range(M):
        com1, com2 = map(int,input().strip().split(" "))
        union(comRoot, comLevel, com1, com2)
    sum = 0
    for i in range(N, 1, -1):
        sum += 1 if find(comRoot, i) == 1 else 0
    print(sum)