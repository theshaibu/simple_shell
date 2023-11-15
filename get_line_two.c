#include "shell.h"

/**
 * read_line - Read a line of input from the standard input.
 * @i_eof: Pointer to store the end-of-file indicator.
 * Return: Pointer to the input line.
 */
char *read_line(int *i_eof) {
    char *input = NULL;  
    size_t bufsize = 0;   

   
    *i_eof = getline(&input, &bufsize, stdin);

    
    return (input);
}

