//Program 1 - Bottom Up LCS Solution

#include <stdio>
#include <stdlib>
#include <iostream>
#include <fstream>

class BU_LCS
{
public:
	BU_LCS();
	~BU_LCS();
	
};

int main(int argc, char* argv){
	if argc != 3{
		cout << "Correct Syntax: program1 <input_file_1> <input_file_2> <output_file>"
		return -1;
	}
	fstream inFile1;
	fstream inFile2;
	inFile1.open(argv[0]);
	inFile2.open(argv[1]);

	return 0;
}