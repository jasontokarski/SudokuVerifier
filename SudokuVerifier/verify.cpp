#include <iostream>
#include <fstream>
#include "verify.h"

/****************************************************************
FUNCTION:   Verifier() constructor

NOTES:      This will initialize all the sudoku grid values to 0
when a Verifier object is created.
****************************************************************/
Verifier::Verifier()
{
	/*For each column and row index set the value to 0*/
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			sudokuGrid[i][j] = 0;
		}
	}
}

/****************************************************************
FUNCTION:   toLower()

ARGUMENTS:  A pointer to a string

NOTES:      This function will convert an uppercase letters within
a string to lowercase.
****************************************************************/
void Verifier::toLower(std::string *str)
{
	std::string::iterator it;
	for (it = (*str).begin(); it != (*str).end(); it++)
	{
		if (*it >= 'A' && *it <= 'Z')
		{
			*it += 32;
		}
	}
}

/****************************************************************
FUNCTION:   readGrid()

ARGUMENTS:  A pointer to a character constant representing the name
of the file to be read into an array.

NOTES:      This function will initialize all the positions in the
sudoku puzzle array to the values found in the text file.
****************************************************************/
int Verifier::readGrid(const std::string filename)
{
	/*Create input stream object and open the sudoku file*/
	std::ifstream inFile;
	inFile.open(filename);

	if (inFile.fail())
	{
		return -1;
	}

	/*Use the inFile object to store each value in the sudoku grid*/
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			inFile >> sudokuGrid[i][j];
			if (inFile.fail())
			{
				return -2;
			}
		}
	}
	/*Close the file*/
	inFile.close();

	return 0;
}

/****************************************************************
FUNCTION:   printGrid()

NOTES:      This function will display all the values within the
two dimensional sudokuGrid array to the console.
****************************************************************/
void Verifier::printGrid()
{
	/*For each column and row index output the current value*/
	for (int i = 0; i < 9; i++)
	{
		if (!(i % 3))
		{
			std::cout << "-------------------------" << std::endl;
		}
		for (int j = 0; j < 9; j++)
		{
			if (!(j % 3))
			{
				std::cout << "| ";
			}
			std::cout << sudokuGrid[i][j] << " ";
		}
		std::cout << "| ";
		std::cout << std::endl;
	}
	std::cout << "-------------------------" << std::endl;
}

/****************************************************************
FUNCTION:   verifySolution()

ARGUMENTS:  None

RETURNS:    Nothing

NOTES:      This function scans through 9 outer rows, 9 outer columns,
and subcolumns containing 3 rows and 3 columns each.
****************************************************************/
bool Verifier::verifySolution()
{
	/*This outer loop will be used to iterate over the starting
	row and column subscripts/indexes within the sudokuGrid array*/
	for (int startIndex = 0; startIndex < 9; startIndex++)
	{
		int rowScan = 0,		
			colScan = 0;

		/*This for loop will set where the beginning scan point begins for a
		particular row or column, very similar to a selection sort in the
		way it searches elements*/
		for (int startScan = 0; startScan < 8; startScan++)
		{
			/*The initial row value to be compared with all other elements
			in the same row*/
			rowScan = sudokuGrid[startIndex][startScan];
			/*The intial column value to be compared with all other elements
			in the same column*/
			colScan = sudokuGrid[startScan][startIndex];

			/*This index will begin one element after the initial starting scan
			position and compare each successive value with the initial row or
			column value until it reaches the end of a column*/
			for (int subScan = startScan + 1; subScan < 9; subScan++)
			{
				/*If the current position in the main row is equal to the starting
				value being scanned in that row, then there must be two of the same
				values in that row, so return false*/
				if (sudokuGrid[startIndex][subScan] == rowScan)
				{
					return false;
				}
				/*If the current position in the main column is equal to the starting
				value being scanned in that column, then there must be two of the same
				values in that column, so return false*/
				if (sudokuGrid[subScan][startIndex] == colScan)
				{
					return false;
				}
			}
		}
	}

	int rowStartScan = 0;  //The subscript value for each starting row position for all the subgrids
	int colStartScan = 0;  //The subscript value for each starting column position for all the subgrids
	int subRow = 0,	       //The subscript value used for each row in a subgrid
		subCol = 0,	       //The subscript value user for each column in a subgrid
		subgridIndex = 0;  //An index to store all the values into an array
	int subgridValues[9];  //The array where values will be stored for each subgrid

	/*These are the initial column subscripts where each subgrid search begins. On each iteration
	move 3 column elements foward on sudokuGrid to the beginning of the next subgrid portion
	to be scanned*/
	for (colStartScan = 0; colStartScan <= 6; colStartScan += 3) {
		/*After each column start scan subscript is set, there are also the start scan values
		representing each rows starting point. There are three row subscript values where scanning
		begins for each column start value. This will scan the subgrids in a left to right, top
		to bottom approach*/
		for (rowStartScan = 0; rowStartScan <= 6; rowStartScan += 3) {

			/*Reset the subgridIndex and set up a loop to go over each row of all the subgrids*/
			subgridIndex = 0;
			for (subRow = 0; subRow < 3; subRow++) {
				/*After the start of each subgrid row, make one last loop to iterate over each
				column of each row in all the subgrids*/
				for (subCol = 0; subCol < 3; subCol++) {
					/*Grab each value contained in all sudokuGrid elements of a subgrid and store it
					in an aray called subgridValues*/
					subgridValues[subgridIndex++] = sudokuGrid[rowStartScan + subRow][colStartScan + subCol];
				}
			}
			/*This is where all the values within a particular subgrid are compared in a similar manner to
			the way selection sort scans through values. startScan is the beginning index point that all
			subsequent values are compared to*/
			int startScan;
			/*Loop over all the values and compare them to the initial start scan value*/
			for (int i = 0; i < 9; i++) {
				startScan = subgridValues[i];
				for (int j = i + 1; j < 9; j++) {
					if (subgridValues[j] == startScan)
						return false;
				}
			}
		}
	}
	return true;
}

