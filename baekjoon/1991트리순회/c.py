from sys import stdin
input = stdin.readline

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

tree = make_tree()
#print(tree)
#print(tree["A"]["L"])
preorder(tree["A"])
print()
inorder(tree["A"])
print()
postorder(tree["A"])
