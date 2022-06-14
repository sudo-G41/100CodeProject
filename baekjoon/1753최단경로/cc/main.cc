#include<iostream>
#include<queue>
#include<vector>
#include<map>

#define MAXW (2e+5+1)

std::vector<int> djikstra(std::vector<std::map<int,int>> G, int k);
std::vector<std::map<int,int>> makeGraph(int v, int e);
void printG(std::vector<std::map<int,int>> G);

int main(){
	int v,e,k;
	scanf("%d%d",&v,&e);
	scanf("%d",&k);
	std::vector<std::map<int,int>> G = makeGraph(v,e);
	printG(G);
	k--;
	djikstra(G,k);
	return 0;
}

std::vector<int> djikstra(std::vector<std::map<int,int>> G, int k){
	//queue<w,v>
	std::priority_queue<std::pair<int,int>> q;
	std::vector<int> miniRoute(G.size(),MAXW);
	int min;
	miniRoute[k]=0;
	q.push({MAXW,k});
	while(!q.empty()){
		std::pair<int,int> tmp = q.top();
		q.pop();
	}
	return miniRoute;
}

std::vector<std::map<int,int>> makeGraph(int V, int e){
	//map<v,w>
	std::vector<std::map<int,int>> G(V);
	int u,v,w;
	while(e-->0){
		scanf("%d%d%d",&u,&v,&w);
		G[u-1].insert({v-1,w});
	}
	return G;
}

void printG(std::vector<std::map<int,int>> G){
	for(auto it=G.begin();it!=G.end();it++){
		for(auto v=it->begin(); v!=it->end();v++){
			printf("(%d, %d) ",v->first,v->second);
		}
		printf("\n");
	}
}
