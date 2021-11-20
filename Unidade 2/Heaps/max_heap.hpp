#ifndef __MAX_HEAP_H__
#define __MAX_HEAP_H__

#include <iostream>
#define MAX 255

using namespace std;

class MaxHeap {
	private:
		int data[MAX];
		int size;
		
		int parent(int index);
		int leftChild(int index);
		int rightChild(int index);
		void reHeapUp(int index);
		void reHeapDown(int index);
		
	public:
		MaxHeap();	
		void create();
		void insert(int value);
		void deleteMax();
		void print();
		
		void changePriority(int index, int priority);
		void remove(int index);
		void heapify(int heapSize, int index);
		void heapSort();
};

#endif // __MAX_HEAP_H__