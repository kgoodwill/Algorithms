//Program 1 - Bottom Up LCS Solution

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>

using namespace std;

class LCS{
	public:
		//Constructors & Destructors
		LCS();
		~LCS();
		LCS(int rows, int columns, int size1, int size2, char* aIn, char* bIn);

		//Public Functions
		int find_lcs();
		int subproblem(int i, int j);
		void print_lcs(int i, int j);
		int get_Rows();
		int get_Columns();
		string get_LCS();

	private:
		//Data Members
		int rows;
		int columns;
		int inputASize;
		int inputBSize;
		int** values;
		int** directions;
		char* inputA;
		char* inputB;
		char* lcs;
};

//Default Constructor
LCS::LCS() : inputA(nullptr), inputB(nullptr), inputASize(1), inputBSize(1), rows(1), columns(1){
	LCS(rows, columns, inputASize, inputBSize, inputA, inputB);
}

//Explicit Value Constructor
LCS::LCS(int rows, int columns, int inputSize1, int inputSize2, char* aIn, char* bIn) : inputA(aIn), inputB(bIn), inputASize(inputSize1), inputBSize(inputSize2), rows(rows), columns(columns){
	values = new int*[rows];
	for(int i=0; i<rows; i++){values[i] = new int[columns];}
	directions = new int*[rows];
	for(int i=0; i<rows; i++){directions[i] = new int[columns];}
}

LCS::~LCS(){
	//Deallocate matrices
}

int LCS::get_Rows(){return rows;}
int LCS::get_Columns(){return columns;}
string LCS::get_LCS(){return lcs;}

int LCS::find_lcs(){
	//Initialize values matrix to -1
	for(int i=0; i<rows; i++){
		for(int j=0; j<columns; j++){
			values[i][j] = -1;
		}
	}
	return subproblem(0,0);
}

int LCS::subproblem(int i, int j){
	if(values[i][j] < 0){
		if(inputA[i] == '\0' || inputB[j] == '\0'){values[i][j] = 0;}
		else if(inputA[i] == inputB[j]){
			values[i][j] = 1 + subproblem(i+1, j+1);
		}
		else{
			values[i][j] = max(subproblem(i+1, j), subproblem(i, j+1));
		}
	}
	return values[i][j];
}
	

string get_input(ifstream* file){
	int count = 0;
	string line = "";
	getline(*file, line);
	return line;
}

int main(int argc, char* argv[]){
	if (argc != 4){
		cout << "Correct Syntax: program3 <input_file_1> <input_file_2> <output_file>" << endl;
		return -1;
	}
	ifstream inFile1 (argv[1]);
	ifstream inFile2 (argv[2]);
	ofstream outfile (argv[3]);

	//Determine the size of each file
	if (!inFile1.is_open() || !inFile2.is_open()){
		cout << "ERROR: One of the input files doesn't exist" << endl;
		return -2;
	}
	string input1;
	string input2;
	inFile1 >> input1;
	inFile2 >> input2;
	int inputALength = input1.length();
	int inputBLength = input2.length();	
	int rowsize = inputALength + 1;
	int colsize = inputBLength + 1;
	char* cinput1 = (char*)input1.c_str();
	char* cinput2 = (char*)input2.c_str();

	//Create a LCS object
	LCS* myLCS = new LCS(rowsize, colsize, inputALength, inputBLength, cinput1, cinput2);
	clock_t t;
	t = clock();
	int lcs_size = myLCS->find_lcs();
	t = clock() - t;
	outfile << lcs_size << endl;
	outfile << ((float)t)/CLOCKS_PER_SEC << endl;
	return 0;
}