#include"solution/solution.hh"

int main(){
	std::vector<std::vector<int>> list1 = {{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}};
	std::vector<std::vector<int>> list2 = {{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,0},{0,0,0,0,1}};
	std::vector<std::vector<int>> list3 = {{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,0},{0,0,0,0,0}};
	std::vector<std::vector<int>> list4(100,std::vector<int>(100,1));
	list4[99][99] = 0;
	std::cout<<solution(list1)<<'\n';
	std::cout<<solution(list2)<<'\n';
	std::cout<<solution(list3)<<'\n';
	std::cout<<solution(list4)<<'\n';
	return 0;
}

