/*
-----------------------------
String Length Program Header
-----------------------------
*/

#ifndef STRLEN_H
#define STRLEN_H

#include <stdio.h>

// assembly function prototype
extern int strlen_s(char *s);

// strlen_c counts the number of characters in a C string
int strlen_c(char *s);

//String Length main program
int run_strlen(char *message);


#endif STRLEN_H

/* --------------------------------- STRLEN_C.H --------------- */