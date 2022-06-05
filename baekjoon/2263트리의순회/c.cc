#include<iostream>
#include<vector>
#include<stack>

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

int Node::getStart(){
	return this->startIdx;
}

int Node::getEnd(){
	return this->endIdx;
}

Node* Node::getRigth(){
	return this->right;
}

Node* Node::getLeft(){
	return this->left;
}

bool Node::haveRigth(){
	return this->right != NULL;
}

bool Node::haveLeft(){
	return this->left != NULL;
}

Node* makeTree(VI idxHashTable, VI postOrder);
VI makeHashTable(VI inOrder);
void printVector(VI v);
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
	Node* tree = makeTree(idxHashTable, postOrder);
	freeOrder(tree);
	delete tree;
    return 0;
}

Node* makeTree(VI idxHashTable, VI postOrder){
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
