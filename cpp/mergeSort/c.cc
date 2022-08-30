#include<cstdio>

int *arr,*tmp;
int size;

void print();
void merge(int left, int mid, int right);
void sort(int left, int right);
bool comp(const int a,const int b);

int main(){
	scanf("%d",&size);
	arr = new int[size];
	tmp = new int[size];

	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	print();
	sort(0,size-1);
	print();
	return 0;
}

void print(){
	for(int i=0; i<size; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void merge(int left, int mid, int right){
    int i, j, k, l;
    i = left;
    j = mid+1;
    k = left;

    while(i<=mid && j<=right){
    if(comp(arr[i], arr[j]))
        tmp[k++] = arr[i++];
    else
        tmp[k++] = arr[j++];
    }

    if(i>mid){
        for(l=j; l<=right; l++)
            tmp[k++] = arr[l];
        }
    else{
        for(l=i; l<=mid; l++)
            tmp[k++] = arr[l];
    }
    for(l=left; l<=right; l++){
        arr[l] = tmp[l];
    }
}

void sort(int left, int right){
    if(left<right){
        int mid = (left+right)/2;
        sort(left, mid);
        sort(mid+1, right);
        merge(left, mid, right);
    }
}

bool comp(const int a,const int b){
	return a>b;
//	return a<b;
}
