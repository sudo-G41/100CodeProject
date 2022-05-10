from sys import stdin
n, m = list(map(int,stdin.readline().strip().split()))
l = list(map(int,stdin.readline().strip().split()))
ll=[]
lst=[]
def a(l:list, max:int, lst:list, ll:list):
    if len(ll)<max:
        for i in l:
            if i not in ll:
                lll=[v for v in ll]
                lll.append(i)
                a(l,max,lst,lll)
    else:
        lst.append(ll)
a(l,m,lst,ll)
lst.sort()
for i in lst:
    print(" ".join(list(map(str,i))))