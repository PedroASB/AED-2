#ifndef __PRIORITY_QUEUE_HPP__
#define __PRIORITY_QUEUE_HPP__

#include <iostream>
#define MAX 10000

using namespace std;

class PQueue {
	private:
		pair<int, int> data[MAX];
		int size;
		
		int parent(int index);
		int leftChild(int index);
		int rightChild(int index);
		void reHeapUp(int index);
		void reHeapDown(int index);
		
	public:
		PQueue();
		void push(pair<int, int> newPair);
		void pop();
		void print();
		pair<int, int> top();
		
		void changePriority(int index, int priority);
		void remove(int index);
};

#endif // __PRIORITY_QUEUE_HPP__