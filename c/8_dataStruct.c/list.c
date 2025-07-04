#include"list.h"
#include"h.h"

List* L = NULL;

int un_o(int idx){
    if(L->size<idx){
        printf("===========\n");
        printf("|size over|\n");
        printf("===========\n");
        return 1;
    }
    else if(idx<0){
        printf("============\n");
        printf("|size under|\n");
        printf("============\n");
        return 1;
    }
    return 0;
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
                listDel();
                break;
            case 3:
                listSer();
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
        printf("Index(dafault 0): ______________________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        idx = input(0);
    }
    printf("Value(dafault 0): ______________________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
    val = input(0);
    
    printf("index: %d, value: %d\n", idx, val);

    if(!un_o(idx)){
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

void listDel(){
    int val, idx;
    Node *n, *d;
    if(!L->size){
        printf("Delete fail......\n");
        return;
    }
    printf("1. Delete by Value\n");
    printf("2. Delete by Index\n");
    printf(": _");
    idx = input(-1);
    n = L->head;

    if(!(idx^1)){
        printf("Value(dafault 0): ______________________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        val = input(0);
        // value 기준 삭제
        while(n->next != L->tail){
            if(n->next->val^val){
                n = n->next;
            }
            else{
                d = n->next;
                n->next = d->next;
                free(d);
                L->size--;
                return;
            }
        }
        printf("[404]: Delete fail%d is not found)\n", val);
        // 여기까지
    }
    else if(!(idx^2)){
        printf("Index(dafault 0): ______________________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        val = input(0);
        if(!un_o(val>-1?val+1:val)){
            // index 기준 삭제
            for(int i=0; i!=val; i++){
                n = n->next;
            }
            d = n->next;
            n->next = d->next;
            free(d);
            L->size--;
            // 여기까지
        }
    }
    else{
        printf("이상한 값은 좀.... [%s]는 1~3이 아니에요...\n", b);
    }
}
void listSer(){
    int val, idx;
    Node *n;
    printf("1. Search by Value\n");
    printf("2. Search by Index\n");
    printf(": _");
    idx = input(-1);
    n = L->head->next;
    switch(idx){
        case 1:
            printf("Value(dafault 0): ______________________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
            val = input(0);
            idx = 0;
            // value 기준 탐색
            while(n != L->tail){
                if(n->val^val){
                    n = n->next;
                    idx++;
                }
                else{
                    printf("%d in [%d]index\n", val, idx);
                    return;
                }
            }
            printf("[404]: Search fail(%d is not found)\n", val);
            break;
        case 2:
            printf("Index(dafault 0): ______________________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
            idx = input(0);
            if(!un_o(idx>-1?idx+1:idx)){
                // index 기준 탐색
                for(int i=0; i!=idx; i++){
                    n = n->next;
                }
                printf("%d index is [%d]\n", idx, n->val);
                // 여기까지
            }
            break;
        default:
            printf("이상한 값은 좀.... [%s]는 1~3이 아니에요...\n", b);
            break;
    }
}

void printList(){
    printf("\n\n\n=============================================================================\n");
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
    printf("=============================================================================\n\n\n");
}
