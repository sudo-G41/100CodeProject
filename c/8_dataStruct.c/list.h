#ifndef LIST_H
#define LIST_H

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

// value
extern List* L;

// functions
void listInit();

void listMain();
void listAdd();
void listDel();
void listSer();
void printList();

#endif
