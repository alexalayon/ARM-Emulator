#include "find_max_c.h"

// find_max_c finds the largest number in an array of integers
int find_max_c(int *array, int n)
{
    int i;
    int max = array[0];
    for (i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// print array contents
void print_array_findmax(int *array, int n)
{
    int i;
    printf("[ ");
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("]\n");
}

//Find max Main Program
int run_find_max(int *array, int test)
{
	if (test != 1000)
	{
		printf("Finding max in array: ");
		print_array_findmax(array, test);
		printf("C result:        %d\n", find_max_c(array, test));
	}
	else
	{
		int i;
		srand(time(NULL));
	
		printf("Finding max in random array of 1000 elements...\n");
		for (i = 0; i < test; i++)
			array[i] = (rand() % 2000) - 1000;
		printf("C result:        %d\n", find_max_c(array, test));
	}

    return 0;
}
