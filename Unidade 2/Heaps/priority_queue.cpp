#include "priority_queue.hpp"

PQueue::PQueue(){
	int i;
	for (i = 0; i < MAX; i++)
		data[i] = make_pair(0, 0);
	size = 0;
}

int PQueue::parent(int index){
	return (int) ((index - 1) / 2);
}

int PQueue::leftChild(int index){
	return (2 * index + 1);
}

int PQueue::rightChild(int index){
	return (2 * index + 2);
}

void PQueue::reHeapUp(int index){
	while (index > 0 && data[index].first > data[parent(index)].first){
		swap(data[index].first, data[parent(index)].first);
		index = parent(index);
	}
}

void PQueue::reHeapDown(int index){
	int j;

	while (leftChild(index) < size){
		j = leftChild(index);
		
		if (rightChild(index) < size && data[rightChild(index)].first > data[j].first)
			j = rightChild(index);

		if (data[index].first > data[j].first)
			break;
		else {
			swap(data[index].first, data[j].first);
			index = j;
		}
	}

}

void PQueue::push(pair<int, int> newPair){
	data[size] = make_pair(newPair.first, newPair.second);
	reHeapUp(size);
	size++;
}

void PQueue::pop(){
	data[0] = make_pair(data[size - 1].first, 
						data[size - 1].second);
	// data[size - 1] = make_pair(0, 0);
	reHeapDown(0);
	size--; // ANTES DO reHeapDown
}

void PQueue::print(){
	int i;
	for (i = 0; i < size; i++)
		cout << data[i].first << "/" << data[i].second << " ";
	cout << endl;
}

pair<int, int> PQueue::top(){
	return data[0];
}

/*
void PQueue::changePriority(int index, int priority){
    int oldPriority = data[index].first;
    data[index].first = priority;
 
    if (priority > oldPriority)
        reHeapUp(index);
    else
        reHeapDown(index);
}

void PQueue::remove(int index){
    data[index].first = data[0].first + 1;
    reHeapUp(index);
	pop();
}
*/