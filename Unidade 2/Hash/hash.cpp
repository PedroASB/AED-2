#include "hash.hpp"

HashTable::HashTable(){
	size = 0;
	for(int i = 0; i < MAX; i++) 
		initializeList(&table[i]);
}

HashTable::~HashTable(){
	for(int i = 0; i < MAX; i++) 
		freeList(&table[i]);
}

int HashTable::getHash(int key){
	return key % MAX;
}

double getFraction(double value){
	return value - (int) value;
}

/*
int _getHash(int key){
	return (int) (MAX*getFraction(A*key));
}
*/

bool HashTable::isFull(){
	return (size >= MAX ? true : false);
}

void HashTable::insert(int value){
	if(isFull()) return;
	int index = getHash(value);
	insertList(&table[index], value);
	size++;
}

int HashTable::search(int key){
	int index = getHash(key);
	return searchList(&table[index], key);
}

void HashTable::print(){
	for(int i = 0; i < MAX; i++){
		cout << i << ": ";
		printList(&table[i]);
		cout << endl;
	}
}

void HashTable::initializeList(List * list){
	list->head = NULL;
	list->lenght = 0;
}

void HashTable::insertList(List * list, int value){
	Node * newNode = (Node *) malloc(sizeof(Node));

	if(newNode){
		newNode->key = value;
		newNode->link = list->head;
		list->head = newNode;
		list->lenght++;
	}

}

int HashTable::searchList(List * list, int value){
	Node * temp = list->head;

	while(temp && temp->key != value)
		temp = temp->link;

	if(temp) return temp->key;

	return 0;
}

void HashTable::printList(List * list){
	Node * temp = list->head;

	while(temp){
		cout << temp->key;
		if(temp->link) cout << " → ";
		temp = temp->link;
	}
}

void HashTable::freeList(List * list){
	Node * previous = list->head;
	Node * current;
	
	while(previous){
		current = previous->link;
		free(previous);
		previous = current;
	}
}