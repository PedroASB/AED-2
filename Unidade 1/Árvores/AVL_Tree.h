#ifndef __AVL_TREE_H__
#define __AVL_TREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
	int data;
	int height;
	struct node *left, *right;
} Node;

typedef Node* AVLtree;

Node * createNode(int value);

AVLtree * createAVLtree(void);

int absInt(int number);

int nodeHeight(Node * node);

int balanceFactor(Node * node);

int highest(int x, int y);

/////////////////////

void leftRotate(AVLtree * root);
void rightRotate(AVLtree * root);
void doubleLeftRotate(AVLtree * root);
void doubleRightRotate(AVLtree * root);

////////////////////////

void insertNode(AVLtree * root, int value);

Node * searchMin(Node * current);

void removeNode(AVLtree * root, int value);

void preOrder(AVLtree * root);

void inOrder(AVLtree * root);

void postOrder(AVLtree * root);

int isEmpty(AVLtree * tree);

Node * freeNode(Node * node);

void freeAllNodes(Node * root);

void freeAVLtree(AVLtree * root);

#endif // __AVL_TREE_H__