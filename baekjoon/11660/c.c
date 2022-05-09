#include <stdio.h>
#include <stdlib.h>
 
int main(void) {
    int** arr;
    int n,m,x1,x2,y1,y2,qwer;
    scanf("%d%d",&n,&m);
    arr = (int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
        arr[i]=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        x1=0;
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
            x1=arr[i][j]+=x1;
        }
    }
    for(int i=0;i<m;i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        qwer=0;
        for(int j=x1-1;j<x2;j++){
            qwer+=arr[j][y2-1];
            if(y1>1){
              qwer-=arr[j][y1-2];
            }
        }
        printf("%d\n",qwer);
    }
	return 0;
}