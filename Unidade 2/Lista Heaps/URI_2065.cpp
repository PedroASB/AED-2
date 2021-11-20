#include <bits/stdc++.h>
#define MAX 10000

// NÃO RESOLVIDO

// g++ URI_2065.cpp -o URI_2065 && ./URI_2065

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
};

// Retorna o maior valor entre x e y
int maxValue(int x, int y);

int main(){
	int N, M, c;
	int tmp, id, time = 0;
	int v[10000];
	PQueue queue;

	cin >> N >> M;

	for (int i = 0; i < N; i++){
		cin >> v[i];
		queue.push(make_pair(0, -i));
	}

	while (M--){
		cin >> c;

		id = -queue.top().second;
		tmp = -queue.top().first;
		
		queue.pop();
		queue.push(make_pair(-(tmp + v[id]*c), -id));

		time = maxValue(time, tmp + v[id]*c);
	}

	cout << time << endl;

	return 0;
}

// Construtor da classe
PQueue::PQueue(){
	int i;
	for (i = 0; i < MAX; i++)
		data[i] = make_pair(0, 0);
	size = 0;
}

// Retorna o índice do pai
int PQueue::parent(int index){
	return (int) ((index - 1) / 2);
}

// Retorna o índice do filho da esquerda
int PQueue::leftChild(int index){
	return (2 * index + 1);
}

// Retorna o índice do filho da direita
int PQueue::rightChild(int index){
	return (2 * index + 2);
}

// ReHeapUp (ShiftUp)
void PQueue::reHeapUp(int index){
	while (index > 0 && data[index].first > data[parent(index)].first){
		swap(data[index].first, data[parent(index)].first);
		index = parent(index);
	}
}

// ReHeapDown (ShiftDown)
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

// Insere um novo elemento
void PQueue::push(pair<int, int> newPair){
	data[size] = make_pair(newPair.first, newPair.second);
	reHeapUp(size);
	size++;
}

// Remove elemento do topo
void PQueue::pop(){
	data[0] = make_pair(data[size - 1].first, 
						data[size - 1].second);
	reHeapDown(0);
	size--;
}

// Retorna o elemento que está no topo
pair<int, int> PQueue::top(){
	return data[0];
}

int maxValue(int x, int y){
	return (x > y ? x : y);
}
