#ifndef UNIONFIND_H
#define UNIONFIND_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct UnionFind{
	int* root;
	int* rank;
	int size;
}unionfind;

int find(unionfind* uf, int num);
void unionSet(unionfind* uf, int x, int y);
unionfind makeSet();
int isSameSet(unionfind* uf, int x, int y);
#endif
