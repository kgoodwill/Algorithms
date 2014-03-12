//Program 1 - Bottom Up LCS Solution

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class LCS{
	public:
		//Constructors & Destructors
		LCS();
		~LCS();
		LCS(int rows, int columns, char* aIn, char* bIn);

		//Public Functions
		void find_lcs(int rows, int columns);

	private:
		//Data Members
		int** values;
		int** directions;
		const char* inputA;
		const char* inputB;

		void lcs_iterate();

};

//Default Constructor
LCS::LCS() : inputA(nullptr), inputB(nullptr){
	values = new int*[1];
	for(int i=0; i < 1; i++){values[i] = new int[1];}
	directions = new int*[1];
	for(int i=0; i<1; i++){directions[i] = new int[1];}
}

LCS::LCS(int rows, int columns, char* aIn, char* bIn) : inputA(aIn), inputB(bIn){
	values = new int*[rows];
	for(int i=0; i<rows; i++){values[i] = new int[columns];}
	directions = new int*[rows];
	for(int i=0; i<rows; i++){directions[i] = new int[columns];}
}

void LCS::find_lcs(int rows, int columns){
	//Initialize row and column 0 of values matrix to 0
	for(int i=0; i<rows; i++){values[i][0] = 0;}
	for(int i=0; i<columns; i++){values[0][i] = 0;}

	for(int i=1; i<rows; i++){
		for(int j=1; j<columns; j++){
			if(1 == 1){

			}
		}
	}
}



//int file_size(ifstream* file);

string get_input(ifstream* file){
	int count = 0;
	string line;
	string new_line;
	while(getline(*file, new_line)){
		line += new_line;
	}
	return line;
}

int main(int argc, char* argv[]){
	if (argc != 3){
		cout << "Correct Syntax: program1 <input_file_1> <input_file_2> <output_file>" << endl;
		return -1;
	}
	ifstream inFile1 (argv[0]);
	ifstream inFile2 (argv[1]);

	//Determine the size of each file
	if (!inFile1.is_open() || !inFile2.is_open()){
		cout << "ERROR: One of the input files doesn't exist" << endl;
		return -2;
	}
	string input1 = get_input(&inFile1);
	string input2 = get_input(&inFile2);
	char* cinput1 = input1.c_str();
	int size1 = input1.length();
	int size2 = input2.length();

	//Create a LCS object
	LCS(size1, size2, input1, input2);

	return 0;
}