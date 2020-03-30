/*
-------------------------
Emulator Main Program 
-------------------------
*/

#include "test.h"

int main()
{
	//Print Emulator Header
	print_header("Emulator Program");
	
	//Quadratic Equation Program Execution
	print_program_header("Quadratic Program");
	quadratic_test();
	
	//Sum of Array Program Execution
	print_program_header("Array Sum Program");
	sum_array_test();
	
	//Find Max Number Program Execution
	print_program_header("Find Max Number Program");
	find_max_test();
	
	//Fibonacci Iterative Program Execution
	print_program_header("Fibonacci Iterative Sequence Program");
	fib_iter_test();
	
	//Fibonacci Recursive Program Execution
	print_program_header("Fibonacci Recursive Sequence Program");
	fib_rec_test();
	
	//String Length Program Execution
	print_program_header("String Length Program");
	strlen_test();
	
	return 0;
}


void print_header(char *title)
{
	//Title Header Format
    printf(" ------------------------------------------------------------------------\n");
    printf("|                             %s                           |\n", title);
    printf(" ------------------------------------------------------------------------\n");	
}

void print_program_header(char *program)
{
	//Program Header Format
	printf("__________________________________________________\n");
    printf("%s \n", program);
    printf("__________________________________________________\n");
	printf("\n");
	
}