# 백준[번호](https://www.acmicpc.net/problem/2606)번
## 문제
신종 바이러스인 웜 바이러스는 네트워크를 통해 전파된다. 한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서 연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다.

![그림 1](https://www.acmicpc.net/upload/images/zmMEZZ8ioN6rhCdHmcIT4a7.png)

예를 들어 7대의 컴퓨터가 <그림 1>과 같이 네트워크 상에서 연결되어 있다고 하자. 1번 컴퓨터가 웜 바이러스에 걸리면 웜 바이러스는 2번과 5번 컴퓨터를 거쳐 3번과 6번 컴퓨터까지 전파되어 2, 3, 5, 6 네 대의 컴퓨터는 웜 바이러스에 걸리게 된다. 하지만 4번과 7번 컴퓨터는 1번 컴퓨터와 네트워크상에서 연결되어 있지 않기 때문에 영향을 받지 않는다.

어느 날 1번 컴퓨터가 웜 바이러스에 걸렸다. 컴퓨터의 수와 네트워크 상에서 서로 연결되어 있는 정보가 주어질 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성하시오.

## 입력
 첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다. 둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. 이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.

## 출력
 1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.

## 내 풀이
 네트워크상에 연결된 컴퓨터를 집합으로 묶었을때 같은 1번 컴퓨터와 같은 집합에 있는 컴퓨터들은 바이러스에 감염이 된다.

그래서 같은 집합에 속하는지 확인을 위해 union-find를 사용하여 같은 루트를가지고 있는지 확인하여 1번과 같은 루트노드를 가지고 있는 원소의 개수 출력한다.

## 구현([전체 코드 파일](/baekjoon/2606%EB%B0%94%EC%9D%B4%EB%9F%AC%EC%8A%A4/c.py))
``` python
#union find를 사용하기 위한 부모노드 리스트와 레벨리스트(트리의 레벨)
comRoot = [i for i in range(N+1)]
comLevel = [0 for _ in range(N+1)]

#부모노드를 찾아가는 함수 루트노드는 자기 자신을 부모로 가진다.
def find(comRoot:list, a:int):
    if comRoot[a] == a:
        return a
    comRoot[a] = find(comRoot, comRoot[a])
    return comRoot[a]
#두 노드를 합치는 함수 노드가 같은 부모를 가졌는지 확인하고 다르면
#부모 노드를 반대쪽 노드의 부모노드로 기리키게 만든다.
#예를 들어 A, B노드가 있고 각각 A는 a를, B는 b를 부모로 가진다 하면
#A가 가리키는 부모노드를 B가 가리키는 b로 바꾸어 같은 부모노드를 가리키게 만든다.
def union(comRoot:list, comLevel:list, a:int, b:int):
    A = find(comRoot, a)
    B = find(comRoot, b)
    if A!=B:
        if comRoot[A]<comRoot[B]:
            comRoot[B] = A
        else:
            comRoot[A] = B
            if comLevel[A]<comLevel[B]:
                comLevel[A]+=1
# 메인 실행
if __name__ == "__main__":
    for _ in range(M):
        com1, com2 = map(int,input().strip().split(" "))
        union(comRoot, comLevel, com1, com2)
    sum = 0
    for i in range(2,N+1):
        sum += 1 if find(comRoot, i) == 1 else 0
    print(sum)
```

## 잡담
 알고리즘 스터디에서 풀었습니다. 유니온 파인드 문제 오랜만이라 재미있었습니다.