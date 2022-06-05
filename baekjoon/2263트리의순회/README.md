# 백준[2263](https://www.acmicpc.net/problem/2263)번
## 문제
 n개의 정점을 갖는 이진 트리의 정점에 1부터 n까지의 번호가 중복 없이 매겨져 있다. 이와 같은 이진 트리의 인오더와 포스트오더가 주어졌을 때, 프리오더를 구하는 프로그램을 작성하시오.

## 입력
 첫째 줄에 n(1 ≤ n ≤ 100,000)이 주어진다. 다음 줄에는 인오더를 나타내는 n개의 자연수가 주어지고, 그 다음 줄에는 같은 식으로 포스트오더가 주어진다.

## 출력
 첫째 줄에 프리오더를 출력한다.

## 내 풀이
 포스트오더를 보면 뒤쪽부터 루트로 해서 점점 내려오는걸 볼 수 있고 인오더는 자신을 기준으로 왼쪽 서브트리의 원소들은 왼쪽에 오른쪽 서브트리는 오른쪽에 있는 것을 볼 수 있다.

 이 두가지를 이용하여 다시 트리를 만들고 그 트리를 프리오더로 출력하는 방법을 사용하여 풀었다.

## 구현([전체 코드 파일](/baekjoon/2263트리의순회/c.cc))
``` c++
typedef std::vector<int> VI;

class Node{
public:
	int value;
	Node(int, int, int, Node*, Node*);
	void connect(Node*, bool);
	int getStart();
	int getEnd();
	Node* getRigth();
	Node* getLeft();
	bool haveRigth();
	bool haveLeft();
	bool operator<(const Node& node) const{
		return this->value<node.value;
	}
	~Node(){
		if(this->right)
			delete this->right;
		if(this->left)
			delete this->left;
	}
private:
	Node* right;
	Node* left;
	int startIdx, endIdx;
};

Node::Node(int value, int start, int end, Node* right=NULL, Node* left=NULL){
	this->value = value;
	this->startIdx = start;
	this->endIdx = end;
	this->right = right;
	this->left = left;
}

void Node::connect(Node* child, bool isRight=true){
	if(isRight){
		this->right = child;
	}
	else{
		this->left = child;
	}
}

Node* makeTree(VI idxHashTable, VI inOrder, VI postOrder);
VI makeHashTable(VI inOrder);
void freeOrder(Node* root);

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N;
	std::cin>> N;
	VI inOrder(N);
	VI postOrder(N);
	for(int i=0; i<N; i++){
		std::cin>> inOrder[i];
	}
	for(int i=0; i<N; i++){
		std::cin>> postOrder[i];
	}
	VI idxHashTable = makeHashTable(inOrder);
	freeOrder(makeTree(idxHashTable,inOrder,postOrder));
    return 0;
}

Node* makeTree(VI idxHashTable, VI inOrder, VI postOrder){
	auto node = postOrder.rbegin();
	std::stack<Node*> nodeStack;
	Node* root = new Node(*node,0,postOrder.size());
	nodeStack.push(root);
	++node;
	while(node!=postOrder.rend()){
		int idx = idxHashTable[*node];
		Node* parent = nodeStack.top();
		if(parent->getStart()<=idx && idx<parent->getEnd()){
			int parentIdx = idxHashTable[parent->value];
			if(idx>parentIdx){
				nodeStack.push(new Node(*node,parentIdx+1,parent->getEnd()));
			}
			else{
				nodeStack.push(new Node(*node,parent->getStart(),parentIdx));
			}
			++node;
		}
		else{
			while(true){
				Node* child = parent;
				nodeStack.pop();
				parent = nodeStack.top();
				parent->connect(child,idxHashTable[parent->value]<idxHashTable[child->value]);
				if(parent->getStart()<=idx && idx<parent->getEnd()){
					break;
				}
			}
		}
	}
	
	for(auto parent = nodeStack.top(),child = nodeStack.top(); nodeStack.size()>1; child = parent){
		nodeStack.pop();
		parent = nodeStack.top();
		parent->connect(child,idxHashTable[parent->value]<idxHashTable[child->value]);
	}
	return root;
}

VI makeHashTable(VI inOrder){
	VI hashTable(inOrder.size()+1);
	for(int idx = 0; idx<inOrder.size(); idx++){
		hashTable[inOrder[idx]] = idx;
	}
	return hashTable;
}

void freeOrder(Node* root){
    std::ios_base::sync_with_stdio(false);
	std::stack<Node*> s;
	s.push(root);
	int f = 0;
	while(!s.empty()){
		Node* node = s.top();
		s.pop();
		std::cout<< node->value<< ' ';
		if(node->haveRigth()){
			s.push(node->getRigth());
		}
		if(node->haveLeft()){
			s.push(node->getLeft());
		}
	}
	std::cout<<'\n';
}
```

## 잡담
 오랜만에 c++로 풀어서 코테를 위해 푼다보다 제대로 무언가를 만든다는 느낌으로 풀어봤다.

 그래서 트리도 Node class만들고 여러가지로 열심히 했다.

 그리고 재귀도 안 사용하도록 짜봤다. ㅎㅎ....진짜 열심히 했다..