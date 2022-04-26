#include<stdio.h>
#include<stdlib.h>
int main(){
	int* student = (int*)malloc(sizeof(int)*6);
	for(int i=0; i<6; i++){
		scanf("%d",&student[i]);
	}
	printf("학번\t국어\t영어\t수학\t총점\t평균\n");
	printf("**************************************\n");
	for(int i=0; i<6; i++){
		printf("%d\t",student[i]);
	}
	return 0;
}
