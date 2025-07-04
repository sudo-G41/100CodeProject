#include<stdio.h>
#include<stdlib.h>
#include"h.h"
#include"list.h"

int listArr = -1;
char* b;

int main(){
    int i;
    b = (char*)malloc(sizeof(char) * 101);
    printf("자료구조를 사용해보자\n");
    printf("1. linked list\n");
    printf("2. stack\n");
    printf("3. queue\n");
    printf("번호를 선택하세요: ");

    i = input(-1);

    switch(i){
        case 1:
            listMain();
            break;
        case 2:
            stackMain();
            break;
        case 3:
            queueMain();
            break;
        default:
            printf("이상한 값은 좀.... [%s]는 1~3이 아니에요...\n", b);
            break;
    }
    return 0;
}

int input(int qwer){
    char* a = b;
    int i = 0;
    int plus;
    
    scanf("%100s", a);

    if(!(plus = (*a != '-'))){
        a++;
    }

    while(*a != '\n' && *a){
        if('0' <= *a && *a <= '9'){
            i = 10*i + (*a&15);
        }
        else{
            i = qwer;
            break;
        }
        a++;
    }
    return plus? i: (~i)+1;
}

void stackMain(){
    printf("1. 배열 사용하기\n");
    printf("2. 리스트 사용하기\n");

    listArr = input(-1);

    while(1){
        switch(listArr){
            case 1:
                break;
            case 2:
                break;
            default:
                break;
        }
    }
}

void queueMain(){
    printf("1. 배열 사용하기\n");
    printf("2. 리스트 사용하기\n");

    listArr = input(-1);

    while(1){
        switch(listArr){
            case 1:
                break;
            case 2:
                break;
            default:
                break;
        }
    }
}
