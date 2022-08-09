from sys import stdin

input = stdin.readline
def solution():
    h,w = map(int, input().strip().split())
    if(w == 0):
        print(0)
        return
    b = []
    hdict = {}
    for idx, hmax in enumerate(list(map(int, input().strip().split()))):
        b.append([0 if hmax <= nowh else 1 for nowh in range(h)])
        if(hmax in hdict):
            hdict[hmax].append(idx)
        else:
            hdict[hmax] = [idx]
    hdict = sorted(hdict.items(), reverse = True)
    l,r = w,-1
    count = 0
    sum = 0
    add = 0
    for idx, dic in enumerate(hdict):
        if(idx == len(hdict)-1):
            break
        l, r = min(l,dic[1][0]), max(r,dic[1][-1])
        count += len(dic[1])
        if(l!=r):
            add = r-l-count+1
            sum += add*(dic[0] - hdict[idx+1][0])
    #         print("sum",sum,"count",count,"add",add,"h",dic[0],"lr",r-l)
    # print("answer",sum)
    print(sum)

if __name__ == "__main__":
    for _ in range(int(input().strip())):
        solution()