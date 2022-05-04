#include"unionfind.h"

int find(unionfind* uf, int num){
	if(uf->root[num]==num){
		return num;
	}
	else{
		return uf->root[num] = find(uf,uf->root[num]);
	}
}
void unionSet(unionfind* uf, int x, int y){
	x = find(uf, x);
	y = find(uf, y);
	if(x==y)
		return;
	if(uf->rank[x]>uf->rank[y])
		uf->root[x] = y;
	else
		uf->root[y] = x;
	if(uf->rank[x]==uf->rank[y])
		uf->rank[x]++;
}
unionfind makeSet(){
	int size;
	printf("몇개의 원소를 가지실건가요? ");
	scanf("%d",&size);
	unionfind uf;
	uf.size = size;
	uf.root = (int*)malloc(size*sizeof(int));
	uf.rank = (int*)calloc(size,sizeof(int));
	for(int i=0;i<size;i++)
		uf.root[i] = i;
	return uf;
}
int isSameSet(unionfind* uf, int x, int y){
	if(find(uf,x)==find(uf,y))
		return 1;
	else
		return 0;
}
