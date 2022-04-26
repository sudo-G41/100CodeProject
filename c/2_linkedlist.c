#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node* next;
	int var;
} Node;
typedef struct head{
	Node* node;
	int size;
} Head;
int pushF(Head* h);
int pushM(Head* h);
int pushL(Head* h);
int main(){
	Head h = {NULL,0};
	int idx = '0';
	int n=0;
	while(idx!=4){
		printf("1.삽입\n2.삭제\n3.탐색\n4.종료\n선택하세요(Enter): _\b");
		scanf("%d",&idx);
		if(1>idx || idx>4){
			printf("잘못된 값입니다.\n");
		}
		else{
			switch(idx){
				case 1:
					n=0;
					while(1>n||n>3){
						printf("1.앞에\n2.중간\n3.뒤에\n선택하세요(Enter)_\b");
						scanf("%d",&n);
					}
					if(n==1){pushF(&h);}
					else if(n==2){pushM(&h);}
					else if(n==3){pushL(&h);}
					h.size++;
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
			}
			for(Node* tmp = h.node; tmp!=NULL; tmp=tmp->next){
				printf("%d->",tmp->var);
			}
			printf("\b\b\t\n");
		}
	}
	return 0;
}
int pushF(Head* h){
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = h->node;
	scanf("%d",&(node->var));
	printf("삽입할 값을 입력해 주세요 : ");
	h->node = node;
	return 0;
}
int pushM(Head* h){
	int idx = 0;
	Node* node = (Node*)malloc(sizeof(Node));
	Node* tmp = h->node;
	printf("삽입할 값을 입력해 주세요 : ");
	scanf("%d",&node->var);
	if(h->size==0){
		h->node = node;
		node->next = NULL;
		return 0;
	}
	printf("삽입할 위치를 입력해 주세요 : ");
	scanf("%d",&idx);
	while(idx>h->size){
		printf("너무 큽니다. 다시입력해 주세요 : ");
		scanf("%d",&idx);
	}
	for(int i=1; i<idx; i++){
		tmp = tmp->next;
	}
	node->next = tmp->next;
	tmp->next = node;
	return 0;
}
int pushL(Head* h){
	int n=0;
	Node* node = (Node*)malloc(sizeof(Node));
	Node* tmp = h->node;
	printf("삽입할 값을 입력해 주세요 : ");
	scanf("%d",&node->var);
	node->next = NULL;
	if(h->size==0){
		h->node = node;
		return 0;
	}
	while(tmp->next!=NULL){
		tmp=tmp->next;
	}
	tmp->next = node;
	return 0;
}
