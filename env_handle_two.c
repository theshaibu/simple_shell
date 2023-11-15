#include "shell.h"

/**
 * cmp_env_name - Compares the name part of an environment variable.
 * @nenv: The environment variable.
 * @name: The name to compare.
 *
 * Return: The number of characters matched (including '='), or 0 if no match.
 */
int cmp_env_name(const char *nenv, const char *name)
{
    int i;

    for (i = 0; nenv[i] != '='; i++)
    {
        if (nenv[i] != name[i])
        {
            return (0);
        }
    }

    return (i + 1);
}

/**
 * _getenv - Gets the value of an environment variable.
 * @name: The name of the environment variable.
 * @_environ: The array of environment variables.
 *
 * Return: A pointer to the value part of the environment variable.
 */
char *_getenv(const char *name, char **_environ)
{
    char *ptr_env;
    int i, mov;

   
    ptr_env = NULL;
    mov = 0;

 
    for (i = 0; _environ[i]; i++)
    {
        
        mov = cmp_env_name(_environ[i], name);
        if (mov)
        {
            
            ptr_env = _environ[i];
            break;
        }
    }

  
    return (ptr_env + mov);
}

/**
 * _env - Implements the 'env' built-in command.
 * @datash: Pointer to the data_shell struct.
 *
 * Return: Always returns 1.
 */
int _env(data_shell *datash)
{
    int i, j;

    
    for (i = 0; datash->_environ[i]; i++)
    {
        
        for (j = 0; datash->_environ[i][j]; j++)
            ;

        
        write(STDOUT_FILENO, datash->_environ[i], j);
        write(STDOUT_FILENO, "\n", 1);
    }


    datash->status = 0;

    return (1);
}

