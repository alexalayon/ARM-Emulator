/*
---------------------------------------------------
Find Max Number Program Header
---------------------------------------------------
*/

#ifndef FIND_MAX_H
#define FIND_MAX_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// assembly function prototype
int find_max_s(int *array, int n);

// find_max_c finds the largest number in an array of integers
int find_max_c(int *array, int n);

// print array contents
void print_array_findmax(int *array, int n);

//Find max main program
int run_find_max(int *array, int test);


#endif FIND_MAX_H

/* --------------------------------- FIND_MAX_C.H --------------- */