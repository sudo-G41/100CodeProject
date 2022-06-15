# 백준[1753](https://www.acmicpc.net/problem/1753)번
## 문제
 방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오. 단, 모든 간선의 가중치는 10 이하의 자연수이다.

## 입력
 첫째 줄에 정점의 개수 V와 간선의 개수 E가 주어진다. (1 ≤ V ≤ 20,000, 1 ≤ E ≤ 300,000) 모든 정점에는 1부터 V까지 번호가 매겨져 있다고 가정한다. 둘째 줄에는 시작 정점의 번호 K(1 ≤ K ≤ V)가 주어진다. 셋째 줄부터 E개의 줄에 걸쳐 각 간선을 나타내는 세 개의 정수 (u, v, w)가 순서대로 주어진다. 이는 u에서 v로 가는 가중치 w인 간선이 존재한다는 뜻이다. u와 v는 서로 다르며 w는 10 이하의 자연수이다. 서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 있음에 유의한다.

## 출력
 첫째 줄부터 V개의 줄에 걸쳐, i번째 줄에 i번 정점으로의 최단 경로의 경로값을 출력한다. 시작점 자신은 0으로 출력하고, 경로가 존재하지 않는 경우에는 INF를 출력하면 된다.

## 내 풀이
 가장 기본적인 다익스트라 알고리즘이다. 단 행렬을 이용한 $O(N^2)$형태로 풀경우 시간초과가 나는 문제이다.

 처음부터 이야기 해 보자면 우선은 V,E,K를 입력받고 그 뒤 그래프를 그려야 하는데 이때 V의 값이 1 ~ 20,000이고 E는 1 ~ 300,000인점을 주의해야 한다. 무슨 이야기냐면 간선이 정점의 개수 -1이 아니라는 것은 두 정점 사이에 간선이 무조건 1개가 아니라 1개를 초과할 수 있도 있고 0개일 수도 있다는 이야기이다.  
 왜 그러느냐 하면 만약 정점이 3개이고 간선이 1개라면 두개의 정점은 서로 이어지지만 나머지 한개는 이어질 수 없는 이야기이다. 1개를 초과하는 부분은 비둘기집 원리를 잘 생각해 보라.(물론 방향 그래프이기에 왔다가 가는 형태일 수도 있지만 그렇다면 최대가 V의 2배이여야 하지 그 이상이 되면 안된다.)
 
그렇기 때문에 나는 map을 써서 그래프를 그릴 때 한번 방문한 정점이면 좀더 짧은것을 저장하여 좀더 빠르게 최솟값을 찾도록 그렸다.

다익스트라는... 뭐 인터넷 찾아봐라 많다.... 우선순위 큐 써서 하는거 많다... 뭔가 오름차순 할 줄 몰라서 막 -시켜서 하는거 있던데 머리 잘쓰는거라 생각하니 STL공부도 좀 해보고 하면서 했음 좋겠다...

## 구현([전체 코드 파일](/baekjoon/폴더이름/코드파일))
``` c++
std::vector<std::map<int,int>> makeGraph(int V, int e){
	//map<v,w>
	std::vector<std::map<int,int>> G(V+1);
	int u,v,w;
	while(e-->0){
		scanf("%d%d%d",&u,&v,&w);
		if(G[u].count(v)){
			G[u][v] = G[u][v]<w? G[u][v]: w;
		}
		else{
			G[u][v] = w;
		}
	}
	return G;
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
```

## 잡담
 아 분명 풀다가 밖에 나갔을 때 아 이 문제 정점이랑 간선수 생각하면 중복 없다는 이야기 없으니 그 부분 잘 처리해야지 해놓고 그거 구현 안하고 아 왜 틀리지 이러고 있었다.... 하..... 이 ****... 벨즈 성분이 부족해서 그런가... 아님 이나 성분이 부족해서 그런가... INF볼때마다 INAFF생각났는데 이나 성분 부족이 맞는거 같다...