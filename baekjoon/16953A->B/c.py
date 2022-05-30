from sys import stdin
input = stdin.readline

def A():
	s, e = list(map(int,input().strip().split()))
	Q = [{"v":s,"l":1}]
	S = set([s])
	while Q:
		tmp = Q.pop(0)
		if tmp["v"] == e:
			return tmp["l"]
		a,b = tmp["v"]*2, tmp["v"]*10+1
		if a<=e and a not in S:
			S.add(a)
			Q.append({"v":a, "l":tmp["l"]+1})
		if b<=e and b not in S:
			S.add(b)
			Q.append({"v":b, "l":tmp["l"]+1})
	return -1

for _ in range(3):
	print(A())
