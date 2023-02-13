#include "solution.h"

int solution(char ***book, size_t r, size_t c){
	int timestamp[1001];
	int room[1001];
	size_t tsIdx, rIdx;
	tsIdx = rIdx = 0;
	for(int i=0; i!=r; i++){
		up(timestamp, &tsIdx, twoTime(book[i]), 1);
	}
	
	up(room, &rIdx, timestamp[1], 0);
	pop(timestamp, &tsIdx, 1);
	while(tsIdx){
		if(out(room[1])>in(timestamp[1])){
			up(room, &rIdx, timestamp[1], 0);
		}
		else{
			down(room, &rIdx, timestamp[1], 0);
		}
		pop(timestamp, &tsIdx, 1);
	}

	return rIdx;
}

int s2i(char *str){
	int n = 0;
	while(*str){
		if(*str!=':')
			n = 10*n+c2i(*str);
        str++;
	}
	return n;
}

int c2i(char c){
	return c&15;
}

void up(int *arr, size_t *size, int n, char roomIn){
	arr[++(*size)] = n;
	int idx = *size;
	while(idx>>1){
		if(roomIn){
			if(arr[idx]<arr[idx>>1]){
				arr[0] = arr[idx];
				arr[idx] = arr[idx>>1];
				arr[idx>>=1] = arr[0];
			}
			else{break;}
		}
		else{
			if(out(arr[idx])<out(arr[idx>>1])){
				arr[0] = arr[idx];
				arr[idx] = arr[idx>>1];
				arr[idx>>=1] = arr[0];
			}
			else{break;}
		}
	}
}

void down(int *arr, size_t *size, int n, char roomIn){
	arr[1] = n;
	int i = 1;
	while((i<<1)<=*size){
		if(roomIn){
			if((i<<1)+1<=*size){
				int child = arr[i<<1]<arr[(i<<1)+1]? i<<1: (i<<1)+1;
				if(arr[i]>arr[child]){
					arr[0] = arr[i];
					arr[i] = arr[child];
					arr[i=child] = arr[0];
				}
				else{break;}
			}
			else{
				if(arr[i]>arr[i<<1]){
					arr[0] = arr[i];
					arr[i] = arr[i<<1];
					arr[i<<=1] = arr[0];
				}
				else{break;}
			}
		}
		else{
			if((i<<1)+1<=*size){
				int child = out(arr[i<<1])<out(arr[(i<<1)+1])? i<<1: (i<<1)+1;
				if(out(arr[i])>out(arr[child])){
					arr[0] = arr[i];
					arr[i] = arr[child];
					arr[i=child] = arr[0];
				}
				else{break;}
			}
			else{
				if(out(arr[i])>out(arr[i<<1])){
					arr[0] = arr[i];
					arr[i] = arr[i<<1];
					arr[i<<=1] = arr[0];
				}
				else{break;}
			}
		}
	}
}

int twoTime(char **arr){
	return 10000*s2i(arr[0])+addTen(s2i(arr[1]));
}

int in(int t){
	return t/10000;
}

int out(int t){
	return t%10000;
}

int addTen(int t){
    t += 10;
	return t%100<60? t: t-60+100;
}

void pop(int *arr, size_t *size, char roomIn){
	int s = arr[(*size)--];
	down(arr, size, s, roomIn);
}