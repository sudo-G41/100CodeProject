#include<iostream>
#include<set>

int main(){
	int N, num;
	std::multiset<int> list;
	scanf("%d",&N);
	list.insert(10001);
	list.insert(-10001);
	auto it = list.begin();
	while(N--){
		scanf("%d",&num);
		list.insert(num);
		if(list.size()%2){
			if(*it<=num){
				++it;
			}
		}
		else{
			if(*it>num){
				--it;
			}
		}
		printf("%d\n", *it);
	}
	return 0;
}