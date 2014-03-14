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
		cout << "HERE" << endl;
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
	//for(int i=0; i<columns; i++){values[0][i] = 0;}

	//for(int i=0; i<rows; i++){directions[i][0] = 0;}
	//for(int i=0; i<columns; i++){directions[0][i] = 0;}

	/*for(int i=0; i<rows; i++){cout << values[i][0] << " ";}
	cout << endl;
	for(int i=0; i<columns; i++){cout << values[0][i] << endl;}*/

	/*for(int i=1; i<=inputASize; i++){
		for(int j=1; j<=inputBSize; j++){
			//cout << "x[i]: " << inputA[i-1] << " " << i << endl;
			//cout << "y[j]: " << inputB[j-1] << " " << j << endl;
			//cout << endl;
			if(inputA[i-1] == inputB[j-1]){
				values[i][j] = (values[i-1][j-1] + 1);
				directions[i][j] = 2;
				//cout << "Found Match: " << values[i][j] << endl;
				//cout << "Direction: " << directions[i][j] << endl;
			}
			else if(values[i-1][j] >= values[i][j-1]){
				values[i][j] = values[i-1][j];
				//cout << values[i][j] << endl;
				directions[i][j] = 3;
				//cout << "Direction: " << directions[i][j] << endl;
			}
			else{
				values[i][j] = values[i][j-1];
				//cout << values[i][j] << endl;
				directions[i][j] = 1;
				//cout << "Direction: " << directions[i][j] << endl;
			}
		}
	}
}*/

/*void LCS::print_lcs(int i, int j, ofstream* outfile){
	//cout << "i: " << i << endl;
	//cout << "j: " << j << endl;
	if (i == 0 || j == 0){
		return;
	}
	//cout << directions[i][j] << endl;
	if (directions[i][j] == 2){
		//cout << "HERE" << endl;
		//cout << directions[i][j] << endl;
		//cout << " " << inputA[i];
		print_lcs(i-1, j-1);
		cout << " " << inputA[i-1] << endl;
	}
	else if (directions[i][j] == 3){
		print_lcs(i-1, j);
	}
	else{
		print_lcs(i, j-1);
	}
}*/



//int file_size(ifstream* file);

string get_input(ifstream* file){
	int count = 0;
	string line = "";
	getline(*file, line);
	//cout << line << endl;
	//cout << "HERE " << line.length() << endl;
	return line;
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
	if (!inFile1.is_open() || !inFile2.is_open()){
		cout << "ERROR: One of the input files doesn't exist" << endl;
		return -2;
	}
	string input1;
	string input2;
	inFile1 >> input1;
	inFile2 >> input2;
	//cout << input1 << endl;
	//cout << input2 << endl;
	int inputALength = input1.length();
	int inputBLength = input2.length();
	//cout << "x.length() - " << inputALength << endl;
	//cout << "y.length() - " << inputBLength << endl;	

	int rowsize = inputALength + 1;
	int colsize = inputBLength + 1;
	//cout << "rowsize - " << rowsize << endl;
	//cout << "colsize - " << colsize << endl;

	char* cinput1 = (char*)input1.c_str();
	char* cinput2 = (char*)input2.c_str();

	//Create a LCS object
	LCS* myLCS = new LCS(rowsize, colsize, inputALength, inputBLength, cinput1, cinput2);

	int lcs_size = myLCS->find_lcs();
	outfile << lcs_size << endl;
	//cout << "--LCS--" << endl;
	//myLCS->print_lcs(inputALength, inputBLength);
	//cout << myLCS->get_LCS() << endl;

	return 0;
}