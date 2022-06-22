#include<iostream>
#include<vector>
#include<stack>

std::vector<int> sendLaser(int);
void printVector(std::vector<int> v);

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N;
	std::cin>>N;
	std::vector<int> laser = sendLaser(N);
	printVector(laser);
	return 0;
}

std::vector<int> sendLaser(int N){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::vector<int> laser(N);
	for(int i=0;i<N;i++)
		std::cin>>laser[i];

	std::stack<int> s;
	std::vector<int> result(N,0);
	int idx=N-1;
	while(idx>-1){
		if(s.empty()){
			s.push(idx--);
		}
		else if(laser[s.top()]>laser[idx]){
			s.push(idx--);
		}
		else{
			result[s.top()] = idx+1;
			s.pop();
		}
	}
	return result;
}

void printVector(std::vector<int> v){
	for(auto it=v.begin(); it!=v.end();it++)
		std::cout<<*it<<' ';
}
