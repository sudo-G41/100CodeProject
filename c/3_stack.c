#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	struct Node* next;
	int var;
}node;
typedef struct Head{
	node* top;
	int size;
}head;
int pop(head* h);
void push(head* h);
void print(head* h);
void peek(head* h);
int main(){
	head h = {NULL,0};
	int idx=0;
	while(idx!=5){
		printf("1.push\n2.pop\n3.top is?\n4.print\n5.exit\nnumber? _\b");
		scanf("%d",&idx);
		if(idx==1)
			push(&h);
		else if(idx==2)
			printf("%d is pop...?\n",pop(&h));
		else if(idx==3)
			peek(&h);
		else if(idx==4)
			print(&h);
		else if(idx==5)
			break;
		else
			printf("please input 1 to 5...\n");
	}
	return 0;
}
int pop(head* h){
	if(h->size==0){
		printf("Is empty\n");
		return -1;
	}
	node* tmp = h->top;
	int var = tmp->var;
	h->top = tmp->next;
	free(tmp);
	h->size--;
	return var;
}
void push(head* h){
	node* tmp = (node*)malloc(sizeof(node));
	tmp->next = h->top;
	printf("input item : ");
	scanf("%d",&tmp->var);
	h->top = tmp;
	h->size++;
}
void print(head* h){
	node* tmp = h->top;
	printf("stack\n=======\n");
	while(tmp!=NULL){
		printf("%5d\n",tmp->var);
		tmp = tmp->next;
	}
	printf("=======\n");
}
void peek(head* h){
	h->size>0?printf("top is %d\n",h->top->var):printf("Is empty\n");
}
