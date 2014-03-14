//Program 1 - Bottom Up
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
		int find_lcs();
		void print_lcs(int i, int j, ofstream* outfile);
		int get_Rows();
		int get_Columns();
		string get_LCS();
		int get_Size(char in);
		void print_matrix(ofstream* outfile);

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

int LCS::get_Size(char in){
	if(in == 'a'){return inputASize;}
	else if(in == 'b'){return inputBSize;}
	else{return -1;}
}

int LCS::find_lcs(){
	for(int i=inputASize; i>=0; i--){
		for(int j=inputBSize; j>=0; j--){
			if(inputA[i] == '\0' || inputB[j] == '\0'){
				values[i][j] = 0;
			}
			else if(inputA[i] == inputB[j]){
				values[i][j] = 1 + values[i+1][j+1];
			}
			else{
				values[i][j] = max(values[i+1][j], values[i][j+1]);
			}
		}
	}
	return values[0][0];
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

void LCS::print_matrix(ofstream* outfile){
	for(int i=0; i<rows; i++){
		for(int j=0; j<columns; j++){
			*outfile << values[i][j] << " ";
		}
		*outfile<<endl;
	}
}

int main(int argc, char* argv[]){
	if (argc != 4){
		cout << "Correct Syntax: program1 <input_file_1> <input_file_2> <output_file>" << endl;
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
	clock_t begin = clock();
	int lcs_size = myLCS->find_lcs();
	clock_t end = clock();
	double elapsed_secs = double(end - begin)/CLOCKS_PER_SEC;

	if(myLCS->get_Rows() < 10 && myLCS->get_Columns() < 10){
		myLCS->print_matrix(&outfile);
		myLCS->print_lcs(myLCS->get_Size('a'), myLCS->get_Size('b'), &outfile);
		outfile << endl;
		outfile << elapsed_secs << endl;
	}
	else{
		outfile << lcs_size << endl;
		outfile << elapsed_secs << endl;
	}

	return 0;
}