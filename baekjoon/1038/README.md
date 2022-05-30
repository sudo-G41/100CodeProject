# 백준[1038](https://www.acmicpc.net/problem/1038)번
## 문제
음이 아닌 정수 X의 자릿수가 가장 큰 자릿수부터 작은 자릿수까지 감소한다면, 그 수를 감소하는 수라고 한다. 예를 들어, 321과 950은 감소하는 수지만, 322와 958은 아니다. N번째 감소하는 수를 출력하는 프로그램을 작성하시오. 0은 0번째 감소하는 수이고, 1은 1번째 감소하는 수이다. 만약 N번째 감소하는 수가 없다면 -1을 출력한다.

## 입력
첫째 줄에 N이 주어진다. N은 1,000,000보다 작거나 같은 자연수 또는 0이다.

## 출력
첫째 줄에 N번째 감소하는 수를 출력한다.

## 내 풀이
감소하는 수가 없다면 <= 감소하는 수의 최대치가 있다 생각하고 어떤 수 인가 생각해보니 `9876543210`이 최대일 것이며 이걸 기준으로 생각해 보자.  
10자리 숫자 : 9876543210  
9자리 숫자 : 987654321, 976543210, ...  
8자리 숫자 : 98765432, 97654321, 97654320, ...  
7자리 숫자 : 9876543, 9765432, ...  
뭔가 보인다.  
7자리 숫자를 하나씩 쪼개서 배열로 만들어 보면 [9,8,7,6,5,4,3]이 될 것이다. 이것을 봤을때 (배열 마지막 수-1) 부터 0까지를 뒤에 추가해주면 그 다음 자리 수를 만들 수 있다.  
이 점을 이용하여 재귀를 통해 감소하는 수를 나타내는 배열들을 만들 수 있들 것이다.  
이를 맨 앞 숫자(인덱스 0번을) 기준으로 정렬하고, 길이 기준으로 정렬하면 감소하는 수를 오름차순으로 정렬하게 되고 인덱스 번호 = 해당 번째 감소하는 수가 되어 해당 배열을 join시켜서 출력하면 된다.

## 구현([전체 코드 파일](/baekjoon/1038/c.py))
``` python
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
```

## 잡담
사실 정렬을 기수정렬 아이디어 가져다가 하면 좀더 빠르게 할 수 있겠지만 귀찮아서 sort써서 했다. 그래도 nlogn이상의 속도를 가지게 만들었을텐데 첫 배열을 만들때 걸리는 시간만 주의하면 문제 없을거란 판단하에 sort를 두번 사용하는것을 채택했고 실제 통과도 했다. 72ms라는 속도로... 생각보다 빨라서 놀랐다.  
그리고 어떤 c로 푼 유저는 감소하는 숫자를 모은 배열을 하드코딩해서 재출했다... 너무 내 취향이다. ㅎㅎ11660에서 처럼 불편해야 하는데 뭔가 이런건 너무 내 취향이다...   
그 외에도 다슨 사람들의 코드를 보면 내 방법 말고도 감소하는 수의 배열을 만드는 방법이 더 있는것 같다. 이런점이 코딩의 묘미인거 같다.  
마지막으로 오늘 올린 두 문제는 몇일 전에 풀어둔거긴 한데 테블릿으로 풀어서 지금에서야 올리게 된다. 그리고 이 두 문제를 풀게된 계기는 어둠의 듀얼(듀얼에서 진사람 판당 상대가 정해준 문제 하나 풀기)에서 두판 져서 그렇다... 그런걸 왜 하냐고? 모르겠음 듀얼을 통해 알려주지! 듀얼이다!!