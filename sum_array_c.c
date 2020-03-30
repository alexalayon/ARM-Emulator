#include "sum_array_c.h"

// sum_array_c calculates the sum of the integers in the array
int sum_array_c(int *array, int n)
{
    int i;
    int sum = 0;
    for (i = 0; i < n; i++) {
        sum = sum + array[i];
    }
    return sum;
}

// print array contents
void print_array_sumarray(int *array, int n)
{
    int i;
    printf("[ ");
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("]\n");
}

//Sum array main program
int run_sum_array(int *array, int test)
{
	//Testing Sum of an array of numbers
	if (test != 1000)
	{
		printf("Summing array: ");
		print_array_sumarray(array, test);
		printf("C result:        %d\n", sum_array_c(array, test));
	}
	else
	{
		int i;
		srand(time(NULL));	
	
		printf("Summing random array of 1000 elements...\n");
		for (i = 0; i < test; i++)
			array[i] = (rand() % 2000) - 1000;
		printf("C result:        %d\n", sum_array_c(array, test));
		printf("Assembly result: %d\n", sum_array_s(array, test));
	}
	
    return 0;
}