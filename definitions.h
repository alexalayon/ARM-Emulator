/*
----------------------------------------
Global Definitions for the program
----------------------------------------
*/

#ifndef DEFINITIONS_H
#define DEFINITIONS_H


//Constant Definitions
#define NUMBER_TEST_MAX	5
#define FIB_TEST_MAX	4
#define STRING_TEST_MAX	4
#define MAX_ARRAY_NUMBER	10
#define RANDOM_ARRAY_NUMBER	1000
#define FINDMAX_ARRAY_NUMBER	6
#define FIB_SEQ_MAX	20

#define REGISTER_MAX	16
#define STACK_SIZE	1024
#define SP	13
#define LR	14
#define PC	15

//Arrays
int quad_x[NUMBER_TEST_MAX] = {0,1,-1,1,-2};
int quad_a[NUMBER_TEST_MAX] = {1,1,1,3,-2};
int quad_b[NUMBER_TEST_MAX] = {2,2,2,-3,-2};
int quad_c[NUMBER_TEST_MAX] = {1,1,1,3,-2};

int sumarray_test[NUMBER_TEST_MAX] = {10, 0, 1, 10, 1000};
int sumarray_random[RANDOM_ARRAY_NUMBER];

int findmax_array[FINDMAX_ARRAY_NUMBER] = {-100, 33, 4, 1, 1231, 27};
int findmax_test[NUMBER_TEST_MAX] = {10, 1, 10, 6, 1000};
int findmax_random[RANDOM_ARRAY_NUMBER];

char *message[STRING_TEST_MAX] = {"hi world", "1234567890", "", "a"};

int array1[MAX_ARRAY_NUMBER] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int array2[MAX_ARRAY_NUMBER] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10};
int fib_test[FIB_TEST_MAX] = {0, 2, 10, 24};



#endif


/* --------------------------------- DEFINITIONS.H --------------- */