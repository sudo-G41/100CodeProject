#include<iostream>

long long up(long long A);
long long down(long long A);

int main(){
	long long A;
	scanf("%lld",&A);
	printf("%lld %lld",down(A),up(A));
	return 0;
}

long long up(long long A){
	long long a = A;
	long long shift, add;
	shift = 0;
	add = 0;
	bool flag = true;
	while(true){
		if(add){
			if(!(a%2))
				return ((a+1)<<shift)+add-1;
			else
				add *= 2;
		}
		else{
			add = a%2;
		}
		a /= 2;
		shift+=1;
	}
	return -1;
}
long long down(long long A){
	//if(!((A+1)&A)){return 0;}도 가능
	long long a = (A+1)^A;
	if(a>A)
		return 0;
	long long b = A-(a>>1);
	long long c = ((A^(A-a))+1)>>2;
	long long d = (a+1)>>1;
	return b-(c/d);
}

