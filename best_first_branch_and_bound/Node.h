//Node Header File
#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Node{
public:
	Node();
	Node(int weight, int profit);
	Node(const Node& sourceNode);
	~Node();
	// Node* get_left();
	// void set_left(Node* node);
	// Node* get_right();
	// void set_right(Node* node);
	float get_ratio();
	void set_ratio(int ratioIn);
	int get_bound();
	void set_bound(int boundIn);
	int get_weight();
	void set_weight(int weightIn);
	int get_profit();
	void set_profit(int profitIn);
	Node& operator=(const Node& sourceNode);
private:
	// Node* left;
	// Node* right;
	int ratio;
	int bound;
	int weight;
	int profit;

	//Calculates the bound of a node by solving KWF
	int* calculate_bound(int i, int weightSoFar, Node** itemList, int capacity, int numItems);
};

#endif //NODE_H