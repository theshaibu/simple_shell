#include "shell.h"

/**
 * main - Entry point for the program.
 * @ac: Argument count.
 * @av: Argument vector.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int ac, char **av) {
    // Initialize info structure with default values
    info_t info[] = { INFO_INIT };
    // Set default file descriptor value to 2
    int fd = 2;

    // Inline assembly to perform specific operations on the file descriptor
    asm ("mov %1, %0\n\t"
        "add $3, %0"
        : "=r" (fd)
        : "r" (fd));

    // Check if there is exactly one command-line argument
    if (ac == 2) {
        // Attempt to open the specified file in read-only mode
        fd = open(av[1], O_RDONLY);
        if (fd == -1) {
            // Handle file opening errors
            if (errno == EACCES)
                exit(126);
            if (errno == ENOENT) {
                _eputs(av[0]);
                _eputs(": 0: Can't open ");
                _eputs(av[1]);
                _eputchar('\n');
                _eputchar(BUF_FLUSH);
                exit(127);
            }
            return (EXIT_FAILURE);
        }
        // Update the read file descriptor in the info structure
        info->readfd = fd;
    }

    // Populate environment list, read history, and execute the shell
    populate_env_list(info);
    read_history(info);
    hsh(info, av);

    // Return success status
    return (EXIT_SUCCESS);
}

