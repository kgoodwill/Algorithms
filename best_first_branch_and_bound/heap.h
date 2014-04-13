//Heap Header File
#ifndef HEAP
#define HEAP

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Node.h"

//Class for a max-heap
class Heap{
public:
	/*Public Functions*/
	Heap();
	~Heap();
private:
	/*Private Data Members*/
	Node* node_array;
	/*Private Functions*/
	void insert();
	int size();
	bool isEmpty();
	int get_largest();
	void remove_largest();
};

#endif //HEAP