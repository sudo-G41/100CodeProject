relation = [["100","ryan","music","2"],["200","apeach","math","2"],["300","tube","computer","3"],["400","con","computer","4"],["500","muzi","music","3"],["600","apeach","music","2"]]

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

print(solution(relation))
