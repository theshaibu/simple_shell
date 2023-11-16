#include "shell.h"

/**
 * Checks if the shell is in interactive mode.
 * @info: Address of a struct containing information.
 *
 * Returns 1 if the shell is in interactive mode, and 0 otherwise.
 */
int interactive(info_t *info) {
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * Checks if a given character is a delimiter in a specified delimiter string.
 * @c: The character to check.
 * @delim: The delimiter string.
 *
 * Returns 1 if the character is a delimiter, and 0 otherwise.
 */
int is_delim(char c, char *delim) {
    while (*delim) {
        if (*delim++ == c)
            return 1;
    }
    return 0;
}

/**
 * Checks if a given character is alphabetic.
 * @c: The character to check.
 *
 * Returns 1 if the character is alphabetic, and 0 otherwise.
 */
int _isalpha(int c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? 1 : 0;
}

/**
 * Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Returns 0 if there are no numbers in the string; otherwise, returns the converted number.
 */
int _atoi(char *s) {
    int i, sign = 1, flag = 0, output;
    unsigned int result = 0;

    for (i = 0; s[i] != '\0' && flag != 2; i++) {
        if (s[i] == '-')
            sign *= -1;

        if (s[i] >= '0' && s[i] <= '9') {
            flag = 1;
            result *= 10;
            result += (s[i] - '0');
        } else if (flag == 1)
            flag = 2;
    }

    output = (sign == -1) ? -result : result;
    return output;
}

