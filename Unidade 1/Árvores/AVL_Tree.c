#include "AVL_Tree.h"

Node * createNode(int value){
	Node * node = (Node *) malloc(sizeof(Node));
	node->data = value;
	node->height = 0;
	node->right = node->left = NULL;
	return node;
}

AVLtree * createAVLtree(void){
	AVLtree * root = (AVLtree *) malloc(sizeof(AVLtree));
	if (root != NULL) *root = NULL;
	return root;
}

int absInt(int number){
	return (number >= 0) ? number : -number;
}

int highest(int numberA, int numberB){
	return (numberA >= numberB) ? numberA : numberB;
}

int nodeHeight(Node * node){
	return (!node) ? -1 : node->height;
}

int balanceFactor(Node * node){
	return absInt(nodeHeight(node->left) - nodeHeight(node->right));
}

// Rotação simples à esquerda (RR)
void leftRotate(AVLtree * root){
	Node * node = (*root)->right;
	(*root)->right = node->left;
	node->left = *root;

	(*root)->height = highest(nodeHeight((*root)->left), 
							nodeHeight((*root)->right)) + 1;
	node->height = highest(nodeHeight(node->right), 
							nodeHeight(*root)) + 1;

	*root = node;
}

// Rotação simples à direita (LL)
void rightRotate(AVLtree * root){
	Node * node = (*root)->left;
	(*root)->left = node->right;
	node->right = *root;

	(*root)->height = highest(nodeHeight((*root)->left), 
							nodeHeight((*root)->right)) + 1;
	node->height = highest(nodeHeight(node->left), 
							nodeHeight(*root)) + 1;

	*root = node;
}

// Rotação dupla à esquerda (RL)
void doubleLeftRotate(AVLtree * root){
	rightRotate(&( (*root)->right ));
	leftRotate(root);
}

// Rotação dupla à direita (LR)
void doubleRightRotate(AVLtree * root){
	leftRotate(&( (*root)->left) );
	rightRotate(root);
}

void insertNode(AVLtree * root, int value){
	if (root == NULL) return;

	if (*root == NULL){
		*root = createNode(value);
		return;
	}

	Node * current = *root; // analisar

	if (value < (*root)->data){
		insertNode(&(current->left), value);

		if (balanceFactor(current) >= 2){
			if (value < (*root)->left->data) 
				rightRotate(root);
			else doubleRightRotate(root);
		}

	} 
	else if (value > current->data){
		insertNode(&(current->right), value);

		if (balanceFactor(current) >= 2){
			if (value > (*root)->right->data)
				leftRotate(root);
			else doubleLeftRotate(root);
		}

	}
	else return;

	current->height = highest(nodeHeight(current->left), 
							nodeHeight(current->right)) + 1;

	return;
}

Node * searchMin(Node * current){
	return (!current->left) ? current : searchMin(current->left);
}

// INCOMPLETA
void removeNode(AVLtree * root, int value){
	if (root == NULL) return;
	if (*root == NULL) return;

	if (value < (*root)->data){
		removeNode(&((*root)->left), value);

		if (balanceFactor(*root) >= 2){
			if (nodeHeight(root)) 
				rightRotate(root);
			else doubleRightRotate(root);
		}

	} 
	else if (value > (*root)->data){
		removeNode(&((*root)->right), value);

		if (balanceFactor(*root) >= 2){
			if ()
				leftRotate(root);
			else doubleLeftRotate(root);
		}

	}
	else {
		
	}


}

void preOrder(AVLtree * root){
	if (root == NULL) return;
	if (*root != NULL){
		printf("%d ", (*root)->data);
		postOrder(&((*root)->left));
		postOrder(&((*root)->right));
	}
}

void inOrder(AVLtree * root){
	if (root == NULL) return;
	if (*root != NULL){
		postOrder(&((*root)->left));
		printf("%d ", (*root)->data);
		postOrder(&((*root)->right));
	}
}

void postOrder(AVLtree * root){
	if (root == NULL) return;
	if (*root != NULL){
		postOrder(&((*root)->left));
		postOrder(&((*root)->right));
		printf("%d ", (*root)->data);
	}
}

int isEmpty(AVLtree * root){
	if (root == NULL) return 1;
	if (*root == NULL) return 1;
	return 0;
}

void freeAllNodes(Node * node){
	if (node == NULL) return;
	freeAllNodes(node->left);
	freeAllNodes(node->right);
	free(node);
	node = NULL;
}

void freeAVLtree(AVLtree * root){
	if (root == NULL) return;
	freeAllNodes(*root);
	free(root);
}