// Priority Queue Implementation
#include "priority_queue.h"

P_Queue::P_Queue(int numItems){
	heap_size = -1;
	array_size = (int)(pow(2, numItems)-1);
	queue = new Node*[array_size];
}

P_Queue::~P_Queue(){
	delete queue;
}

bool P_Queue::isEmpty(){
	return heap_size < 0;
}

bool P_Queue::isFull(){
	return heap_size >= array_size - 1;
}

Node** P_Queue::getArray(){
	return queue;
}

int P_Queue::getArraySize(){
	return array_size;
}

int P_Queue::getHeapSize(){
	return heap_size;
}

Node* P_Queue::getMax(){
	return queue[0];
}

int P_Queue::Left(int i){
	return 2 * (i+1) - 1;
}

int P_Queue::Right(int i){
	return 2 * (i+1);
}

int P_Queue::Parent(int i){
	return max((i+1)/2 - 1, 0);
}

Node* P_Queue::removeMax(){
	if (isEmpty()){
		cout << "Underflow..." << endl;
		Node* n; //Create a blank node and return it
		return n;
	}
	else{
		Node* max = queue[0];
		queue[0] = queue[heap_size];
		heap_size--;
		cout << heap_size << endl;
		maxHeapify(0);
		return max;
	}
}

void P_Queue::maxHeapify(int i){
	int left = Left(i);
	int right = Right(i);
	int largest = i;
	if(left <= heap_size && (queue[left]->getBound() > queue[i]->getBound())){
		largest = left;
	}
	if(right <= heap_size && (queue[right]->getBound() > queue[largest]->getBound())){
		largest = right;
	}
	if(largest != i){
		Node* node = queue[i];
		queue[i] = queue[largest];
		queue[largest] = node;
		maxHeapify(largest);
	}
}

bool P_Queue::insert(Node* nodePtr){
	if(isFull()){
		//cout << isFull() << endl;
		cout << "Overflow..." << endl;
		return false;
	}
	else{
		heap_size++;
		increaseKey(heap_size, nodePtr);
		return true;
	}
}

void P_Queue::increaseKey(int i, Node* key){
	queue[i] = key;
	while((i>1) && queue[Parent(i)]->getBound() < queue[i]->getBound()){
		Node* node = queue[i];
		queue[i] = queue[Parent(i)];
		queue[Parent(i)] = node;
		i = Parent(i);
	}
}