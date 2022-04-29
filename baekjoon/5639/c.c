#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node* left;
	struct node* right;
	int var;
}node;
typedef struct tree{
	node* root;
}tree;
node* makeNode(int var){
	node* tmp = (node*)malloc(sizeof(node));
	tmp->var = var;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}
void input(tree* n, int num){
	if(n->root==NULL){
		n->root=makeNode(num);
		return;
	}
	node* tmp = n->root;
	int flag;
	while(1){
		flag = num<tmp->var;
#ifndef BOJ
		printf("%d\n",flag);
#endif
		if(flag){
			if(tmp->left==NULL)
				break;
			tmp = tmp->left;
		}
		else{
			if(tmp->right==NULL)
				break;
			tmp = tmp->right;
		}
	}
	if(flag)
		tmp->left = makeNode(num);
	else
		tmp->right = makeNode(num);
}
void pr(node* n){
	if(n==NULL)
		return;
	pr(n->left);
	pr(n->right);
	printf("%d\n",n->var);
}
int main(){
	int num;
	tree t1 = {NULL};
	while(scanf("%d",&num)!=EOF){
		input(&t1,num);
#ifndef BOJ
		printf("%d@\n",num);
#endif
	}
	pr(t1.root);
	return 0;
}
