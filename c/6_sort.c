#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define SIZE 10
void merge(int[]);
void radix(int[]);
void heap(int[]);

int main(){
	int arr[SIZE];
	srand(time(NULL));
	for(int i=0,j=0,num=rand()%100; i<SIZE;){
		if(j<i){
			if(num==arr[j]){
				j=0;
				num = rand()%100;
			}
			else{
				j++;
			}
		}
		else{
			arr[i] = num;
			num = rand()%100;
			i++;
			j=0;
		}
	}
	int arr1[SIZE],arr2[SIZE],arr3[SIZE];
	for(int i=0; i<SIZE; i++){
		printf("%d ",arr[i]);
		arr1[i] = arr2[i] = arr3[i] = arr[i];
	}
	printf("\n");
	merge(arr1);
	radix(arr2);
	return 0;
}
void combine(int arr[], int i, int j, int size){
	int cparr[SIZE];
	memcpy(cparr, arr, sizeof(cparr));
	for(int x=i, y=j, idx=i;x!=j||y!=size;idx++){
		if(x==j){
			arr[idx] = cparr[y++];
		}
		else if(y==size){
			arr[idx] = cparr[x++];
		}
		else{
			if(cparr[x]<cparr[y]){
				arr[idx] = cparr[x++];
			}
			else{
				arr[idx] = cparr[y++];
			}
		}
	}
}
void divide(int arr[], int a, int z){
	if(a+1>=z){
		return;
	}
	int size = (a+z);
	divide(arr,a,size/2);
	divide(arr,size/2,z);
	combine(arr,a,size/2,z);
}
void merge(int arr[]){
	divide(arr,0,SIZE);
	printf("Merge : ");
	for(int i=0; i<SIZE; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void radix(int arr[]){
	int a[10][10000];
	for(int i=0;i<10;i++)
		a[i][0]=1;
	for(int i=0,j=1;i<3;i++){
		for(int idx=0; idx<SIZE; idx++){
			int tmp = (arr[idx]/j)%10;
			a[tmp][a[tmp][0]++] = arr[idx];
		}
		for(int idx = 0, asdf=0;idx<10;idx++){
			for(int qwer=1;qwer<a[idx][0];qwer++)
				arr[asdf++]=a[idx][qwer];
			a[idx][0]=1;
		}
		j*=10;
	}
	printf("Radix : ");
	for(int i=0; i<SIZE; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void heap(int* arr);
