#ifndef __MIN_HEAP_H__
#define __MIN_HEAP_H__

#include <iostream>
#define MAX 255

using namespace std;

class MinHeap {
	private:
		int data[MAX];
		int size;
		
		int parent(int index);
		int leftChild(int index);
		int rightChild(int index);
		void reHeapUp(int index);
		void reHeapDown(int index);
		
	public:
		MinHeap();	
		void create();
		void insert(int value);
		void deleteMinValue();
		void print();
		
		void heapify(int heapSize, int index, int flag);
		void heapSort();
};

#endif // __MIN_HEAP_H__