# Sudoku Verifier

A CLI based program used to verify whether a sudoku puzzle was properly completed.

  - Compiles on Linux and Windows
  - Input Verification
  - Load puzzles with a file

### Linux Instructions

 ```sh
$ cd path/to/SudokuVerifier
$ make
$ ./main
```
1. Follow the the prompt to enter your file name.
1. Three example puzzles have been included
1. Remember to include the file extension!

### Windows Instructions
1. This program was compiled in Visual Studio 2017
1. Open SudokuVerifier.sln
1. Debug > Start Debugger (or press F5)
1. Follow the the prompt to enter your file name.
1. Three example puzzles have been included
1. Remember to include the file extension!    
  
#### Notes #

A custom `toLower` function has been added which converts a string with uppercase characters to all lowercase characters. Any file will be loaded into a two dimensional array before it is displayed on the screen.

When creating an input sudoku file, enter nine digits for the first row, seperated by spaces. Includes nine total rows, seperating each row by a newline character.

#### Example Input #
```sh
3 5 4 8 6 7 1 2 9
6 7 8 9 2 1 3 5 4
1 9 2 5 3 4 6 7 8
7 3 5 1 4 9 2 8 6
4 1 9 6 8 2 7 3 5
8 2 6 7 5 3 4 9 1
9 6 1 3 7 5 8 4 2
2 8 3 4 9 6 5 1 7
5 4 7 2 1 8 9 6 3
```
