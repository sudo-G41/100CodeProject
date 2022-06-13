
#include"solution.hh"

int solution(std::vector<std::vector<int> > maps);

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