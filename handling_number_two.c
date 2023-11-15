#include "shell.h"

/**
 * aux_help - Display information about built-in commands.
 * Return: None.
 */
void aux_help(void) {
    // Display the usage information for the 'help' command
    char *help = "help: help [-dms] [pattern ...]\n";
    write(STDOUT_FILENO, help, _strlen(help));

    // Provide a brief description of the 'help' command
    help = "\tDisplay information about built-in commands.\n ";
    write(STDOUT_FILENO, help, _strlen(help));

    // Provide additional information about the 'help' command
    help = "Displays brief summaries of built-in commands.\n";
    write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_alias - Define or display aliases.
 * Return: None.
 */
void aux_help_alias(void) {
    // Display the usage information for the 'alias' command
    char *help = "alias: alias [-p] [name[=value]...]\n";
    write(STDOUT_FILENO, help, _strlen(help));

    // Provide a brief description of the 'alias' command
    help = "\tDefine or display aliases.\n ";
    write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_cd - Change the shell working directory.
 * Return: None.
 */
void aux_help_cd(void) {
    // Display the usage information for the 'cd' command
    char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";
    write(STDOUT_FILENO, help, _strlen(help));

    // Provide a brief description of the 'cd' command
    help = "\tChange the shell working directory.\n ";
    write(STDOUT_FILENO, help, _strlen(help));
}

