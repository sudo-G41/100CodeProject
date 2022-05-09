from sys import stdin
def qwer(i:int, l:list, lst:list):
    for i in range(i,-1,-1):
        ll = [i for i in l]
        ll.append(str(i))
        lst.append(ll)
        if i>0:
            qwer(i-1,ll,lst)
l=[]
lst=[]
qwer(9,l,lst)
lst.sort()
lst.sort(key=lambda x : len(x))
idx = int(stdin.readline().strip())
if len(lst)<=idx:
    print(-1)
else:
    print("".join(lst[idx]))