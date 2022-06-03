from sys import stdin
input = stdin.readline

def A():
	C, N = map(int,input().strip().split())
	color = {}
	for _ in range(C):
		tmp = color
		for c in input().strip():
			if c not in tmp:
				tmp[c]={}
			tmp = tmp[c]
		tmp["end"]=True
	name = set()
	for _ in range(N):
		name.add(input().strip())
	Q = int(input().strip())
	for _ in range(Q):
		q = input().strip()
		tmp = color
		flag = True
		for idx,c in enumerate(q):
			if c in tmp:
				tmp = tmp[c]
				if "end" in tmp:
					if q[idx+1:] in name:
						print("Yes")
						flag=False
						break
			else:
				if "end" in tmp and q[idx:] in name:
					flag = False
					print("Yes")
					flag = False
					break
				else:
					print("No")
					flag = False
					break
		if flag:
			print("No")

if __name__ == "__main__":
	A()
