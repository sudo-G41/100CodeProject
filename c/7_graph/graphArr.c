#include"graphArr.h"
int** graphMakeArr(int size){
	int** arr = (int**)calloc(size, sizeof(int*));
	for(int i=0;i<size;i++){
		arr[i]=(int*)calloc(size, sizeof(int));
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
	int now = root;
	int* dijk = (int*)calloc(size,sizeof(int));
	int* flag = (int*)calloc(size,sizeof(int));
	for(int i=1;i<size;i++){
		flag[now] = 1;
		int min = root;
		for(int idx=0;idx<size;idx++){
			if(flag[idx]==0){
				if(dijk[idx]==0){
					dijk[idx] = arr[now][idx];
				}
				else if(arr[now][idx]>0){
					int tmp = dijk[idx]+arr[now][idx];
					if(arr[root][idx]==0){
						dijk[idx]+=arr[now][idx];
					}
					else if(tmp<arr[root][idx]){
						dijk[idx] = tmp;
					}
				}
				if(dijk[min]==0){
					min=idx;
				}
				else{
					min=dijk[idx]<dijk[min]?idx:min;
				}
			}
		}
		now = min;
	}
	return dijk;
}
