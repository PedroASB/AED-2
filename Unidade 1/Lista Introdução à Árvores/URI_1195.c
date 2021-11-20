#include <stdio.h>
#include <stdlib.h>

// gcc URI_1195.c -o URI_1195 && ./URI_1195

// Estrutura de um nó da árvore
typedef struct node {
	int data;
	struct node *left, *right;
} Node;

// Estrutura de uma árvore binária
typedef struct tree {
	int size;
	Node *root;
} Tree;

// Cria e aloca um nó
Node * createNode(int value);

// Cria e aloca uma árvore
Tree * createTree(void);

// Insere um nó na árvore
void insertNode(Tree * tree, int value);

// Imprime a árvore na ordem prefixa
void preOrder(Node * root);

// Imprime a árvore na ordem infixa
void inOrder(Node * root);

// Imprime a árvore na ordem posfixa
void postOrder(Node * root);

// Libera a memória alocada pelos nós da árvore
void freeAllNodes(Node * root);

// Libera a memória alocada pela estrutura da árvore
Tree * freeTree(Tree * tree);

int main(){
	int C, N, value, i = 1;
	Tree * tree = NULL;

	scanf("%d", &C);

	while (C--){
		scanf("%d", &N);
		tree = createTree();
		while (N--){
			scanf("%d", &value);
			insertNode(tree, value);
		}
		printf("Case %d:", i);
		printf("\nPre.:");
		preOrder(tree->root);
		printf("\nIn..:");
		inOrder(tree->root);
		printf("\nPost:");
		postOrder(tree->root);
		printf("\n\n");
		tree = freeTree(tree);
		i++;
	}

	return 0;
}

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
		else {
			if (tmp->right == NULL){
				tmp->right = newNode;
				return;
			}
			tmp = tmp->right;
		}
	}

}

void preOrder(Node * root){
	if (root != NULL){
		printf(" %d", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(Node * root){
	if (root != NULL){
		inOrder(root->left);
		printf(" %d", root->data);
		inOrder(root->right);
	}
}

void postOrder(Node * root){
	if (root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		printf(" %d", root->data);
	}
}

void freeAllNodes(Node * root){
	Node * tmp = root;
	if (tmp != NULL){
		freeAllNodes(tmp->left);
		freeAllNodes(tmp->right);
		free(tmp);
	}
}

Tree * freeTree(Tree * tree){
	if (tree == NULL) return NULL;

	if (tree->root != NULL){
		freeAllNodes(tree->root);
	}

	tree->size = 0;
	free(tree);

	return NULL;
}