#include "BST.h"

Node * createNode(int value){
	Node * node = (Node *) malloc(sizeof(Node));
	node->data = value;
	node->right = node->left = NULL;
	return node;
}

Tree * createTree(void){
	Tree * tree = (Tree *) malloc(sizeof(Tree));
	tree->size = 0;
	tree->root = NULL;
	return tree;
}

void insertNode(Tree * tree, int value){
	Node * tmp = NULL, * newNode = NULL;
	newNode = createNode(value);

	tree->size++;

	if (tree->root == NULL){
		tree->root = newNode;
		return;
	}

	tmp = tree->root;

	while (tmp != NULL){
		if (value < tmp->data){
			if (tmp->left == NULL){
				tmp->left = newNode;
				return;
			}
			tmp = tmp->left;
		} 
		else if (value > tmp->data){
			if (tmp->right == NULL){
				tmp->right = newNode;
				return;
			}
			tmp = tmp->right;
		}
		else return;
	}

}

Node * removeNode(Tree * tree, Node * root, int key){
	if (tree == NULL || root == NULL){
		return NULL;
	}

	if (root->data == key){
		if (root->right == NULL && root->left == NULL){
			free(root);
			tree->size--; // conferir
			return NULL;
		}
		else if (root->right == NULL || root->left == NULL){
			Node * tmp;
			if (root->left != NULL)
				tmp = root->left;
			else 
				tmp = root->right;
			free(root);
			tree->size--; // conferir
			return tmp;
		}
		else {
			Node * tmp = root->left;
			while (tmp->right != NULL)
				tmp = tmp->right;
			root->data = tmp->data;
			tmp->data = key;
			root->left = removeNode(tree, root->left, key);
			return root;
		}
	} 
	else {
		if (key < root->data){
			root->left = removeNode(tree, root->left, key);
		}
		else {
			root->right = removeNode(tree, root->right, key);
		}
		return root;
	}

}

Node * search(Tree * tree, int key){
	Node * tmp = tree->root;

	while (tmp != NULL){
		if (key == tmp->data) {
			return tmp;
		}
		if (key > tmp->data) {
			tmp = tmp->right;
		}
		else {
			tmp = tmp->left;
		}
	}

	return NULL;
}

int isEmpty(Tree * tree){
	if (tree == NULL) return 1;
	if (tree->root == NULL) return 1;
	return 0;
}

void preOrder(Node * root){
	if (root != NULL){
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(Node * root){
	if (root != NULL){
		inOrder(root->left);
		printf("%d ", root->data);
		inOrder(root->right);
	}
}

void postOrder(Node * root){
	if (root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->data);
	}
}

Node * freeNode(Node * node){
	node->left = node->right = NULL;
	free(node);	
	return NULL;
}

void freeAllNodes(Node * root){
	Node * tmp = root;
	if (tmp != NULL){
		freeAllNodes(tmp->left);
		freeAllNodes(tmp->right);
		printf("Removendo %d\n", tmp->data);
		tmp = freeNode(tmp);
	}
}

Tree * freeTree(Tree * tree){
	if (tree == NULL) return NULL;

	if (tree->root != NULL){
		freeAllNodes(tree->root);
		tree->root = NULL;
	}

	tree->size = 0;
	free(tree);

	return NULL;
}

/*
Node * maxNode(Node * root){
	return (!root->right) ? root : maxNode(root->right);
}

Node * removeNode(Tree * tree, Node * root, int value){
	if (tree == NULL || root == NULL) return NULL;

	if (root->data == value){
		Node * temp = NULL;
		tree->size--;
		if (root->right == NULL || root->left == NULL){
				if (!root->right)
					temp = root->left;
				else
					temp = root->right;
				free(root);
				return temp;
		}
		temp = maxNode(root->left);
		root->data = temp->data;
		temp->data = value;
		root->left = removeNode(createTree(), root->left, value);
	}
	else if ( value < root->data ){
		root->left = removeNode(tree, root->left, value);
	} 
	else {
		root->right = removeNode(tree, root->right, value);
	}

	return root;
}

*/