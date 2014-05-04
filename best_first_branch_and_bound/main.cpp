//Main.cpp
#include "Node.h"
#include "priority_queue.h"
#include "heap.h"
#include <fstream>
#include <string.h>
#include <sstream>

using namespace std;

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
	int numItems; //Number of items in the input
	int capacity; //Capacity of the knapsack
	char dummyVar;
	getline(infile, myString);
	myStream << myString;
	myStream >> numItems >> dummyVar >> capacity;

	Node itemList[numItems]; //List of items from input
	int i = 0;

	while(!infile.eof() && i <= numItems){
		string newString;
		stringstream newStream;
		int weight;
		int profit;
		getline(infile, newString);
		//cout << newString << endl;
		newStream << newString;
		//cout << newStream << endl;
		newStream >> weight >> dummyVar >> profit;
		Node* node = new Node(weight, profit); //Create a new node to add to itemList
		itemList[i] = *node;
		i++;
	}


	//Sort the itemList by non-increasing profit/weight ratio

	//Create an empty priority queue
	P_Queue* pq = new P_Queue(itemList, numItems);

	//Need to calculate the bound of each node in the priority queue


	//infile.close();
	//outfile.close();
	return 0;
}