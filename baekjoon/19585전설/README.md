# 백준[19585](https://www.acmicpc.net/problem/19585)번
## 문제
 Sogang ICPC Team에는 색상 이름과 닉네임의 순서로 이여서 팀명을 지으면 ICPC 리저널에서 수상할 수 있다는 전설이 있다. 색상 이름들과 닉네임들이 주어질 때, Q개의 팀에 대해 다음 리저널에서 수상할 수 있을지 전설에 기반해 알려주는 프로그램을 작성하자.

## 입력
 첫째 줄에는 색상의 종류 C와 닉네임의 개수 N이 주어진다. (1 ≤ C, N ≤ 4,000)

 다음 C개의 줄에는 색상 이름 C개가 한 줄에 하나씩 주어진다. 색상 이름은 중복되지 않는다.

 다음 N개의 줄에는 Sogang ICPC Team 구성원들의 닉네임 N개가 한 줄에 하나씩 주어진다. 닉네임도 중복되지 않는다.

 다음 줄에는 팀의 개수 Q가 주어진다. (1 ≤ Q ≤ 20,000)

 다음 Q개의 줄에는 팀명 Q개가 한 줄에 하나씩 주어진다. 팀명은 중복되지 않는다.

 모든 색상 이름의 길이와 닉네임의 길이는 1,000글자를 넘지 않는다. 모든 팀명은 2,000글자를 넘지 않는다. 모든 문자열은 알파벳 소문자로만 이루어져 있다.

## 출력
 팀명이 입력된 순서대로, 전설에 따라 해당 팀이 다음 리저널에서 수상할 수 있다면 Yes, 아니라면 No를 출력한다.

## 내 풀이
 트라이 구조를 아는가? 트리형태로 문자열을 저장하여 접두사를 빠르게 찾아낼 수 있는 자료구조이다.
 좀더 표현하자면 글자 하나 하나씩 노드로 바꾸어 자신의 전 글자를 부모노드 삼아 이어나가는 트리 구조를 말한다.

 예를들어 전화번호 010-1234-5678, 010-1234-9876, 010-1248-1632가 있다고 할 때 위 전화번호는 공통적으로 010-12가 들어간다. 이 부분을 접두사라고 하는데 이것을 트리 형태로 표현하면

 <p align="center"><img width="20%" src="그림1.png" /></p>
 
 으로 표현 할 수 있다. 여기서 접두사 부분은 같은 노드를 가지게 되어 어떠한 단어가 다른 단어의 접두사인지를 빠르게 확인 할 수 있다.

 이 문제에서 나는 색깔을 트라이 형태로 저장하고 닉네임을 set에 저장하여 팀명에 색깔이 들어가는지(접두사인지) 빠르게 탐색을 하고 있을 경우 나머지를 set을 통해 닉네임에 있는지 없는지 확인을 하여 빠르게 탐색해 나아간다.

## 구현([전체 코드 파일](/baekjoon/19585전설/c.py))
``` python
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
```

## 잡담
 아... 3달만에 풀었다... 파이선 딕셔너리가 트라이 만들때 너무 편한듯.. c++의 map을 내가 아직 잘 못다루는 점도 있는거 같긴 하지만.. ㅎㅎ...