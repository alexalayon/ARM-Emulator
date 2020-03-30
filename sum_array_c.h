/*
-----------------------------
Array Sum Program Header
-----------------------------
*/

#ifndef SUM_ARRAY_H
#define SUM_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// assembly function prototype
int sum_array_s(int *array, int n);

// sum_array_c calculates the sum of the integers in the array
int sum_array_c(int *array, int n);

// print array contents
void print_array_sumarray(int *array, int n);

//Sum array main program
int run_sum_array(int *array, int test);


#endif SUM_ARRAY_H

/* --------------------------------- SUM_ARRAY_C.H --------------- */