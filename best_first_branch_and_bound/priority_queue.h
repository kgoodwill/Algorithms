//This is the header for the priority queue class for the best first branch and bound algorithm
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "Node.h"

using namespace std; 

class P_Queue
{
public:
	P_Queue();
	P_Queue(Node* array, int arraySize);
	~P_Queue();
	void push(Node* node);
	Node* pop();
	bool isEmpty();

private:
	//Data Members
	Node* p_Queue; //an array of nodes
	//Functions
	Node* buildMaxHeap(Node* nodeArray, int arraySize);
	void clearMaxHeap();
	void maxHeapify(Node* A, int i, int n);
	inline int getLeft(int i);
	inline int getRight(int i);
	inline int getParent(int i);
};

#endif //PRIORITY_QUEUE_H