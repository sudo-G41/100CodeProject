#include<cstdio>
#include<cstdlib>

using namespace std;

void solution(int N, long long* v);

int main(){
	int N;
	scanf("%d",&N);
	long long v[100001];
	for(int i=0;i!=N;i++){
		scanf("%lld",&v[i]);
	}
	solution(N,v);
	return 0;
}

inline long long absm(long long n){
	return n>0? n: -n;
}

void solution(int N, long long* v){
	int l,r;
	int ll,rr;
	l = 0;
	r = N-1;
	ll = l;
	rr = r;
	while(l!=r){
		if(absm(v[l]+v[r])<absm(v[ll]+v[rr])){
			ll = l;
			rr = r;
		}
		v[l]+v[r]>0? r--: l++;
	}
	printf("%lld %lld\n",v[ll], v[rr]);
}
