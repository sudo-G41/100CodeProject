#include<iostream>

bool prime(int i);

int main(){
	int i;
//	printf("# : _\b");
//	scanf("%d", &i);
//
//	printf("%d is %s\n",i,prime(i)? "prime!": "not prime...");
	i = 1;
	while(i!=10001){
		if(prime(i)){
			printf("%d\n",i);
		}
		i++;
	}
}

bool prime(int i){
	if(i<13){
		switch(i){
			//12 이하 소수
			case 2: case 3: case 5:
			case 7:	case 11:
				return true;
			default:
				return false;
		}
	}
	switch(i%10){
		case 1: case 3:
		case 7: case 9:
			switch(i%12){
				case 1: case 5:
				case 7: case 11:
					int n = 3;
					while(i>n*n){
						if(!(i%n)){return false;}
						n+=2;
					}
					return i != (n*n);
			}
	}
	return false;
}
