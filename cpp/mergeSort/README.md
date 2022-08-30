# 병합정렬
병합정렬
0부터 size까지 병합정렬 되는 코드
## [코드](./c.cc)
 ```
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
```