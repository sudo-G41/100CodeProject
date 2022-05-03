#include<limits.h>
#include"graphArr.h"

int** graphMakeArr(int size){
	int** arr = (int**)calloc(size, sizeof(int*));
	for(int i=0;i<size;i++){
		arr[i]=(int*)malloc(size*sizeof(int));
		for(int j = 0;j<size;j++)
			arr[i][j] = INT_MAX/2;
	}
	return arr;
}
void input(int size, int** arr){
	for(int i=0;i<size;i++){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		arr[x][y]=w;
		arr[y][x]=w;
	}
}
int* dijkstraArr(int size, int** arr, int root){
	int* d = (int*)malloc(size*sizeof(int));
	int* flag = (int*)calloc(size,sizeof(int));
	memcpy(d,arr[root],size*sizeof(int));
	int idx;
	int now = root;
	int min = now;
	flag[root] = 1;
	for(int i=0;i<size;i++){
		idx = 0;
		min = root;
		while(idx<size){
			if(flag[idx]<1){
				if(d[idx]>d[now]+arr[now][idx]){
					d[idx] = d[now]+arr[now][idx];
				}
				min = d[min]<d[idx]?min:idx;
			}
			idx++;
		}
		flag[min] = 1;
		now = min;
	}
	d[root]=0;
	return d;
}
