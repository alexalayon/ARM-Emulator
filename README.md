                                README

These programs implement six functions in ARM assembly language and C.
A Makefile is included which can be used to generate the executable
files for all programs. The included programs are the following:

1. Quadratic equation
    Calculates the solution to the quadratic equation for the given parameters
    Files: quadratic_c.c and quadratic_s.s

2. Sum Array
    Calculates the sum of the integers in the array
    Files: sum_array_c.c and sum_array_s

3. Find Max
    Finds the largest number in an array of integers
    Files: find_max_c.c and find_max_s

4. Fibonacci sequence, iteratively
    Iteratively determines the value of the nth number in the Fibonacci sequence
    Files: fib_iter_c.c and fib_iter_s.s

5. Fibonacci sequence, recursively
    Recursively determines the value of the nth number in the Fibonacci sequence
    Files: fib_rec_c.c and fib_rec_s.s

6. String Length
    Counts the number of characters in a C string
    Files: strlen_c.c and strlen_s.s

                                COMPILING 

In order to compile all the files, the following command can be used:

    make

Or:

    make all

This generates the following executable files:

quadratic, sum_array, find_max, fib_iter, fib_rec and strlen, that correspond
to all the six functions listed previously.

                                RUNNING

In order to run the executable files simply write the executable file name
on the command line using the following format:

    ./executable_filename
    
Where executable_name can be one of: quadratic, sum_array, find_max, fib_iter,
fib_rec and strlen


