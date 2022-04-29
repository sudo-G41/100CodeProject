from sys import stdin
import copy
def draw():
    graph = {}
    s = stdin.readline().strip()
    while s != "":
        a,b = s.split(" ")
        if a in graph:
            graph[a].append(b)
        else:
            graph[a] = [b]
        if b in graph:
            graph[b].append(a)
        else:
            graph[b] = [a]
        s = stdin.readline().strip()
    return graph
g = draw()
print("graph : ",g)
def DFS(g : dict):
    #root = input("root? _\b")
    root = 'A'
    ans = [root]
    stack = [root]
    s = set()
    s.add(root)
    size = len(g)
    tmp = g[root].pop(0)
    while len(s)<size:
        if tmp not in s:
            root = tmp
            s.add(root)
            stack.append(root)
            ans.append(root)
        if len(g[root])>0:
            tmp = g[root].pop(0)
        else:
            root = stack.pop()
    print("DFS : ",ans)
DFS(copy.deepcopy(g))
def BFS(g : dict):
    #root = input("root? _\b")
    root='A'
    ans = [root]
    queue = [root]
    s = set(queue)
    size = len(g)
    while len(s)<size:
        if len(g[root])>0:
            tmp = g[root].pop(0)
            if tmp not in s:
                queue.append(tmp)
                ans.append(tmp)
                s.add(tmp)
        else:
            root = queue.pop(0)
    print("BFS : ",ans)
BFS(g)
