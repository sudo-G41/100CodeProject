import math
i = int(input())
s = input()
C = 0
for c in s:
  if c == 'C':
    i-=1
    C+=1
print(math.ceil((C/(i+1))))