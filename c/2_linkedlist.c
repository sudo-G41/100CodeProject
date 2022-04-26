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
int delF(Head* h);
int delM(Head* h);
int delL(Head* h);
int searchI(Head* h);
int searchV(Head* h);
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
			n=0;
			switch(idx){
				case 1:
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
					if(h.size==0){
						printf("비어있습니다.\n");
						break;
					}
					while(1>n||n>3){
						printf("1.앞에\n2.중간\n3.뒤에\n선택하세요(Enter)_\b");
						scanf("%d",&n);
					}
					if(n==1){delF(&h);}
					else if(n==2){delM(&h);}
					else if(n==3){delL(&h);}
					h.size--;
					break;
				case 3:
					while(1>n||n>2){
						printf("1.Index에 위치한 값\n2.원소의 위치\n선택하세요(Enter)_\b");
						scanf("%d",&n);
					}
					if(n==1){
						printf("찾으신 Index에는 %d이/가 들어있습니다.\n",searchI(&h));
					}
					else if(n==2){
						int var = searchV(&h);
						if(var==-1)
							printf("없습니다.\n");
						else
							printf("%d번째에 있습니다.\n",var);
					}
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
	if(idx==0){
		node->next = h->node;
		h->node = node;
		return 0;
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
int delF(Head* h){
	Node* tmp = h->node;
	h->node = tmp->next;
	free(tmp);
	return 0;
}
int delM(Head* h){
	int n=0;
	Node* tmp = h->node;
	Node* ptr = NULL;
	if(h->size==1){
		h->node = tmp->next;
		free(tmp);
		return 0;
	}
	while(1>n||n>h->size){
		printf("몇번째 원소를 제거하시겠습니까?(1~%d) : ",h->size);
		scanf("%d",&n);
	}
	if(n==1){
		h->node = tmp->next;
		free(tmp);
	}
	else{
		for(int i=1; i<n; i++){
			ptr = tmp;
			tmp = tmp->next;
		}
		ptr->next = tmp->next;
		free(tmp);
	}
	return 0;
}	
int delL(Head* h){
	Node* tmp;
	tmp = h->node;
	if(h->size==1){
		h->node = NULL;
		free(tmp);
	}
	else{
		while(tmp->next->next!=NULL)
			tmp = tmp->next;
		free(tmp->next);
		tmp->next = NULL;
	}
	return 0;
}
int searchI(Head* h){
	int idx = 0;
	Node* tmp = h->node;
	while(idx<1||h->size<idx){
		printf("Index번호를 입력해 주세요(1~%d) : ", h->size);
		scanf("%d",&idx);
	}
	for(int i=1; i<idx; i++)
		tmp = tmp->next;
	return tmp->var;
}
int searchV(Head* h){
	int var, idx=1;
	Node* tmp = h->node;
	printf("찾으실 값을 입력해 주세요 : ");
	scanf("%d",&var);
	while(tmp!=NULL){
		if(tmp->var==var)
			return idx;
		tmp = tmp->next;
	}
	return -1;
}
