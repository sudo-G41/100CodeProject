#include<stdio.h>
#include<stdlib.h>
typedef struct node{
       struct node* left;	
       struct node* right;
       int item;
       int level;
}node;
typedef struct tree{
	node* root;       
}tree;
node* makeNode(int item, node* l, node* r, int level){
	node* tmp = (node*)malloc(sizeof(node));
	tmp->item = item;
	tmp->left = l;
	tmp->right = r;
	tmp->level = level;
	return tmp;
}
//전위 우선 탐색
void preorder(node* n){
	if(n==NULL)
		return; 
	printf("%d->",n->item);
	preorder(n->left);
	preorder(n->right);
}
//중위 우선 탐색
void inorder(node* n){
	if(n==NULL)
		return;
	inorder(n->left);
	printf("%d->",n->item);
	inorder(n->right);
}
//후위 우선 탐색
void postorder(node* n){
	if(n==NULL)
		return;
	postorder(n->left);
	postorder(n->right);
	printf("%d->",n->item);
}
int main(){
	tree root = {makeNode(0,NULL,NULL,0)};
	root.root->left = makeNode(1,NULL,NULL,1);
	root.root->right = makeNode(2,NULL,NULL,1);
	root.root->left->left = makeNode(3,NULL,NULL,2);
	root.root->left->right = makeNode(4,NULL,NULL,2);
	root.root->right->left = makeNode(5,NULL,NULL,2);
	root.root->right->right = makeNode(6,NULL,NULL,2);
	root.root->left->left->left = makeNode(7,NULL,NULL,3);
	root.root->left->left->right = makeNode(8,NULL,NULL,3);
	root.root->left->right->left = makeNode(9,NULL,NULL,3);
	root.root->left->right->right = makeNode(10,NULL,NULL,3);
	root.root->right->left->left = makeNode(11,NULL,NULL,3);
	root.root->right->left->right = makeNode(12,NULL,NULL,3);
	root.root->right->right->left = makeNode(13,NULL,NULL,3);
	root.root->right->right->right = makeNode(14,NULL,NULL,3);
	preorder(root.root);
	printf("\n");
	inorder(root.root);
	printf("\n");
	postorder(root.root);
	printf("\n");
	return 0;
}
