# Programmers[Lv2 게임 맵 최단거리](https://programmers.co.kr/learn/courses/30/lessons/1844)
## 문제
 ROR 게임은 두 팀으로 나누어서 진행하며, 상대 팀 진영을 먼저 파괴하면 이기는 게임입니다. 따라서, 각 팀은 상대 팀 진영에 최대한 빨리 도착하는 것이 유리합니다.
 
 게임 맵의 상태 maps가 매개변수로 주어질 때, 캐릭터가 상대 팀 진영에 도착하기 위해서 지나가야 하는 칸의 개수의 최솟값을 return 하도록 solution 함수를 완성해주세요. 단, 상대 팀 진영에 도착할 수 없을 때는 -1을 return 해주세요.

## 제한사항 
* maps는 n x m 크기의 게임 맵의 상태가 들어있는 2차원 배열로, n과 m은 각각 1 이상 100 이하의 자연수입니다.
    * n과 m은 서로 같을 수도, 다를 수도 있지만, n과 m이 모두 1인 경우는 입력으로 주어지지 않습니다.
* maps는 0과 1로만 이루어져 있으며, 0은 벽이 있는 자리, 1은 벽이 없는 자리를 나타냅니다.
* 처음에 캐릭터는 게임 맵의 좌측 상단인 (1, 1) 위치에 있으며, 상대방 진영은 게임 맵의 우측 하단인 (n, m) 위치에 있습니다.


## 내 풀이
 최단경로문제에서 가끔 BFS를 물어보는 문제가 있던데 이 문제가 그 BFS문제였다.

 DFS도 가능 하지만 모든 경로를 한번씩 확인해야 하므로 효율성이 떨어져 시간초과가 날 것으로 예상되므로 BFS를 사용하는 문제이다.

 BFS는 어떻게 시간초과가 안나냐 하면 BFS는 같은 레벨의 노드들끼리 먼저 비교하기 때문에 도착 노드가 먼저 나온 레벨이 가장 최소 레벨이 되므로 최소의 횟수로 도착할 수 있다.

 그리고 이미 들렸던 곳은 다음에 또 들렸을 경우 더 많은 횟수로 도착한것 이기 때문에 이미 들렸던 곳은 다시 들릴 이유가 없으므로 매핑을 해서 한번 들린곳은 다시 찾지 안도록 해주어야 한다. 

## 구현([전체 코드 파일](/programmers/1844%EA%B2%8C%EC%9E%84%EB%A7%B5%EC%B5%9C%EB%8B%A8%EA%B1%B0%EB%A6%AC/solution/solution.cc))
``` C++
int solution(std::vector<std::vector<int> > maps){
	int answer;
	std::vector<std::vector<int>> moveMaps(maps);
	int n,m;
	n = maps.size();
	m = maps[0].size();
	int x,y;
	x=y=0;
	std::queue<std::vector<int>> bfs;
	bfs.push({x,y,1});
	moveMaps[x][y] = 0;
	while(!bfs.empty()){
		std::vector<int> front = bfs.front();
		bfs.pop();
		x=front[0];
		y=front[1];
		int count = front[2];
		if(x==n-1&&y==m-1){
			return count;
		}
		else{
			count++;
		}
		
		if(x+1<n){
			if(moveMaps[x+1][y]){
				if(x+1==n-1&&y==m-1){
					return count;
				}
				bfs.push({x+1,y,count});
				moveMaps[x+1][y]=0;
			}
		}
		if(x>0){
			if(moveMaps[x-1][y]){
				bfs.push({x-1,y,count});
				moveMaps[x-1][y]=0;
			}
		}
		if(y+1<m){
			if(moveMaps[x][y+1]){
				if(x==n-1&&y+1==m-1){
					return count;
				}
				bfs.push({x,y+1,count});
				moveMaps[x][y+1]=0;
			}
		}
		if(y>0){
			if(moveMaps[x][y-1]){
				bfs.push({x,y-1,count});
				moveMaps[x][y-1]=0;
			}
		}

	}
	return -1;
}

```

## 잡담
 백준 풀다보니 푸는 눈이 좀 생긴것 같다.. BFS DFS이런거 문제로 만나면 잘 이해 못했는데 이제 조금씩 보이기 시작한 느낌이라 좋다.. ㅎㅎ