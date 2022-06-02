import sys
input = sys.stdin.readline

def solution(sound:str):
	duck_cnt = 0
	duck_list = {c:0 for c in "quack"}
	duck_idx = {"u":"q", "a":"u", "c":"a", "k":"c"}
	for c in sound:
		if c == "q":
			if duck_list["k"] == 0:
				duck_cnt += 1
			else:
				duck_list["k"] -= 1
			duck_list[c] += 1
		else:
			if duck_list[duck_idx[c]]>0:
				duck_list[c] += 1
				duck_list[duck_idx[c]] -= 1
			else:
				return -1
	for k,v in duck_list.items():
		if v>0:
			if k != "k":
				return -1
	return duck_cnt

if __name__ == "__main__":
	sound = input().strip()
	while sound:
		print(solution(sound))
		sound = input().strip()