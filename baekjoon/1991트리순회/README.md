# 백준[1991](https://www.acmicpc.net/problem/1991)번
## 문제
 이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.

 예를 들어 이진 트리가 입력되면,

* 전위 순회한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)
* 중위 순회한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)
* 후위 순회한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)

가 된다.

## 입력
 첫째 줄에는 이진 트리의 노드의 개수 N(1 ≤ N ≤ 26)이 주어진다. 둘째 줄부터 N개의 줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다. 노드의 이름은 A부터 차례대로 알파벳 대문자로 매겨지며, 항상 A가 루트 노드가 된다. 자식 노드가 없는 경우에는 .으로 표현한다.

## 출력
 첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 셋째 줄에 후위 순회한 결과를 출력한다. 각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.

## 내 풀이
 트리의 순화는 한국어 번역을 참 잘한거 같다. 트리만 그릴 줄 안다면 전위탐색은 먼저 출력하고 위에 주어진대로 왼쪽 오른쪽을, 중위는 왼쪽 출력 오른쪽, 후위는 왼쪽 오른쪽 출력 느낌으로만 만들어 주면 되기 때문에 재귀를 이용해서 탐색하는 함수만 만들어 주면 된다.

 그래서 이진트리를 어떻게 구현하냐가 중요한데 나는 여기서 python이 순수객체지향언어라는 점을 이용하여 구현하였다.

 어떠한 부분을 이용하였냐면 같은 dict안에 있는 서로 다른 두 dict인 A,B가 있을때 A가 B를 안에 포함하면 이는 A가 B를 가지는 것이 아닌 A는 B의 주소를 가지고 그곳을 가리키게 만드는 점이다.

 그래서 tree라는 dict안에 모든 node를 만들고 서로 왼쪽 오른쪽을 각각 가리키게 하여 루트부터 트리를 작성하게되면 모든 노드에 대한 트리 or 서브트리가 저장된 dict가 완성된다.

## 구현([전체 코드 파일](/baekjoon/1991트리순회/c.py))
``` python
def preorder(tree):
	if tree:
		print(tree["node"],end="")
		preorder(tree["L"])
		preorder(tree["R"])

def inorder(tree):
	if tree:
		inorder(tree["L"])
		print(tree["node"],end="")
		inorder(tree["R"])

def postorder(tree):
	if tree:
		postorder(tree["L"])
		postorder(tree["R"])
		print(tree["node"],end="")

def make_tree():
	N = int(input())
	tree = {}
	for _ in range(N):
		node, l, r = input().strip().split()
		if node not in tree:
			tree[node] = {"node":node}
		if l != '.':
			if l not in tree:
				tree[l] = {"node":l}
			tree[node]["L"] = tree[l]
		else:
			tree[node]["L"] = {}
		if r != '.':
			if r not in tree:
				tree[r] = {"node":r}
			tree[node]["R"] = tree[r]
		else:
			tree[node]["R"] = {}

	return tree
```

## 잡담
 뭐.. 사실 이런건 class로 만들어야 한다는데 dict를 class처럼 사용할 수 있으니 이렇....ㅎㅎ... 꼼수라는 것이다...