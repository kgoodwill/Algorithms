//Recursive
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>
#include <algorithm>

using namespace std;

class LCS{
	public:
		//Constructors & Destructors
		LCS();
		~LCS();
		LCS(int rows, int columns, int size1, int size2, char* aIn, char* bIn);

		//Public Functions
		int find_lcs(int i, int j);
		void print_lcs(int i, int j, ofstream* outfile);
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

int LCS::find_lcs(int i, int j){
	if(inputA[i] == '\0' || inputB[j] == '\0'){
		return 0;
	}
	if(inputA[i] == inputB[j]){
		return values[i][j] = find_lcs(i+1, j+1) + 1;
	}
	else{
		return values[i][j] = max(find_lcs(i+1, j),find_lcs(i, j+1));
	} 
}

void LCS::print_lcs(int i, int j, ofstream* outfile){
	if (i == 0 || j == 0){
		return;
	}
	if (directions[i][j] == 2){
		print_lcs(i-1, j-1, outfile);
		*outfile << " " << inputA[i-1];
	}
	else if (directions[i][j] == 3){
		print_lcs(i-1, j, outfile);
	}
	else{
		print_lcs(i, j-1, outfile);
	}
}

int main(int argc, char* argv[]){
	if (argc != 4){
		cout << "Correct Syntax: program2 <input_file_1> <input_file_2> <output_file>" << endl;
		return -1;
	}
	ifstream inFile1 (argv[1]);
	ifstream inFile2 (argv[2]);
	ofstream outfile (argv[3]);

	//Determine the size of each file
	if (!inFile1.is_open() || !inFile2.is_open() || !outfile.is_open()){
		cout << "ERROR: One of the files doesn't exist" << endl;
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
	int lcs_size = 0;
	clock_t begin = clock();
	lcs_size = myLCS->find_lcs(0, 0);
	clock_t end = clock();
	double elapsed_secs = double(end - begin)/CLOCKS_PER_SEC;
	outfile << lcs_size << endl;
	outfile << elapsed_secs << endl;
	return 0;
}