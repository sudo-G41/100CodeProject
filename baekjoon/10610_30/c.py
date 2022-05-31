from sys import stdin
input = stdin.readline

N = input().strip()
L = list(map(int,N))
S = set(L)
if sum(L)%3==0 and 0 in S:
  L.sort(reverse=True)
  print(''.join(list(map(str,L))))
else:
  print(-1)