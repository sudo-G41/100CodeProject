from sys import stdin

def gdc(a:int, b:int):
    while a%b>0:
        a,b=b,a%b
    return b

def lcm(a:int,b:int):
    return a*b//gdc(a,b)

def times(a:list,b:list,c:list,lst:list,max:int,bSize:int,cSize:int):
    next, now, end = lst
    while max>=now:
        if a[now%next] and b[now%bSize] and c[now%cSize]:
            break
        now+=next
    return now

A=list(map(int,stdin.readline().strip().split()))
B=list(map(int,stdin.readline().strip().split()))
C=list(map(int,stdin.readline().strip().split()))

a=[A[1]<=i and i<=A[2] for i in range(A[0])]
b=[B[1]<=i and i<=B[2] for i in range(B[0])]
c=[C[1]<=i and i<=C[2] for i in range(C[0])]

max=lcm(lcm(A[0],B[0]),C[0])
now = [times(a,b,c,A,max,B[0],C[0]), times(b,c,a,B,max,C[0],A[0]), times(c,a,b,C,max,A[0],B[0])]
now = min(now)
print(-1 if now>max else now)
