#ifndef VERIFY_H
#define VERIFY_H

#include <string>

#define ROW_SIZE 9
#define COL_SIZE 9

class Verifier
{
private:
	/*The main sodokuGrid data member where the integer
	values found in the sudoku file will be stored*/
	int sudokuGrid[ROW_SIZE][COL_SIZE];
public:
	Verifier();
	int readGrid(const std::string);
	void printGrid();
	bool verifySolution();
	void toLower(std::string*);
};

#endif
