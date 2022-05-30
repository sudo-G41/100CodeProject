from sys import stdin
input = stdin.readline

N = int(input().strip())
L = [0]
L.extend(list(map(int,input().strip().split())))
a,b = list(map(int,input().strip().split()))

def A(L:list,a:int,b:int)->int:
	if a==b:
		return 0
	q=[{"q":[a],"level":1}]
	size = len(L)-1
	idxSet = set([0])
	while q:
		al = q.pop(0)
		for aa in al["q"]:
			if aa>size:
				continue
			if isA(L,aa,b):
				return al["level"]
			else:
				tmp = aa%L[aa]
				nextmp = size//L[aa]
				qwer = [tmp+i*L[aa] for i in range(nextmp+1) if tmp+i*L[aa] not in idxSet]
				if qwer:
					q.append({"q":qwer,"level":al["level"]+1})
					idxSet.update(qwer)
	return -1
	
def isA(L:list,a:int,b:int)->bool:
	return (b-a)%L[a] == 0

print(A(L,a,b))