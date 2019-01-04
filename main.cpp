/****************************************************************
PROGRAM:   Sodoku Verifier
AUTHOR:    Jason Tokarski

FUNCTION:  This program will take multiple 9x9 tables of values located
in a text file, scan all the rows, columns, subrows, and subcolumns
in the sodoku puzzles and verifier whether the puzzle was solved correctly.

INPUT:     A text file containing a sodoku puzzle.

OUTPUT:    A message verifing that your sodoku puzzle was solved
correctly or incorrectly.

NOTES:     Please only use puzzles with digits ranging from 1 through 9
with each row and column being seperated by spaces.
****************************************************************/
#include <iostream>
#include <string.h>
#include "verify.h"

/*If we are not on a windows system use strerror_s*/
#ifdef _WIN32
	#define strerror_r(errno,buf,len) strerror_s(buf,len,errno)
#endif

#define BUFFER_SIZE 1024
#define CONTINUE 1

int main()
{
	/*Create an object of the verifier class*/
	Verifier v;
	std::string fileName;
	int errNum = 0;
	char buf[BUFFER_SIZE];

	std::cout << "Sudoku Verifier\n";

	while (CONTINUE)
	{
		std::cout << std::endl;
		std::cout << "Please enter your file containing a sudoku puzzle (q to quit): ";
		std::cin >> fileName;

		v.toLower(&fileName);

		if (fileName == "q" || fileName == "quit")
		{
			break;
		}

		/*Read the file data into a 2D array*/
		errNum = v.readGrid(fileName);

		/*Check for any errors*/
		if (errNum == -1)
		{
			strerror_r(errno, buf, BUFFER_SIZE);
			std::cerr << buf;
			continue;
		}
		else if (errNum == -2)
		{
			std::cout << "Invalid character data inside of file!\n";
			continue;
		}

		/*Print the two dimensional array of values representing
		the sodoku puzzle.*/
		v.printGrid();

		if (v.verifySolution())
		{
			std::cout << "\nThis is a valid Sudoku solution\n";
		}
		else
		{
			std::cout << "\nThis is not a valid Sudoku solution\n";
		}
	}
	return 0;
}