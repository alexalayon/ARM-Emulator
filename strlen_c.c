#include "strlen_c.h"


// strlen_c counts the number of characters in a C string
int strlen_c(char *s)
{
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

//String Length Main Program
int run_strlen(char *message)
{
    printf("Calculating length of \"%s\":\n", message);
    printf("Assembly solution: %d\n", strlen_s(message));

    return 0;
}
