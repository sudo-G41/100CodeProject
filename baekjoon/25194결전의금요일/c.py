from sys import stdin
N = int(stdin.readline().strip())
lst = list(map(int,stdin.readline().strip().split()))

s1=set()
s2=set()
for l in lst:
	for s in s1:
		tmp = (l+s)%7
		s2.add(tmp)
	s1.add(l%7)
	s1.update(s2)
	s2=set()
		
print("YES" if 4 in s1 else "NO")
