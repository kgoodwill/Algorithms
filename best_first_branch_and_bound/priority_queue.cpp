//This is the implementation for the priority queue class
#include "priority_queue.h"

/* Public Methods for PQ */
P_Queue::P_Queue(){
	//Initialize the array to NULL for default
}


//Takes in a ptr to an array of nodes
P_Queue::P_Queue(Node* array, int arraySize){
	// p_Queue = new Node[(2**arraySize)-1];
	p_Queue = buildMaxHeap(array, arraySize);
	// for(int i = 0; i < arraySize; i++){
	// 	cout << p_Queue[i].get_weight() << endl;
	// }
}

P_Queue::~P_Queue(){
	clearMaxHeap();
}

/* Private Methods for PQ */
void P_Queue::push(Node* node){

}

Node* P_Queue::pop(){
	return 0;
}

Node* P_Queue::buildMaxHeap(Node* nodeArray, int arraySize){
	int returnSize = pow(2, arraySize) - 1;
	cout << "returnSize = " << returnSize << endl;
	Node* returnArray = new Node[returnSize];
	//Add elements from nodeArray to returnArray(aka priority_queue)
	for(int i = 0; i < arraySize; i++){
		returnArray[i] = nodeArray[i];
	}
	for(int i = floor(returnSize/2); i > 1; i--){
		maxHeapify(returnArray, i, returnSize);
	}
	for(int i = 0; i < returnSize; i++){
		cout << returnArray[i].get_ratio() << endl;
	}
	return returnArray;
}

/* Private Methods for PQ */
void P_Queue::maxHeapify(Node* A, int i, int n){
	int largest;
	int left = getLeft(i);
	int right = getRight(i);
	if(left <= n && A[left].get_ratio() > A[n].get_ratio()){
		largest = left;
	}
	else{
		largest = i;
	}
	if(right <= n && A[right].get_ratio() > A[largest].get_ratio()){
		largest = right;
	}
	if(largest != i){
		//Swap A[largest] and A[i]
		swap(A[largest], A[i]);
		maxHeapify(A, largest, n);
	}
}

void swap(Node* a, Node* b){
	Node* tmp = new Node();
	tmp = a;
	a = b;
	b = tmp;
	delete tmp;
	// //weight
	// // profit
	// // bound
	// // key

	// //Set values for tmp
	// tmp->set_weight(a->get_weight());
	// tmp->set_profit(a->get_profit());
	// tmp->set_bound(a->get_bound());
	// tmp->set_key(a->get_ratio());

	// //Set values of a to those of b
	// a->set_weight(b->get_weight());
	// a->set_profit(b->get_profit());
	// a->set_bound(b->get_bound());
	// a->set_key(b->get_ratio());

	// //Set values of b to those of tmp
	// b->set_weight(tmp->get_weight());
	// b->set_profit(tmp->get_profit());
	// b->set_bound(tmp->get_bound());
	// b->set_key(tmp->get_ratio());

	// //Delete tmp
	// delete tmp;
}

inline int P_Queue::getLeft(int i){
	return 2*i;
}

inline int P_Queue::getRight(int i){
	return 2*i + 1;
}

inline int P_Queue::getParent(int i){
	return floor(i/2);
}

void P_Queue::clearMaxHeap(){
	//Keeping popping and discarding nodes until empty
	Node* dummy;
	while(!isEmpty()){
		dummy = pop();
	}
}

bool P_Queue::isEmpty(){
	if(p_Queue[0].get_weight() == 0){
		return false;
	}
	else{return true;}
}