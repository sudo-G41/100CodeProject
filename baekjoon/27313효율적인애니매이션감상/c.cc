#include<cstdio>
#include<cstdlib>

using namespace std;

int arr[100001];
int tmp[100001];

void sorting(int, int);
void merge(int l, int r);
void sort(int l, int m, int r);
int solution(int, int, int);

int main(){
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	for(int i = 0; i!=N; i++){
		scanf("%d", arr+i);
		if(arr[i] > M){
			i--;
			N--;
		}
	}
	sorting(0,N);
//	for(int i = 0; i!=N; i++){
//		printf("%d ",arr[i]);
//	}
	printf("%d\n", solution(N,M,K));
	return 0;
}

int solution(int N, int M, int K){
	tmp[0] = M-arr[0];
	for(int i=0; i!=N; i++){
		if(i<K){
			tmp[i] = M-arr[i];
		}
		else{
			if(tmp[i-K]-arr[i]<0){
				return i;
			}
			else{
				tmp[i] = tmp[i-K]-arr[i];
			}
		}
	}
	return N;
}

void sorting(int s, int e){
	merge(s,e);
}

void merge(int l, int r){
	if(l==r-1)
		return;
	int m = l + ((r-l)>>1);
	merge(l,m);
	merge(m,r);
	sort(l,m,r);
}

void sort(int l, int m, int r){
	int ll, rr, idx;
	idx = ll = l;
	rr = m;
	while(ll!=m && rr!=r){
		if(arr[ll]<arr[rr]){
			tmp[idx++] = arr[ll++];
		}
		else{
			tmp[idx++] = arr[rr++];
		}
	}

	if(ll == m){
		ll = rr;
		rr = r;
	}
	else{
		rr = m;
	}

	while(ll!=rr){
		tmp[idx++] = arr[ll++];
	}
	while(l!=r){
		arr[l] = tmp[l];
		l++;
	}
}
