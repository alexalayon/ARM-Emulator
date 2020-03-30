/*
-----------------------------
Quadratic Program Header
-----------------------------
*/

#ifndef QUADRATIC_H
#define QUADRATIC_H

#include <stdio.h>

// assembly function prototype
extern int quadratic_s(int x, int a, int b, int c);

// quadratic_c calculates the solution to the quadratic equation for the given parameters
int quadratic_c(int x, int a, int b, int c);

//Quadratic main program
int run_quadratic(int x, int a, int b, int c);


#endif QUADRATIC_H

/* --------------------------------- QUADRATIC_C.H --------------- */