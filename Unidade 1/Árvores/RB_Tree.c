#include "RB_Tree.h"

int color(Node * node){
	return (!node) ? BLACK : node->color;
}

int swapColor(Node * node){
	node->color = !node->color;
	if (node->left) 
		node->left->color = !node->left->color;
	if (node->right) 
		node->right->color = !node->right->color;
}