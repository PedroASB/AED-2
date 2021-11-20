#include "min_heap.hpp"

MinHeap::MinHeap(){
	int i;
	for (i = 0; i < MAX; i++)
		data[i] = 0;
	size = 0;
}

int MinHeap::parent(int index){
	return (int) ((index - 1) / 2);
}

int MinHeap::leftChild(int index){
	return (2 * index + 1);
}

int MinHeap::rightChild(int index){
	return (2 * index + 2);
}

void MinHeap::reHeapUp(int index){
	while (index > 0 && data[index] < data[parent(index)]){
		swap(data[index], data[parent(index)]);
		index = parent(index);
	}
}

void MinHeap::reHeapDown(int index){
	int j;

	while (leftChild(index) < size){
		j = leftChild(index);
		
		if (rightChild(index) < size && data[rightChild(index)] < data[j])
			j = rightChild(index);

		if (data[index] < data[j])
			break;
		else {
			swap(data[index], data[j]);
			index = j;
		}
	}

}

void MinHeap::create(){
	int i, value;

	cout << "Heap size: ";
	cin >> size;
	cout << "Enter data: ";

	for (i = 0; i < size; i++){
		cin >> value;
		insert(value);
	}
}

void MinHeap::insert(int value){
	data[size] = value;
	reHeapUp(size);
	size++;
}

void MinHeap::deleteMinValue(){
	data[0] = data[size - 1];
	// data[size - 1] = 0;
	reHeapDown(0);
	size--; // Ideia: O size-- deve vir antes do reHeapDown
}

void MinHeap::print(){
	int i;
	for (i = 0; i < size; i++)
		cout << data[i] << " ";
	cout << endl;
}

void MinHeap::heapify(int heapSize, int index, int flag){
    int lowest = index;
    int left = leftChild(index);
    int right = rightChild(index);

    if (left < heapSize && data[left] < data[lowest])
        lowest = left;

    if (right < heapSize && data[right] < data[lowest])
        lowest = right;

    if (lowest != index) {
        swap(data[index], data[lowest]);
		cout << " ";
		print();
        heapify(heapSize, lowest, flag);
    }
}


void MinHeap::heapSort(){
	int i;
	
	cout << "Before" << endl;
	print();
	for (i = (size - 1) / 2; i >= 0 ; i--){
		heapify(size, i, 0);
	}
	cout << "After" << endl;
	print();

	// cout << endl;
	// print();
	cout << endl;

	for (i = size - 1; i >= 1 ; i--){
		print();
		swap(data[0], data[i]);
		heapify(i, 0, 1);
	}
}
/*
15 13 12 9 11 5 8 3 6 7
13 7 12 9 11 5 8 3 6 15
13 11 12 9 7 5 8 3 6 15
12 11 6 9 7 5 8 3 13 15
12 11 8 9 7 5 6 3 13 15
11 3 8 9 7 5 6 12 13 15
11 9 8 3 7 5 6 12 13 15
9 6 8 3 7 5 11 12 13 15
9 7 8 3 6 5 11 12 13 15
8 7 5 3 6 9 11 12 13 15
7 6 5 3 8 9 11 12 13 15
6 3 5 7 8 9 11 12 13 15
5 3 6 7 8 9 11 12 13 15
3 5 6 7 8 9 11 12 13 15





15 13 12 9 11 5 8 3 6 7 
13 11 12 9 7 5 8 3 6 15 
12 11 8 9 7 5 6 3 13 15 
11 9 8 3 7 5 6 12 13 15 
9 7 8 3 6 5 11 12 13 15 
8 7 5 3 6 9 11 12 13 15 
7 6 5 3 8 9 11 12 13 15 
6 3 5 7 8 9 11 12 13 15 
5 3 6 7 8 9 11 12 13 15 
3 5 6 7 8 9 11 12 13 15

decrescente

3 6 5 9 7 12 8 15 13 11
5 6 11 9 7 12 8 15 13 3
5 6 8 9 7 12 11 15 13 3
6 13 8 9 7 12 11 15 5 3
6 7 8 9 13 12 11 15 5 3
7 15 8 9 13 12 11 6 5 3
7 9 8 15 13 12 11 6 5 3
8 9 11 15 13 12 7 6 5 3
9 12 11 15 13 8 7 6 5 3
11 12 13 15 9 8 7 6 5 3
12 15 13 11 9 8 7 6 5 3
13 15 12 11 9 8 7 6 5 3
15 13 12 11 9 8 7 6 5 3

*/