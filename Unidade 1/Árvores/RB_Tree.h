#ifndef __RB_TREE_H__
#define __RB_TREE_H__

#include <stdio.h>
#include <stdlib.h>
#define RED 1
#define BLACK 0

typedef struct node {
	int data;
	int color;
	struct node *left, *right;
} Node;

typedef Node* RBtree;

int color(Node * node);
int swapColor(Node * node);


#endif // __RB_TREE_H__