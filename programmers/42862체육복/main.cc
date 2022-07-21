#include"solution/solution.hh"

int main(){
	std::vector<std::vector<int>> list1 = {{2,4}, {1,3,5}};
	std::vector<std::vector<int>> list2 = {{2,4},{3}};
	std::vector<std::vector<int>> list3 = {{3},{1}};
	std::vector<std::vector<int>> list4 = {{1,3}, {2,4}};
	std::cout<<solution(5, list1[0], list1[1])<<'\n';
	std::cout<<solution(5, list2[0], list2[1])<<'\n';
	std::cout<<solution(3, list3[0], list3[1])<<'\n';
	std::cout<<solution(4, list4[0], list4[1])<<'\n';
	return 0;
}
//int n, vector<int> lost, vector<int> reserve
/*
5 	[2, 4] 	[1, 3, 5] 	5
5 	[2, 4] 	[3] 	4
3 	[3] 	[1] 	2
*/