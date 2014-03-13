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
		void find_lcs();
		void print_lcs(int i, int j);
		int get_Rows();
		int get_Columns();

	private:
		//Data Members
		int rows;
		int columns;
		int** values;
		int** directions;
		char* inputA;
		char* inputB;
};

//Default Constructor
LCS::LCS() : inputA(nullptr), inputB(nullptr), rows(1), columns(1){
	LCS(rows, columns, inputA, inputB);
}

//Explicit Value Constructor
LCS::LCS(int rows, int columns, char* aIn, char* bIn) : inputA(aIn), inputB(bIn), rows(rows), columns(columns){
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

void LCS::find_lcs(){
	//Initialize row and column 0 of values matrix to 0
	for(int i=0; i<rows; i++){values[i][0] = 0;}
	for(int i=0; i<columns; i++){values[0][i] = 0;}

	for(int i=1; i<rows; i++){
		for(int j=1; j<columns; j++){
			if(inputA[i] == inputB[j]){
				values[i][j] = (values[i-1][j-1]) + 1;
				directions[i][j] = 2;
			}
			else if(values[i-1][j] >= values[i][j-1]){
				values[i][j] = values[i-1][j];
				directions[i][j] = 3;
			}
			else{
				values[i][j] = values[i][j-1];
				directions[i][j] = 1;
			}
		}
	}
}

void LCS::print_lcs(int i, int j){
	if (i == 0 || j == 0){
		exit(0);
	}
	if (directions[i][j] == 2){
		print_lcs(i-1, j-1);
		cout << " " << inputA[i] << endl;
	}
	else if (directions[i][j] == 3){
		print_lcs(i-1, j);
	}
	else{
		print_lcs(i, j-1);
	}
}



//int file_size(ifstream* file);

string get_input(ifstream* file){
	int count = 0;
	string line = "";
	getline(*file, line);
	cout << line << endl;
	cout << "HERE " << line.length() << endl;
	return line;
}

int main(int argc, char* argv[]){
	if (argc != 4){
		cout << "Correct Syntax: program1 <input_file_1> <input_file_2> <output_file>" << endl;
		return -1;
	}
	ifstream inFile1 (argv[1]);
	ifstream inFile2 (argv[2]);

	//Determine the size of each file
	if (!inFile1.is_open() || !inFile2.is_open()){
		cout << "ERROR: One of the input files doesn't exist" << endl;
		return -2;
	}
	string input1;
	string input2;
	inFile1 >> input1;
	inFile2 >> input2;
	cout << input1 << endl;
	cout << input2 << endl;
	//inFile1.getline(input1, 1000);
	//inFile2.getline(input2, 1000);
	int size1 = input1.length() + 1;
	int size2 = input2.length() + 1;

	char* cinput1 = (char*)input1.c_str();
	char* cinput2 = (char*)input2.c_str();
	//int size1 = input1.length();
	cout << size1 << endl;
	//int size2 = input2.length();
	cout << size2 << endl;

	//Create a LCS object
	LCS* myLCS = new LCS(size1, size2, cinput1, cinput2);

	myLCS->find_lcs();
	myLCS->print_lcs(size1, myLCS->get_Columns());

	return 0;
}