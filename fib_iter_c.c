#include "fib_iter_c.h"

// fib_iter_c iteratively determines the value of the nth number in the Fibonacci sequence
int fib_iter_c(int n) {
    int i;
    int prev_prev_num = 0, prev_num = 0, cur_num = 1;
    if (n == 0) {
        return 0;
    }
    for (i = 1; i < n ; i++) {
        prev_prev_num = prev_num;
        prev_num = cur_num;
        cur_num = prev_prev_num + prev_num;
    }
    return cur_num;
}

//Fibonacci Iterative Main Program
int run_fib_iter(int test)
{
    printf("Calculating fib(0):\n");
    printf("Assembly result: %d\n", fib_iter_s(test));
	
    return 0;
}

void run_fib_iter_seq(int test)
{
	int i;
	printf("Calculating fib sequence for first 20 numbers:\n");
    printf("C result:\n");
    for (i = 0;  i< test; i++)
        printf("%s%d", (i > 0)? ", ":"", fib_iter_c(i));
    printf("\nAssembly result:\n");
    for (i = 0;  i< test; i++)
        printf("%s%d", (i > 0)? ", ":"", fib_iter_s(i));
    printf("\n");
}
