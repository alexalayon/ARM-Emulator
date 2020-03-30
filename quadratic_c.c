#include "quadratic_c.h"

// quadratic_c calculates the solution to the quadratic equation for the given parameters
int quadratic_c(int x, int a, int b, int c)
{
    int result = (a * (x * x)) + (b * x) + c;
    return result;
}


//Quadratic Main Program
int run_quadratic(int x, int a, int b, int c)
{
	//Testing Quadratic equation program
	if (a == 1)
	{
		printf("Solving x^2 + %dx + %d with x = %d: \n", b, c, x);
	}
	else
	{
		printf("Solving %dx^2 + %dx + %d with x = %d: \n", a, b, c, x);
	}
	
    printf("Assembly solution: %d\n", quadratic_s(x,a,b,c));

    return 0;
}
