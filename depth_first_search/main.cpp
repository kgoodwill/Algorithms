#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <list>
#include <time.h>

using namespace std;

enum color_t {NONE, WHITE, GRAY, BLACK};
int TIME;

class Node{
	color_t color;
	Node* parent;
	int discovery_time;
	int finish_time;
public:
	Node();
	void changeColor(color_t newColor);
	color_t getColor();
	void setDTime(int timeIn);
	void setFTime(int timeIn);
	void setParent(Node parentNode);
	int getDTime();
	int getFTime();
};

Node::Node(){
	color = NONE;
	parent = NULL;
}

void Node::changeColor(color_t newColor){
	color = newColor;
}

color_t Node::getColor(){
	return color;
}

void Node::setDTime(int timeIn){
	discovery_time = timeIn;
}

void Node::setFTime(int timeIn){
	finish_time = timeIn;
}

void Node::setParent(Node parentNode){
	parent = &parentNode;
}

int Node::getDTime(){
	return discovery_time;
}

int Node::getFTime(){
	return finish_time;
}

class Graph{
	int numVertex; //The number of vertices in the graph
	list<int>* adj; //Adjacency list for the graph, an array of lists
	Node* nodes;
	void DFS_VISIT(int u);
public:
	Graph(int V);
	void addEdge(int v, int w); //Adds an edge to the graph
	void addNode(int spot);
	void DFS(); //DFS search of the vertices reachable from Node v
	void printTraversal();
	void printAdj();
};

Graph::Graph(int V){
	numVertex = V;
	adj = new list<int>[numVertex+1];
	nodes = new Node[numVertex+1];
	for(int i = 0; i < numVertex+1; i++){
		Node* node = new Node();
		nodes[i] = *node;
	}
}

void Graph::addEdge(int v, int w){
	if(nodes[v].getColor() != WHITE){
		nodes[v].changeColor(WHITE);
	}
	if(nodes[w].getColor() != WHITE){
		nodes[w].changeColor(WHITE);
	}
	adj[v].push_back(w);
	//cout << "Edge " << v << "," << w << " added" << endl;
}

void Graph::addNode(int spot){
	if(nodes[spot].getColor() == NONE){
		nodes[spot].changeColor(WHITE);	
		//cout << "Node added at: " << spot << endl;
	}
	else{
		//cout << "Node already exists" << endl;
	}
}

void Graph::DFS(){
	TIME = 0;
	for(int i = 1; i < numVertex+1; i++){
		if(nodes[i].getColor() == WHITE){
			this->DFS_VISIT(i);
		}
	}
}

void Graph::DFS_VISIT(int u){
	TIME = TIME + 1;
	nodes[u].setDTime(TIME);
	nodes[u].changeColor(GRAY);
	//cout << "Node: " << u << " Discovery Time: " << TIME << " Color: " << nodes[u].getColor() << endl;
	// cout << "List Size at " << u << ": " << adj[u].size() << endl;
	list<int>::iterator v;
	for(v = adj[u].begin(); v != adj[u].end(); v++){
		// cout << *v << endl;
		// cout << "Color: " << nodes[*v].getColor() << endl;
		if(nodes[*v].getColor() == WHITE){
			// cout << "WHITE node found" << endl;
			nodes[*v].setParent(nodes[u]);
			DFS_VISIT(*v);
		}
	}
	nodes[u].changeColor(BLACK);
	TIME = TIME + 1;
	nodes[u].setFTime(TIME);
	// cout << "Node: " << u << " Finish Time: " << TIME << " Color: " << nodes[u].getColor() << endl;
}

//Prints the traversal to the screen
void Graph::printTraversal(){
	cout << "Node: D/F" << endl;
	for(int i = 1; i < numVertex+1; i++){
		cout << i << ": " << nodes[i].getDTime() << "/" << nodes[i].getFTime() << endl;
	}
}

void Graph::printAdj(){
	for(int i = 0; i < numVertex+1; i++){
		cout << i << ": ";
		list<int>::iterator j;
		for(j = adj[i].begin(); j != adj[i].end(); j++){
			cout << *j << " ";
		}
		cout << endl;
	}
}

int main(int argc, char* argv[]){
	if(argc != 3)

	{
		cout << "Usage Error: ./DepthFirstSearch <input_file> <output_file>" << endl;
		return -1;
	}

	ifstream inFile;
	ofstream outFile;
	inFile.open(argv[1]);
	outFile.open(argv[2]);

	string myString;
	stringstream myStream;
	int sizeList;
	char dummyVar; 

	if(!inFile.is_open() || !outFile.is_open()){
		cout << "Unable to open one of the files" << endl;
		return -2;
	}
	getline(inFile, myString);
	myStream << myString;
	myStream >> sizeList;
	myStream.clear();

	//Create a graph
	Graph* graph = new Graph(sizeList);

	int place = 0;
	while(!inFile.eof()){
		myStream.clear();
		int start_pos;
		int end_pos;
		getline(inFile, myString);
		myStream << myString;
		myStream >> start_pos >> dummyVar >> end_pos;
		graph->addEdge(start_pos, end_pos);
		graph->addNode(start_pos);
	}

	graph->printAdj();
	clock_t t;
	t = clock();
	graph->DFS();
	t = clock() - t;
	graph->printTraversal();
	cout << "Time: " << (float)t << endl;

	return 0;
}