#include<cstdio>
#include<vector>

using namespace std;

int MOVE[2][4] = {
	{0,0,1,-1},
	{1,-1,0,0}
};

int solution(vector<vector<int>> maps);
void check(vector<vector<int>>& maps, int rain, int x, int y);
int safe(vector<vector<int>> maps, int rain);

int main(){
	int n;
	scanf("%d",&n);
	vector<vector<int>> maps(n,vector<int>(n));
	for(int x=0, y=0; x!=n; ){
		if(y!=n){
			scanf("%d",&maps[x][y]);
			y++;
		}
		else{
			x++;
			y=0;
		}
	}
	printf("%d",solution(maps));
	return 0;
}

int solution(vector<vector<int>> maps){
	int answer = 1;
	for(int i = 1; i!=101; i++){
		int tmp = safe(maps, i);
		answer = answer>tmp? answer: tmp;
	}
	return answer;
}

void check(vector<vector<int>>& maps, int rain, int x, int y){
	if(0>x || x==maps.size() || 0>y || y==maps.size())
		return;
	if(maps[x][y] > rain){
		maps[x][y] = 0;
		for(int i=0; i!=4; i++){
			check(maps, rain, x+MOVE[0][i], y+MOVE[1][i]);
		}
	}
}

int safe(vector<vector<int>> maps, int rain){
	int result = 0;
	for(int x=0, y=0; x!=maps.size(); ){
		if(y!=maps.size()){
			if(maps[x][y] > rain){
				result++;
				check(maps, rain, x, y);
			}
			y++;
		}
		else{
			x++;
			y=0;
		}
	}
	return result;
}
