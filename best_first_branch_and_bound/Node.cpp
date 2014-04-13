//Node Implementation File
#include "Node.h"

// Creates a default Node
Node::Node(){
	// left = NULL;
	// right = NULL;
	bound = 0;
	ratio = 0;
	weight = 0;
	profit = 0;
}

Node::Node(int weight, int profit){
	// left = NULL;
	// right = NULL;
	bound = 0; //Bound can only be set from a KWF solution
	this->profit = profit;
	this->weight = weight;
	this->ratio = profit/weight;
}

Node::Node(const Node& sourceNode){
	this->bound = sourceNode.bound;
	this->ratio = sourceNode.ratio;
	this->weight = sourceNode.weight;
	this->profit = sourceNode.profit;
}

Node::~Node(){

}

Node& Node::operator=(const Node& sourceNode){
	bound = sourceNode.bound;
	ratio = sourceNode.ratio;
	weight = sourceNode.weight;
	profit = sourceNode.profit;
	return *this;
}

/* Getters and Setters */

//ratio
float Node::get_ratio(){
	return this->ratio;
}

void Node::set_ratio(int ratioIn){
	this->ratio = ratioIn;
}

//bound
int Node::get_bound(){
	return this->bound;
}

void Node::set_bound(int boundIn){
	this->bound = boundIn;
}

//weight
int Node::get_weight(){
	return this->weight;
}

void Node::set_weight(int weightIn){
	this->weight = weightIn;
}

//profit
int Node::get_profit(){
	return this->profit;
}

void Node::set_profit(int profitIn){
	this->profit = profitIn;
}

int* calculate_bound(int i, int weightSoFar, Node** itemList, int capacity, int numItems){
	int knapsack[numItems];
	for(int j = i; j < numItems; j++){ //Initialize the knapsack to 0
		knapsack[j] = 0; 
	}
	while(weightSoFar < capacity && i <= numItems){
		if(weightSoFar + itemList[i]->get_weight() <= capacity){
			knapsack[i] = 1; //Item placed into the knapsack
			weightSoFar = weightSoFar + itemList[i]->get_weight();
		}
		else{
			knapsack[i] = (capacity - weightSoFar)/itemList[i]->get_weight();
			weightSoFar = capacity;
		}
		i++;
	}
	return knapsack;
}