#include "max_heap.hpp"

MaxHeap::MaxHeap(){
	int i;
	for (i = 0; i < MAX; i++)
		data[i] = 0;
	size = 0;
}

int MaxHeap::parent(int index){
	return (int) ((index - 1) / 2);
}

int MaxHeap::leftChild(int index){
	return (2 * index + 1);
}

int MaxHeap::rightChild(int index){
	return (2 * index + 2);
}

void MaxHeap::reHeapUp(int index){
	while (index > 0 && data[index] > data[parent(index)]){
		swap(data[index], data[parent(index)]);
		index = parent(index);
	}
}

void MaxHeap::reHeapDown(int index){
	int j;

	while (leftChild(index) < size){
		j = leftChild(index);
		
		if (rightChild(index) < size && data[rightChild(index)] > data[j])
			j = rightChild(index);

		if (data[index] > data[j])
			break;
		else {
			swap(data[index], data[j]);
			index = j;
		}
	}

}

void MaxHeap::heapify(int heapSize, int index){
    int largest = index;
    int left = leftChild(index);
    int right = rightChild(index);

    if (left < heapSize && data[left] > data[largest])
        largest = left;

    if (right < heapSize && data[right] > data[largest])
        largest = right;

    if (largest != index) {
        swap(data[index], data[largest]);
        heapify(heapSize, largest);
    }
}

void MaxHeap::create(){
	int i, value;

	cout << "Heap size: ";
	cin >> size;
	cout << "Enter data: ";

	for (i = 0; i < size; i++){
		cin >> value;
		insert(value);
	}
}

void MaxHeap::insert(int value){
	data[size] = value;
	reHeapUp(size);
	size++;
}

void MaxHeap::deleteMax(){
	data[0] = data[size - 1];
	data[size - 1] = 0;
	reHeapDown(0);
	size--;
}

void MaxHeap::print(){
	int i;
	for (i = 0; i < size; i++)
		cout << data[i] << " ";
	cout << endl;
}

void MaxHeap::changePriority(int index, int priority){
    int oldPriority = data[index];
    data[index] = priority;
 
    if (priority > oldPriority)
        reHeapUp(index);
    else
        reHeapDown(index);
}

void MaxHeap::remove(int index){
    data[index] = data[0] + 1;
    reHeapUp(index);
	deleteMax();
}

void MaxHeap::heapSort(){
	int i;
	for (i = (size - 1) / 2; i >= 0 ; i--){
		heapify(size, i);
	}

	for (i = size - 1; i >= 1 ; i--){
		swap(data[0], data[i]);
		heapify(i, 0);
	}
}