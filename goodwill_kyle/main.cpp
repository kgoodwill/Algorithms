//Main.cpp
#include "node.h"
#include "priority_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <sstream>
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

int CAPACITY;
int NUM_ITEMS;

vector<Node*> knapsack(const int p[], const int w[], int W, int maxProfit);
float bound(Node* node, const int w[], const int p[]);


int main(int argc, char* argv[]){
	if(argc != 3){
		cout << "Usage: ./BestFirstSearch <input_file> <output_file>" << endl;
		return -1;
	}
	ifstream infile;
	ofstream outfile;
	infile.open(argv[1]);
	outfile.open(argv[2]);

	string myString;
	stringstream myStream;
	// int numItems; //Number of items in the input
	// int capacity; //Capacity of the knapsack
	char dummyVar;
	getline(infile, myString);
	myStream << myString;
	myStream >> NUM_ITEMS >> dummyVar >> CAPACITY;

	int profit[NUM_ITEMS];
	int weight[NUM_ITEMS];
	int i = 0;

	while(!infile.eof() && i <= NUM_ITEMS){
		string newString;
		stringstream newStream;
		getline(infile, newString);
		//cout << newString << endl;
		newStream << newString;
		//cout << newStream << endl;
		newStream >> weight[i] >> dummyVar >> profit[i];
		// cout << weight << " " << profit << endl;
		i++;
	}

	//P_Queue* mypq = new P_Queue(NUM_ITEMS);
	//best_first_branch_n_bound(mypq, 0);
	/*Nothing in the array to access yet -__- */

	// P_Queue notPtr = *mypq;
	// Node** array = notPtr.getArray();
	// for(int i = 0; i < pow(2, numItems)-1; i++){
	// 	cout << array[i]->getRatio() << endl;
	// }


	//Sort the itemList by non-increasing profit/weight ratio


	//Need to calculate the bound of each node in the priority queue

	vector<Node*> myResults = knapsack(profit, weight, CAPACITY, 0);
	cout << "Size: " << myResults.size() << endl;

	infile.close();
	outfile.close();
	return 0;
}

// Node* quickSort(Node* nodeArray, int arraySize){
// 	if(arraySize <= 1){
// 		return nodeArray;
// 	}
// }


// Computes the bound for the current node
float bound(Node* node, const int w[], const int p[]){
	int j, k; //Indexes
	int totalWeight;
	float result;
	if(node->getWeight() >= CAPACITY){
		return 0;
	}
	else{
		result = node->getProfit();
		j = node->getLevel() + 1;
		totalWeight = node->getWeight();
		while(j <= NUM_ITEMS && totalWeight + w[j] <= CAPACITY){
			totalWeight = totalWeight + w[j];
			result = result + p[j];
			j++;
		}
		k=j;
		if(k<=NUM_ITEMS){
			result = result + (CAPACITY - totalWeight) * p[k]/w[k];
		}
		return result;
	}
}

vector<Node*> knapsack(const int p[], const int w[], int W, int maxProfit){
	P_Queue* myQueue = new P_Queue(NUM_ITEMS);
	vector<Node*> results;
	Node u, v;
	v.setLevel(0);
	v.setProfit(0);
	v.setWeight(0);
	maxProfit = 0;
	v.setBound(bound(&v, w, p));
	//
	cout << "Bound: " << v.getBound() << endl;
	//
	myQueue->insert(&v);
	while(!myQueue->isEmpty()){
		results.push_back(myQueue->removeMax());
		cout << myQueue->getHeapSize() << endl;
		cout << "maxProfit: " << maxProfit << endl;
		if((v.getBound()) > maxProfit){
			u.setLevel(v.getLevel() + 1);
			u.setWeight(v.getWeight() + w[u.getLevel()]);
			u.setProfit(v.getProfit() + p[u.getLevel()]);
			if(((u.getWeight()) <= W) && ((u.getProfit()) > maxProfit)){
				maxProfit = u.getProfit();
			}
			u.setBound(bound(&u, w, p));
			if((u.getBound()) > maxProfit){
				myQueue->insert(&u);
			}
			u.setWeight(v.getWeight());
			u.setProfit(v.getProfit());
			u.setBound(bound(&u, w, p));
			if((u.getBound()) > maxProfit){
				myQueue->insert(&u);
			}
		}
	}
	return results;
}

void ghetto_sort(int* profit, int* weight, int numItems){
	int i = 0;
	while(i < numItems - 1){
		if(profit[i]/weight[i] < profit[i+1]/weight[i+1]){
			int tmp_profit = profit[i+1];
			int tmp_weight = weight[i+1];
			profit[i+1] = profit[i];
			weight[i+1] = weight[i];
			profit[i] = tmp_profit;
			weight[i] = tmp_weight;
		}
	}
}