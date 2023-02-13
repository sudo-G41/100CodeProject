#include "solution/solution.h"

void cp(char *str1, char str2[]){
	char *c = str2;
	while(*c){
		*str1++ = *c++;
	}
}

int main(){
	char ***book = (char***)malloc(sizeof(char**)*5);
	for(int i=0;i!=5;i++){
		book[i] = (char**)malloc(sizeof(char*)*2);
		book[i][0] = (char*)malloc(sizeof(char)*11);
		book[i][1] = (char*)malloc(sizeof(char)*11);
	}
	
	char books[5][2][11] = {{"15:00", "17:00"}, {"16:40", "18:20"}, {"14:20", "15:20"}, {"14:10", "19:20"}, {"18:20", "21:20"}};
	int r = 5, c = 2;
	for(int i=0,j=0;i!=r;){
		if(j!=c){
			cp(book[i][j],books[i][j]);
			j++;
		}
		else{
			j = 0;
			i++;
		}
	}
	printf("%d\n",solution(book, r, c));
	return 0;
}
