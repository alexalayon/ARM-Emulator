#include "fib_rec_c.h"

// fib_rec_c recursively determines the value of the nth number in the Fibonacci sequence
int fib_rec_c(int n)
{
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fib_rec_c(n - 1) + fib_rec_c(n - 2);
    }
}

//Fibonacci Recursive Main Program
int run_fib_rec(int test)
{
    printf("Calculating fib(%d):\n", test);
    printf("Assembly result: %d\n", fib_rec_s(test));
    

    return 0;
}

void run_fib_rec_seq(int test)
{
	int i;
	
	printf("Calculating fib sequence for first 20 numbers:\n");
    printf("C result:\n");
    for (i = 0;  i< test; i++)
        printf("%s%d", (i > 0)? ", ":"", fib_rec_c(i));
    printf("\nAssembly result:\n");
    for (i = 0;  i< test; i++)
        printf("%s%d", (i > 0)? ", ":"", fib_rec_s(i));
    printf("\n");
}