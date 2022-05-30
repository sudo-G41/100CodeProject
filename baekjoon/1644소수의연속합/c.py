from sys import stdin
input = stdin.readline

def pr(N:int)->list:
	L = [2,3,5,7,11]
	if N<12:
		return [i for i in L if i<=N]
	for n in range(13,N+1,2):
		if n%5==0:
			continue
		if n%12 in set([1,5,7,11]):
			flag = True
			for i in L:
				if i*i > n:
					break
				if n%i == 0:
					flag = False
					break
			if flag:
				L.append(n)
	return L

def A(N:int)->int:
	L = pr(N)
	s, e, count, tmp = 0, 0, 0, 0
	while True:
		if e<len(L):
			if tmp<N:
				tmp += L[e]
				e += 1
			else:
				if tmp==N:
					count += 1
				tmp -= L[s]
				s += 1
		else:
			if tmp>N:
				tmp -= L[s]
				s += 1
			else:
				if tmp == N:
					count += 1
				break
	return count

if __name__ == "__main__":
	N = input()
	while N:
		print(A(int(N.strip())))
		N = input()