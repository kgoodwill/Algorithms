//Priority Queue Header
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include "node.h"

using namespace std;

class P_Queue{
public:
	// P_Queue();
	P_Queue(int numItems);
	~P_Queue();
	bool isEmpty();
	bool isFull();
	int getArraySize();
	int getHeapSize();
	Node** getArray();
	Node* getMax();
	Node* removeMax();
	bool insert(Node*);
private:
	// Data Members
	Node** queue; //Array of node pointers
	int array_size;
	int heap_size;

	int Left(int i);
	int Right(int i);
	int Parent(int i);
	void increaseKey(int, Node*);
	void maxHeapify(int);
};

#endif //PRIORITY_QUEUE_H