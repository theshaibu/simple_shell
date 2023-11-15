#include "shell.h"

/**
 * aux_help_env - Display help information for the 'env' command.
 * Return: None.
 */
void aux_help_env(void) {
    // Display the usage information for the 'env' command
    char *help = "env: env [option] [name=value] [command [args]]\n\t";
    write(STDOUT_FILENO, help, _strlen(help));

    // Provide a brief description of the 'env' command
    help = "Print the environment of the shell.\n";
    write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_setenv - Display help information for the 'setenv' command.
 * Return: None.
 */
void aux_help_setenv(void) {
    // Display the usage information for the 'setenv' command
    char *help = "setenv: setenv (const char *name, const char *value, int replace)\n\t";
    write(STDOUT_FILENO, help, _strlen(help));

    // Provide a brief description of the 'setenv' command
    help = "Add a new definition to the environment.\n";
    write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_unsetenv - Display help information for the 'unsetenv' command.
 * Return: None.
 */
void aux_help_unsetenv(void) {
    // Display the usage information for the 'unsetenv' command
    char *help = "unsetenv: unsetenv (const char *name)\n\t";
    write(STDOUT_FILENO, help, _strlen(help));

    // Provide a brief description of the 'unsetenv' command
    help = "Remove an entry completely from the environment.\n";
    write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_general - Display general help information for the shell.
 * Return: None.
 */
void aux_help_general(void) {
    // Display general information about the shell
    char *help = "^-^ bash, version 1.0(1)-release\n";
    write(STDOUT_FILENO, help, _strlen(help));

    help = "These commands are defined internally. Type 'help' to see the list.";
    write(STDOUT_FILENO, help, _strlen(help));

    help = "Type 'help name' to find out more about the function 'name'.\n\n ";
    write(STDOUT_FILENO, help, _strlen(help));

    help = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
    write(STDOUT_FILENO, help, _strlen(help));

    help = "[dir]\nexit: exit [n]\n env: env [option] [name=value] [command ";
    write(STDOUT_FILENO, help, _strlen(help));

    help = "[args]]\n setenv: setenv [variable] [value]\n unsetenv: ";
    write(STDOUT_FILENO, help, _strlen(help));

    help = "unsetenv [variable]\n";
    write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_exit - Display help information for the 'exit' command.
 * Return: None.
 */
void aux_help_exit(void) {
    // Display the usage information for the 'exit' command
    char *help = "exit: exit [n]\n Exit shell.\n";
    write(STDOUT_FILENO, help, _strlen(help));

    help = "Exits the shell with a status of N. If N is omitted, the exit";
    write(STDOUT_FILENO, help, _strlen(help));

    help = "status is that of the last command executed.\n";
    write(STDOUT_FILENO, help, _strlen(help));
}

