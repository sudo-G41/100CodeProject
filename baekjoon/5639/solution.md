# 백준 5639번
## 문제
이진 검색 트리는 다음과 같은 세 가지 조건을 만족하는 이진 트리이다.  
* 노드의 왼쪽 서브트리에 있는 모든 노드의 키는 노드의 키보다 작다.  
* 노드의 오른쪽 서브트리에 있는 모든 노드의 키는 노드의 키보다 크다.  
* 왼쪽, 오른쪽 서브트리도 이진 검색 트리이다.  
이때 이진 검색 트리를 전위 순회한 결과가 주어졌을 때, 이 트리를 후위 순회한 결과를 구하는 프로그램을 작성하시오.
## 입력
트리를 전위 순회한 결과가 주어진다. 노드에 들어있는 키의 값은 10<sup>6</sup>보다 작은 양의 정수이다. 모든 값은 한 줄에 하나씩 주어지며, 노드의 수는 10,000개 이하이다. 같은 키를 가지는 노드는 없다.
## 출력
입력으로 주어진 이진 검색 트리를 후위 순회한 결과를 한 줄에 하나씩 출력한다.

## 풀이
입력으로 전위 순회한 결과가 주어지므로 전위 순회에 맞춰서 트리를 작성해 주는데 이때 사용된 트리는 이진 검색트리이므로 루트부터 하나씩 비교하여 이진검색트리의 조건에 따라 비교하면서 리프노드를 추가하여 준다.  
예를 들어 50, 30, 24, 31 순으로 주어지면 50을 루트로 주고 그다음 노드인 30은 루트보다 작은 값을 가지므로 왼쪽에 추가 한다. 그리고 다음 노드인 24는 루트보다 작은 값을 가지므로 왼쪽에 추가 하는데 이때 이미 30이라는 노드가 있으므로 다시 30과 비교를 진행한다. 30보다 작은 값을 가지므로 30의 왼쪽을 확인 왼쪽에 노드가 없으므로 30 왼쪽에 추가를 진행한다. 마지막으로 31을 루트부터 시작하여 하나씩 비교하면서 추가를 진행한다.
# 구현([전체 코드 파일](/baekjoon/5639/c.c))
``` c
//Tree를 구현하기 위한 구조체와 root를 구현하기 위한 구조체
typedef struct node{
	struct node* left;
	struct node* right;
	int var;
}node;
typedef struct tree{
	node* root;
}tree;
//새로운 노드를 만들어 주는 함수(리프노드 생성)
node* makeNode(int var){
	node* tmp = (node*)malloc(sizeof(node));
	tmp->var = var;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}
//노드를 추가해주는 함수
void input(tree* n, int num){
	if(n->root==NULL){
		n->root=makeNode(num);
		return;
	}
	node* tmp = n->root;
	int flag;
	while(1){
		flag = num<tmp->var;
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
//후위 순회 출력 함수
void pr(node* n){
	if(n==NULL)
		return;
	pr(n->left);
	pr(n->right);
	printf("%d\n",n->var);
}
```

