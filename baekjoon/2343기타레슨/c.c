#include<stdio.h>
#include<stdlib.h>

int solution(int N, int M, const int* arr);
int counting(int N, int M, const int* arr, int min);

int main(){
	int N,M;
	int arr[100001];
	scanf("%d%d",&N,&M);
	for(int i=0; i!=N;i++){
		scanf("%d",&arr[i]);
	}
	printf("%d",solution(N,M,arr));
	return 0;
}

int solution(int N, int M, const int* arr){
	int l, r, min;
	int flag;
	l = 0;
	r = 0;
	for(int i=0; i!=N; i++){
		r += arr[i];
	}
	
	while(l!=r){
		min = l+(r-l)/2;
		if(counting(N, M, arr, min)){
			r = min;
		}
		else{
			l = min+1;
		}
	}
	return l;
}
int counting(int N, int M, const int* arr, int min){
	for(int i=0, sum=0; i!=N;){
		if(sum+arr[i]<=min){
			sum += arr[i];
			i++;
		}
		else{
			sum = 0;
			M--;
			if(!M){
				return 0;
			}
		}
	}
	return 1;
}
