#include "shell.h"

/**
 * cd_shell - Change directory based on the arguments.
 * @datash: The data_shell struct.
 * Return: 1 on success, -1 on failure.
 */
int cd_shell(data_shell *datash)
{
    char *dir;
    int ishome, ishome2, isddash;

    dir = datash->args[1];

  
    if (dir != NULL)
    {
        ishome = _strcmp("$HOME", dir);
        ishome2 = _strcmp("~", dir);
        isddash = _strcmp("--", dir);
    }

    
    if (dir == NULL || !ishome || !ishome2 || !isddash)
    {
        cd_to_home(datash);
        return (1);
    }

    
    if (_strcmp("-", dir) == 0)
    {
        cd_previous(datash);
        return (1);
    }

    
    if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
    {
        cd_dot(datash);
        return (1);
    }

   
    cd_to(datash);

    return (1);
}

