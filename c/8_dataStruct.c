#include<stdio.h>
#include<stdlib.h>

// structs
typedef struct node{
    int val;
    struct node* next;
}Node;

typedef struct list{
    Node* head;
    Node* tail;
    int size;
}List;

// global values
int listArr = -1;
char* b;

List* L;

// functions;
int input(int);

void listInit();

void listMain();
void listAdd();
void listDel();
void listSer();
void printList();

void stackMain();

void queueMain();

int main(){
    int i;
    b = (char*)malloc(sizeof(char) * 101);
    printf("알고리즘을 사용해보자\n");
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

void listInit(){
    Node* n;
    if(L != NULL){
        while(L->size){
            n = L->head->next;
            free(L->head);
            L->head = n;
            L->size--;
        }
    }
    else{
        L = (List*)malloc(sizeof(List));
        L->size = 0;
        L->head = (Node*)malloc(sizeof(Node));
        L->tail = NULL;
        L->head->next = L->tail;
    }
    return;
}

void listMain(){
    int i;

    listInit();

    while(1){
        printf("1. List Add node\n");
        printf("2. List Del node\n");
        printf("3. Search Node index\n");
        printf("-1.Exit\n");
        printf(": __\b\b");
        i = input(0);
        switch(i){
            case 1:
                printf("add\n");
                listAdd();
                break;
            case 2:
                break;
            case 3:
                break;
            case -1:
                exit(0);
                break;
            default:
                printf("이상한 값은 좀.... [%s]는 1~3이 아니에요...\n", b);
                break;
        }
        printList();
    }
}

void listAdd(){
    int val, idx = 0;
    if(L->size){
        printf("Index(dafault 0): _______\b\b\b\b\b\b\b");
        idx = input(0);
    }
    printf("Value(dafault 0): _______\b\b\b\b\b\b\b");
    val = input(0);
    
    printf("index: %d, value: %d\n", idx, val);

    if(L->size<idx){
        printf("size over\n");
    }
    else if(idx<0){
        printf("size under\n");
    }
    else{
        // 리스트에 데이터 삽입하는 코드
        Node* n=L->head;
        for(int i = 0; i!=idx; i++){
            n = n->next;
        }
        Node* data = (Node*)malloc(sizeof(Node));
        data->val = val;
        data->next = n->next;
        n->next = data;
        L->size++;
        // 여기까지
    }
}

//void listDel();
//void listSer();
void printList(){
    printf("=============================================================================\n");
    if(L->size){
        Node* n = L->head->next;
        printf("list: [ ");
        // 리스트에서 모든 데이터를 조회하는 코드
        while(1){
            printf("%d ", n->val);
            n = n->next;
            if(n == L->tail){
                printf("]\n");
                break;
            }
            printf("-> ");
        }
        //여기까지
    }
    else{
        printf("list: []... it's empty\n");
    }
    printf("=============================================================================\n");
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
