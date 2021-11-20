#ifndef __HASH_HPP__
#define __HASH_HPP__

#include <iostream>
using namespace std;

#define MAX 11
#define A 0.618

typedef struct node {
	int key;
	struct node * link;
} Node;

typedef struct list {
	int lenght;
	Node * head;
} List;

class HashTable {
	private:
		int size;
		List table[MAX];

		int getHash(int key);
		void initializeList(List * list);
		void insertList(List * list, int value);
		int searchList(List * list, int value);
		void printList(List * list);
		void freeList(List * list);

	public:
		HashTable();
		~HashTable();

		bool isFull();
		void insert(int value);
		int search(int key);
		void print();
};

#endif // __HASH_HPP__