#ifndef __BST_H__
#define __BST_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *left, *right;
} Node;

typedef struct tree {
	int size;
	Node *root;
} Tree;

Node * createNode(int value);

Tree * createTree(void);

void insertNode(Tree * tree, int value);

Node * removeNode(Tree * tree, Node * root, int key);

// Fazer usando if/else e também de forma recursiva
Node * search(Tree * tree, int key);

int isEmpty(Tree * tree);

void preOrder(Node * root);

void inOrder(Node * root);

void postOrder(Node * root);

void freeAllNodes(Node * root);

Tree * freeTree(Tree * tree);

#endif // __BST_H__