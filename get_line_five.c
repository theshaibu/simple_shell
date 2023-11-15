#include "shell.h"

/**
 * get_sigint - Signal handler for SIGINT (Ctrl+C).
 * @sig: Signal number.
 */
void get_sigint(int sig) {
    
    (void)sig;

    
    write(STDOUT_FILENO, "\n^-^ ", 5);
}

