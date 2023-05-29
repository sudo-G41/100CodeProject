#include<cstdio>
#include<cstdlib>

using namespace std;

int main(){
	int N, M, K;
	int tmp;
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0; i!=M; i++){
		scanf("%d",&tmp);
		s.insert(tmp);
	}
	for(int i=0; i!=K; i++){
		scanf("%d",&tmp);
		auto it = s.upper_bound(tmp);
		printf("%d\n", *it);
		s.erase(it);
	}
	return 0;
}
