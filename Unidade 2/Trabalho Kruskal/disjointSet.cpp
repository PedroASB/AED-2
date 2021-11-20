#include "disjointSet.hpp"

/**
 * Função construtora (sem parâmetro)
 */
DisjointSet::DisjointSet(){
	this->size = 0;
}

/**
 * Função construtora (com parâmetro)
 *
 * @param (int) size: tamanho do conjunto
 */
DisjointSet::DisjointSet(int size){
	this->size = size;
	
	this->ranks.resize(size);
	this->parents.resize(size);

	for(int i = 0; i < size; i++){
		this->parents[i] = i;
		this->ranks[i] = 1;
	}
	
}

/**
 * Faz a união de dois conjuntos disjuntos
 *
 * @param (int) child1: elemento de um conjunto
 * @param (int) child2: elemento de um conjunto
 */
void DisjointSet::join(int child1, int child2){
	int parent1 = this->find(child1);
	int parent2 = this->find(child2);
	
	if (parent1 != parent2){
		if (this->ranks[parent1] < this->ranks[parent2]){
			std::swap(parent1, parent2);
		}
		this->ranks[parent1] += this->ranks[parent2];
		this->parents[parent2] = parent1;
	}
	
}

/**
 * Faz a busca do representante do conjunto
 *
 * @param (int) child: elemento de um conjunto
 * @return (int) representante
 */
int DisjointSet::DisjointSet::find(int child){
	if (child != this->parents[child]){
		this->parents[child] = this->find(parents[child]);
	}
	return this->parents[child];
}

/**
 * Imprime os ranks e os representantes de cada conjunto
 *
 */
void DisjointSet::print(){
	using namespace std;
	cout << this->size << endl;
	cout << "------------" << endl;
	cout << "Ranks" << endl;
	for(int i = 0; i < this->size; i++){
		cout << this->ranks[i] << " ";
	}
	cout << endl << "Parents" << endl;
	for(int i = 0; i < this->size; i++){
		cout << this->parents[i] << " ";
	}
	cout << endl;
}

/**
 * Retorna a quantidade de elementos
 *
 * @return (int) tamanho
 */
int DisjointSet::getSize(){
	return this->size;	
}