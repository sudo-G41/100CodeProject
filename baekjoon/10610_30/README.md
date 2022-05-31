# 백준[11660](https://www.acmicpc.net/problem/10610)번
## 문제
 어느 날, 미르코는 우연히 길거리에서 양수 N을 보았다. 미르코는 30이란 수를 존경하기 때문에, 그는 길거리에서 찾은 수에 포함된 숫자들을 섞어 30의 배수가 되는 가장 큰 수를 만들고 싶어한다.

 미르코를 도와 그가 만들고 싶어하는 수를 계산하는 프로그램을 작성하라.

## 입력
 N을 입력받는다. N는 최대 10<sup>5</sup>개의 숫자로 구성되어 있으며, 0으로 시작하지 않는다.

## 출력
 미르코가 만들고 싶어하는 수가 존재한다면 그 수를 출력하라. 그 수가 존재하지 않는다면, -1을 출력하라.

## 내 풀이
 3의 배수는 참 특이한 특징을 지니고 있다. 모든 자릿수를 더하면 그것도 3의 배수이다. 즉 모든 숫자를 더한 값을 3으로 나눈 나머지가 0이면 3의 배수이다.

 10의 배수또한 특징이 있다. 10을 곱했기 때문에 일의자리가 '0'이다.

 위 두가지를 합치면 다 더한 숫자가 3의 배수이며 '0'이 한개 이상 들어 있으면 30의 배수를 만들 수 있다는 이야기가 된다는 것이다. '0'만 일의 자리에 하나 놓아주면 어떻게 조합해도 30의 배수란 의미는 앞에서부터 큰 수를 하나씩 놓다보면 결국 가장 큰 수가 들어온다는 이야기이다. 여기까지 이야기 하면 만들 수 있지 않을까?

## 구현([전체 코드 파일](/baekjoon/10610_30/c.py))
``` python
N = input().strip()
L = list(map(int,N))
S = set(L)
if sum(L)%3==0 and 0 in S:
  L.sort(reverse=True)
  print(''.join(list(map(str,L))))
else:
  print(-1)
```

## 잡담
 그렇다 3의 배수의 특징은 인상적이고 초등학생때인가? 중학생떄 한번 배운 그거라 안 잊혀진다.. ㅎㅎ
 10은 잠깐 생각해 봤는데 바로 떠올라서 두개 섞어서 잘 풀었다. ㅎㅎ