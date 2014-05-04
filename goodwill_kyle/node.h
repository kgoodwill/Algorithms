//Node Header
#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Node{
public:
	Node();
	Node(int profitIn, int weightIn);
	~Node();
	int getRatio();
	float getBound();
	int getProfit();
	int getWeight();
	int getLevel();
	void setWeight(int);
	void setLevel(int);
	void setProfit(int);
	void setBound(float);
private:
	int profit;
	int weight;
	int level;
	int ratio;
	float bound;
};

#endif //NODE_H