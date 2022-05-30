#include<iostream>

int solution(int A, int B);
int main(){
	int a,b;
	std::cin>> a>> b;
	std::cout<<solution(a,b);
	return 0;
}
int solution(int a, int b){
	bool flag=true;
	int tmp = 1;
	while(a<b){
		if(flag){
			a*=2;
			flag=false;
		}
		else{
			a=10*a+1;
			flag=true;
		}
		tmp++;
	}
	return a==b?tmp:-1;
}
