#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

/*basic input/output and memory management functions*/
#include "chastefont.h"

int main(int argc, char **argv)
{

 /*function to make ASCII file*/
 /*BBM_Save_ASCII("o/ascii.txt");*/

 chaste_char_list_line();
 
 /*chaste_char_list_numbers();*/
 
 /*chaste_char_list_limited();*/
 
 /*BBM_Save_ASCII("o/ascii.txt");*/
 
 /*chaste_char_list_numbers_256();*/
 /*BBM_Save_256("o/256.txt");*/

 return 0;
}

/*
This file is part of the Chaste Font project of Chastity White Rose/Chandler Isaac Klebs.
It contains only the main function which calls other functions I have written. The others are in header files.

This and all the other source files usually come with my own makefile which has the command to compile and run them using gcc. All have been tested on msys2 under Windows 10.

If only the C standard library(The current official way):
gcc -Wall -ansi -pedantic main.c -o main && ./main

Compile with g++ and see if the code is also valid C++. (portability is important to me)
g++ -Wall -ansi -pedantic main.c -o main && ./main

Can even be compiled with tcc.
tcc main.c -o main.exe && ./main

Or even the Microsoft C compiler.
cl main.c /Fe:main && main


*/
