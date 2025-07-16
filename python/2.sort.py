from random import shuffle

arr = list(range(0,16))
shuffle(arr)

a1 = arr[:]
a2 = arr[:]
a3 = arr[:]
a4 = arr[:]
a5 = arr[:]

print("befor arr:", arr)

# 퀵 정렬
def q(p,l,r):
    if l > r:
        return
    _l, _r = l, r

    while _l <= _r:
        if a1[_l] >= a1[p]:
            _l += 1
        elif a1[p] >= a1[_r]:
            _r -= 1
        else:
            a1[_l], a1[_r] = a1[_r], a1[_l]
            _l, _r = _l+1, _r-1
    a1[p], a1[_r] = a1[_r], a1[p]
    _p = _r
    
    q(p, p+1, _p-1)
    q(_p+1, _p+2, r)

#병합정렬
#def me(ar):
#    global a2
#    def di(ar):
#        #print(ar)
#        if len(ar) != 1:
#            mi = len(ar)>>1
#            ar = me(di(ar[:mi]), di(ar[mi:]))
#        return ar
#    def me(le, ri):
#        ar = []
#        while le and ri:
#            ar.append(le.pop(0) if le[0] < ri[0] else ri.pop(0))
#        #print(ar,le,ri)
#        return ar + le + ri
#    a2 = di(ar)
# 병합정렬 함수 하나로 만들기
# me함수로 재귀하는 부분이 분할
# 반복문이 병합역활을 진행
# print부분 주석을 풀면 병합정렬이 진행 되는 과정을 볼 수 있다.
def me(ar):
    if len(ar) == 1:
        return ar
    mi = len(ar)>>1
    #print("분할:",ar,"→", ar[:mi], ar[mi:])
    le, ri = me(ar[:mi]), me(ar[mi:])
    ar = []
    #print("병합:",le, ri, end=" → ")
    while le and ri:
        ar.append(le.pop(0) if le[0] < ri[0] else ri.pop(0))
    #print(ar+le+ri)
    return ar + le + ri

#힙정렬(최소힙 사용)
def hea():
    global a3
    # 리스트를 최소힙 형태로 변경
    # 루트의 자식노드 부터 마지막 노드까지 자신의 위치로 이동시켜 최소 힙 형태가 되도록 함
    for par in range(1, len(a3)):
        chi = True
        while chi:
            chi = (par - 1)>>1
            if a3[par] < a3[chi]:
                a3[par], a3[chi] = a3[chi], a3[par]
            par = chi
    lea = len(a3) - 1
    while lea:
        #print(a3)
        a3[0], a3[lea] = a3[lea], a3[0]
        lea -= 1
        par = 0
        ch1 = (par<<1) + 1
        ch2 = ch1+1 if ch1<lea else ch1
        while ch2 <= lea:
            if a3[ch1] < a3[ch2]:
                if a3[ch1] < a3[par]:
                    a3[ch1], a3[par], par = a3[par], a3[ch1], ch1
                else:
                    break
            else:
                if a3[ch2] < a3[par]:
                    a3[ch2], a3[par], par = a3[par], a3[ch2], ch2
                else:
                    break
            ch1 = (par<<1) + 1
            ch2 = ch1+1 if ch1<lea else ch1

# 카운트 정렬
def coun():
    global a4
    arra = [0] * (max(a4)+1)
    for valu in a4:
        arra[valu] += 1
    a4 = []
    for inde, valu in enumerate(arra):
        a4 += ([inde] * valu)

# 기수정렬이라는 제가 좋아하는 정렬(성능 나쁨)입니다.
# 참고로 Big(o)는 O(kn)입니다. k는 가장 큰 숫자의 자릿수
# 빠른 척 느립니다. 해봤거든요
def radix():
    global a5
    lengt = len(str(max(a5)))
    a5 = [str(value).zfill(lengt) for value in a5]
    for place in range(lengt-1, -1, -1):
        dicti = {str(index):[] for index in range(10)}
        for value in a5:
            dicti[value[place]].append(value)
        array = []
        for digit in range(10-1,-1,-1):
            array += dicti[str(digit)]
    a5 = list(map(int,array))

q(0, 1, len(a1)-1)
a2 = me(a2)
hea()
coun()
radix()

print("after(quick):", a1)
print("after(merge):", a2)
print("after(min_h):", a3)
print("after(count):", a4)
print("after(radix):", a5)

# 여기는 merge sort C 로 짜던거 응용으로 만든 코드
#def so(le):
#    di(0,le)
#def di(le, ri):
#    if le == ri-1:
#        return
#    mi = le+((ri-le) >> 1)
#    # >>1 은 /2의 몫과 같은 효과가 있다.
#    # a+(b-a)/2 = (2a + b - a)/2 = (2a - a + b)/2 = (a+b)/2 이므로 a와 b 의 중간을 찾는 다른 표현법이므로 그냥 오른쪽과 왼쪽의 중간 인덱스 번호 찾기다. 이렇게 하는 이유는 c에서 자료형에 따른 오버플로우 발생을 막기 위한 태크닉으로 사실 파이선은 굳이 이렇게 할 필요 없이 (le+ri)//2하면 된다. C/C++를 꿈 꾸는 자가 있는지는 모르겠지만 그냥 이런 테크닉도 있다.
#    di(le, mi)
#    di(mi,ri)
#    me(le,mi,ri)
#
#def me(le, mi, ri):
#    global a2
#    _l, _r, ix = le, mi, le
#    ar = a2[:]
#    while _l != mi and _r != ri:
#        if a2[_l] <= a2[_r]:
#            ar[ix] = a2[_l]
#            _l += 1
#        else:
#            ar[ix] = a2[_r]
#            _r += 1
#        ix += 1
#
#    while _l != mi or _r != ri:
#        if _l != mi:
#            ar[ix] = a2[_l]
#            _l += 1
#        else:
#            ar[ix] = a2[_r]
#            _r += 1
#        ix += 1
#    a2 = ar
