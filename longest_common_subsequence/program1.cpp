//Program 1 - Bottom Up LCS Solution

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class BU_LCS
{
public:
	BU_LCS();
	~BU_LCS();
};

int file_size(fstream file);

int file_size(fstream file){
	int count = 0;
	string line;
	while(!file.eof()){
		line = file.getline();
		count += line.length();
	}
	return count;
}

int main(int argc, char* argv){
	if argc != 3{
		cout << "Correct Syntax: program1 <input_file_1> <input_file_2> <output_file>" << endl;
		return -1;
	}
	fstream inFile1;
	fstream inFile2;
	inFile1.open(argv[0], fstream::in);
	inFile2.open(argv[1], fstream::in);

	//Determine the size of each file
	int size1 = file_size(inFile1);
	int size2 = file_size(inFile2);

	return 0;
}