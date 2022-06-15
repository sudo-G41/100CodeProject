#include<iostream>
#include<queue>
#include<vector>
#include<map>

#define MAXW 987654321

std::vector<int> djikstra(std::vector<std::map<int,int>> G, int k);
std::vector<std::map<int,int>> makeGraph(int v, int e);
void printG(std::vector<std::map<int,int>> G);

int main(){
	int v,e,k;
	scanf("%d%d",&v,&e);
	scanf("%d",&k);
	std::vector<std::map<int,int>> G = makeGraph(v,e);
	#ifndef BOJ
	//디버깅용
	printG(G);
	#endif
	std::vector<int> route = djikstra(G,k);
	for(auto it=route.begin();++it!=route.end();){
		if(*it<MAXW){
			std::cout<<*it<<'\n';
		}
		else{
			std::cout<<"INF\n";
		}
	}
	return 0;
}

std::vector<int> djikstra(std::vector<std::map<int,int>> G, int k){
	//queue<w,v>
	std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>> > q;
	std::vector<int> miniRoute(G.size(),MAXW);
	q.push({miniRoute[k]=0,k});
	while(!q.empty()){
		int u = q.top().second;
		int uw = q.top().first;
		q.pop();
		if(miniRoute[u]<uw){
			continue;
		}
		for(auto node = G[u].begin(); node!=G[u].end();node++){
			int v = node->first;
			int vw = node->second;
			if(miniRoute[v]>vw+uw){
				miniRoute[v] = vw+uw;
				q.push({miniRoute[v],v});
			}
		}
	}
	return miniRoute;
}

std::vector<std::map<int,int>> makeGraph(int V, int e){
	//map<v,w>
	std::vector<std::map<int,int>> G(V+1);
	int u,v,w;
	while(e-->0){
		scanf("%d%d%d",&u,&v,&w);
		if(G[u].count(v)){
			G[u][v] = G[u][v]<w?G[u][v]:w;
		}
		else{
			G[u][v] = w;
		}
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
