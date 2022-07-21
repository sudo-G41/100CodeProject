#include"solution.hh"

int solution(int n, std::vector<int> lost, std::vector<int> reserve) {
    int answer = 0;
	std::vector<int> students(n+2, 1);
	for(auto idx = lost.begin(); idx != lost.end(); idx++){
		students[*idx]--;
	}
	for(auto idx = reserve.begin(); idx != reserve.end(); idx++){
		students[*idx]++;
	}
	students[0] = 0;
	students[++n] = 0;
	for(int id=1; id<n; id++){
		if(!students[id]){
			if(students[id-1]>1){
				students[id]++;
				students[id-1]--;
			}
			else if(students[id+1]>1){
				students[id]++;
				students[id+1]--;
			}
		}
		answer += students[id]? 1: 0;
	}
    return answer;
}