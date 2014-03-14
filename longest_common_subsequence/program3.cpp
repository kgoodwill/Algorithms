//Program 1 - Top Down w/ Memoization
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>

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
	int count = 0;
	//Initialize row and column 0 of values matrix to 0
	for(int i=0; i<rows; i++){values[i][0] = 0;}
	for(int i=0; i<columns; i++){values[0][i] = 0;}

	for(int i=0; i<rows; i++){directions[i][0] = 0;}
	for(int i=0; i<columns; i++){directions[0][i] = 0;}

	/*for(int i=0; i<rows; i++){cout << values[i][0] << " ";}
	cout << endl;
	for(int i=0; i<columns; i++){cout << values[0][i] << endl;}*/

	for(int i=1; i<=inputASize; i++){
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
	return count;
}

void LCS::print_lcs(int i, int j, ofstream* outfile){
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
		outfile<<endl;
		outfile << elapsed_secs << endl;
	}
	outfile << lcs_size << endl;
	outfile << elapsed_secs << endl;

	return 0;
}