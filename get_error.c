#include "shell.h"

/**
 * get_error - Handles error messages and sets the status in data_shell.
 * @datash: Pointer to the data_shell struct.
 * @eval: Error code to determine the type of error.
 * 
 * Returns: The provided error code.
 */
int get_error(data_shell *datash, int eval) {
    char *error;

    
    switch (eval) {
        case -1:
            error = error_env(datash);
            break;
        case 126:
            error = error_path_126(datash);
            break;
        case 127:
            error = error_not_found(datash);
            break;
        case 2:
            if (_strcmp("exit", datash->args[0]) == 0)
                error = error_exit_shell(datash);
            else if (_strcmp("cd", datash->args[0]) == 0)
                error = error_get_cd(datash);
            break;
    }

 
    if (error) {
        write(STDERR_FILENO, error, _strlen(error));
        free(error);
    }

   
    datash->status = eval;
    return eval;
}

