/* C program by Azariel Del Carmen for CS1311 Apr 2021
 * play with system and call other programs
 */
 
#include <stdio.h>
#include <process.h>
 
void main(void)
{
	printf("Program to play with system calls --- \n\n");
	system("dir");
	system("calc.exe");
	system("notepad");
	
	printf("\n\nsystem call with inputs/parameters \n");
	system("C:\\inputs 999 some other words");
}
