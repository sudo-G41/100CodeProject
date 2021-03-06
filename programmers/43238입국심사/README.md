# Programmers[Lv3 입국심사](https://programmers.co.kr/learn/courses/30/lessons/43238)
## 문제
 n명이 입국심사를 위해 줄을 서서 기다리고 있습니다. 각 입국심사대에 있는 심사관마다 심사하는데 걸리는 시간은 다릅니다.

처음에 모든 심사대는 비어있습니다. 한 심사대에서는 동시에 한 명만 심사를 할 수 있습니다. 가장 앞에 서 있는 사람은 비어 있는 심사대로 가서 심사를 받을 수 있습니다. 하지만 더 빨리 끝나는 심사대가 있으면 기다렸다가 그곳으로 가서 심사를 받을 수도 있습니다.

모든 사람이 심사를 받는데 걸리는 시간을 최소로 하고 싶습니다.

입국심사를 기다리는 사람 수 n, 각 심사관이 한 명을 심사하는데 걸리는 시간이 담긴 배열 times가 매개변수로 주어질 때, 모든 사람이 심사를 받는데 걸리는 시간의 최솟값을 return 하도록 solution 함수를 작성해주세요.

## 제한사항 
* 입국심사를 기다리는 사람은 1명 이상 1,000,000,000명 이하입니다.
* 각 심사관이 한 명을 심사하는데 걸리는 시간은 1분 이상 1,000,000,000분 이하입니다.
* 심사관은 1명 이상 100,000명 이하입니다.

## 내 풀이
 이 문제 백준에도 있어서 백준을 가서 분류를 좀 확인해봤다. 이분탐색과 매개변수 탐색으로 분류되어 있는데 매개변수 탐색을 처음 들어봐서 좀 찾아봤다.  
 대충 이야기 하자면 매개면수 탐색은 값 그대로가 아니라 특정 조건에 대해 계산을 하고 가능한 값인가 아닌가 그 사이를 탐색하는 느낌이였다.  
 그래서 여기서는 불가능한 최소값인 0과 가능한 최대값인 가장 오래 걸리는 심사관이 모든 사람을 심사하는 $n*MAX(Times)$를 이용하여 탐색을 해보았다.  
 이분탐색에 맞게 0과 $n$ x $MAX(Times)$의 중간값인 $mid$를 구하고 그 중간값을 $(Times)$의 모든 사람들과 나눈 몫을 구한다.   
 자 예를 들어 예제 1번처럼 7분 걸리는 심사관과 10분 걸리는 심사관이 있고 기다리는 사람들이 6명 있다 해보자  
 여기서 첫 $mid$는 30이고 그럼 30분 동안 7분 심사관은 4명을 10분 심사관은 3명을 확인할 수 있을 것이다. 즉 최대 7명을 심사 가능하다는 이야기가 되어 6명 모두를 심사 할 수 있는 시간이 되어 0과 30사이에 우리가 원하는 값이 있다는 것을 알 수 있다.  
 한번 더 해보면 0과 30 사이인 15가 되고 이동안 7분 심사관은 2명 10분 심사관은 1명이 가능하여 최대 3명밖에 못한다. 그러므로 15분과 30분 사이에 우리가 원하는 시간이 있다는 것을 알 수 있다. 이러한 탐색을 반복하여 이분 탐색을 진행 할 수 있고 탐색이 완료된다.

## 구현([전체 코드 파일](/programmers/43238%EC%9E%85%EA%B5%AD%EC%8B%AC%EC%82%AC/c.py))
``` python
def solution(n, times):
    answer = 0
    min_time = 0
    max_time = max(times)*n
    while(max_time!=min_time+1):
        mid = (min_time+max_time)//2
        wait = sum([mid//v for v in times])
        if(wait<n):
            min_time = mid
        else:
            max_time = mid
    return max_time
```

## 잡담
아 어렵다... 풀이 자체는 쉬운데 탐색 기준 찾는게 어려웠다... 다른 분들 대단하네..