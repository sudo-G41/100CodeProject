#include<stdio.h>
#include<stdlib.h>
int dan(){
	int size;
	printf("노드의 개수를 입력해 주세요. : ");
	scanf("%d",&size);
	//graph[i][j] => i->j를 가리킴
	int** graph = (int**)malloc(size*sizeof(int*));
	for(int i=0; i<size; i++)
		graph[i] = (int*)calloc(size, sizeof(int));
	int edgeCount = 0;
	printf("간선의 개수를 입력해 주세요 : ");
	scanf("%d",&edgeCount);
	for(int i=0; i<edgeCount; i++){
		int a,b,w;
		printf("두 정점 a,b와 가중치 w를 입력해 주세요(a->b방향) : ");
		scanf("%d%d%d",&a,&b,&w);
		graph[a][b]=w;
	}
	printf("  |");
	for(int i=0; i<size; i++)
		printf("%3d ",i);
	printf("\n-------------------------------\n");
	for(int i=0,j=0;i<size;j++){
		if(j==0){printf("%2d|",i);}
		if(j<size){
			printf("%3d ",graph[i][j]);
		}
		else{
			i++;
			j=-1;
			printf("\n");
		}
	}
	return 0;
}
int yang(){
	int size;
	printf("노드의 개수를 입력해 주세요. : ");
	scanf("%d",&size);
	char ch;
	//graph[i][j] => i->j를 가리킴
	int** graph = (int**)malloc(size*sizeof(int*));
	for(int i=0; i<size; i++)
		graph[i] = (int*)calloc(size, sizeof(int));
	int edgeCount = 0;
	printf("간선의 개수를 입력해 주세요 : ");
	scanf("%d",&edgeCount);
	for(int i=0; i<edgeCount; i++){
		char a,b;
		int w;
		printf("두 정점 a,b와 가중치 w를 입력해 주세요 : ");
		scanf(" %c%c%d",&a,&b,&w);
		printf("|%c|%c|%d|\n",a,b,w);
		graph[a-'A'][b-'A']=graph[b-'A'][a-'A']=w;
	}
	printf("  |");
	for(int i=0; i<size; i++)
		printf("%3c ",'A'+i);
	printf("\n-------------------------------\n");
	for(int i=0,j=0;i<size;j++){
		if(j==0){printf("%2c|",'A'+i);}
		if(j<size){
			printf("%3d ",graph[i][j]);
		}
		else{
			i++;
			j=-1;
			printf("\n");
		}
	}
	return 0;
}
int main(){
	yang();
	return 0;
}
