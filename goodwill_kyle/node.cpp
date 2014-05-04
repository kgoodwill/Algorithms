//Node Implementation
#include "node.h"

Node::Node(){
	weight = 0;
	profit = 0;
	level = 0;
	ratio = 0;
	bound = 0.0;
}

Node::Node(int weightIn, int profitIn){
	weight = weightIn;
	profit = profitIn;
	level = 0;
	bound = 0.0;
	ratio = weight/profit;
}

Node::~Node(){
	//Nothing to put here as no dynamic memory is needed
}

float Node::getBound(){
	return bound;
}

int Node::getRatio(){
	return ratio;
}

int Node::getProfit(){
	return profit;
}

int Node::getWeight(){
	return weight;
}

int Node::getLevel(){
	return level;
}

void Node::setWeight(int i){
	weight = i;
}

void Node::setProfit(int i){
	profit = i;
}

void Node::setLevel(int i){
	level = i;
}

void Node::setBound(float f){
	bound = f;
}