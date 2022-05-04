#include"unionfind.h"

int main(){
	int x;
	int a,s;
	unionfind uf = makeSet();
	printf("몇개의 연결을 하실건가요? ");
	scanf("%d",&x);
	for(int i=0;i<x;i++){
		a=0;
		s=0;
		printf("연결할 집합의 원소a b 를 입력해 주세요 ");
		scanf("%d %d",&a,&s);
		unionSet(&uf,a,s);
	}
	printf("연결을 확인할 두 원소 a b를 입력해 주세요 ");
	scanf("%d%d",&a,&s);
	printf("두 원소 %d, %d는 ",a,s);
	printf(isSameSet(&uf, a,s)?"같은 집합에 있습니다.\n":"다른 집합에 속해 있습니다.\n");
}
