#include"graphArr.h"

void printTwoD(int** arr, int size);
void printList(int size, int* arr);

int main(){
	int** g = graphMakeArr(6);
	printf("정점 1,2 가중치 입력 \n");
	input(10,g);
	int* arr = dijkstraArr(6,g,0);
	printList(6,arr);
//	printTwoD(g, 6);
	return 0;
}
void printList(int size, int* arr){
	for(int i=0;i<size;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
void printTwoD(int** arr, int size){
	for(int i=0,j=0;i<size;j++){
		if(j<size){
			printf("%d ",arr[i][j]);
		}
		else{
			j=-1;
			i++;
			printf("\n");
		}
	}
}
