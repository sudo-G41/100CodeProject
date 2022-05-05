# [후보키](https://programmers.co.kr/learn/courses/29/lessons/42890?language=python3)
## 문제설명
프렌즈대학교 컴퓨터공학과 조교인 제이지는 네오 학과장님의 지시로, 학생들의 인적사항을 정리하는 업무를 담당하게 되었다.

그의 학부 시절 프로그래밍 경험을 되살려, 모든 인적사항을 데이터베이스에 넣기로 하였고, 이를 위해 정리를 하던 중에 후보키(Candidate Key)에 대한 고민이 필요하게 되었다.

후보키에 대한 내용이 잘 기억나지 않던 제이지는, 정확한 내용을 파악하기 위해 데이터베이스 관련 서적을 확인하여 아래와 같은 내용을 확인하였다.

    관계 데이터베이스에서 릴레이션(Relation)의 튜플(Tuple)을 유일하게 식별할 수 있는 속성(Attribute) 또는 속성의 집합 중, 다음 두 성질을 만족하는 것을 후보 키(Candidate Key)라고 한다.
        * 유일성(uniqueness) : 릴레이션에 있는 모든 튜플에 대해 유일하게 식별되어야 한다.
        * 최소성(minimality) : 유일성을 가진 키를 구성하는 속성(Attribute) 중 하나라도 제외하는 경우 유일성이 깨지는 것을 의미한다. 즉, 릴레이션의 모든 튜플을 유일하게 식별하는 데 꼭 필요한 속성들로만 구성되어야 한다.

제이지를 위해, 아래와 같은 학생들의 인적사항이 주어졌을 때, 후보 키의 최대 개수를 구하라.

## 제한사항
* relation은 2차원 문자열 배열이다.
* relation의 컬럼(column)의 길이는 1 이상 8 이하이며, 각각의 컬럼은 릴레이션의 속성을 나타낸다.
* relation의 로우(row)의 길이는 1 이상 20 이하이며, 각각의 로우는 릴레이션의 튜플을 나타낸다.
* relation의 모든 문자열의 길이는 1 이상 8 이하이며, 알파벳 소문자와 숫자로만 이루어져 있다.
* relation의 모든 튜플은 유일하게 식별 가능하다.(즉, 중복되는 튜플은 없다.)

## 풀이
유일성은 릴레이션에 있는 튜플에 대해 유일하게 식별되야 하므로 중복이 없다. 그러므로 중복을 허용하지 않는 set(python 기준)에 튜플을 넣고 해당 set의 길이와 릴레이션의 길이가 같은지 확인하여 같으면 유일성을 만족한다 볼 수 있다.  
최소성은 이미 최소성을 만족하는 속성을 포함한 키는 최소성을 만족 할 수 없다는 점을 이용하여 속성이 적은 순서로 확인해가며 최소성을 보장하는 방식으로 풀었다.

make_index_list 함수는 이용하여 유일성을 확인하기 위한 인덱스 집합을 call-by-reference를 이용하여 만들어 준다. 이때 원소 길이를 기준으로 정령이 필요하다(solution함수의 sort(key=lambda x:len(x))가 길이순으로 정렬하는 역활을 한다).  
is_only_one 함수는 유일성을 검사하는 함수로 make_index_list 함수로 만들어진 인덱스 집합을 가져와서 해당 인덱스에 있는 속성을 묶은 집합을 만들어 해당 집합의 원소의 개수가 릴레이션의 길이와 같은지 확인하는 방법으로 유일성을 확인한다.  
is_minimal 함수는 이미 유일성 및 최소성을 만족하고 있는 인덱스를 포함하고 있는 집합인지 확인하여 최소성을 보장한다.

## 구현([전체 코드 파일](programmers/42890/Solution.py))
``` python
#solution
def solution(relation):
	index_list=[]
	candidate_Key_lsit=[]
	make_index_list(set(),index_list,0,len(relation[0]))
	index_list.sort(key=lambda x:len(x))
	for s in index_list:
		if is_only_one(s,relation):
			if is_minimal(candidate_Key_lsit, s):
				candidate_Key_lsit.append(s)
	answer = len(candidate_Key_lsit)

	return answer

#비교해야할 인덱스 리스트 만들기 비트 마스크에서 아이디어 좀 빌려옴
def make_index_list(s:set,l:list,start:int,size:int):
	for i in range(start,size):
		ss = s|set([i])
		l.append(ss)
		if i+1<size:
			make_index_list(ss,l,i+1,size)

#유일성 검사
def is_only_one(s:set,relation:list):
	s = set(["".join([r[i] for i in s]) for r in relation])
	return len(s)==len(relation)

#최소성 검사?
def is_minimal(l:list,s:set):
	for ss in l:
		if len(ss-s)==0:
			return False
	return True
```