#include "shell.h"

/**
 * Converts a string to an integer.
 * @s: The string to be converted.
 * Return: The converted number or -1 on error.
 */
int _erratoi(char *s)
{
    int i = 0;
    unsigned long int result = 0;

    if (*s == '+')
        s++;

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            result *= 10;
            result += (s[i] - '0');
            if (result > INT_MAX)
                return -1;
        }
        else
            return -1;
    }

    return result;
}

/**
 * Prints an error message.
 * @info: The parameter and return info struct.
 * @estr: String containing specified error type.
 */
void print_error(info_t *info, char *estr)
{
    _eputs(info->fname);
    _eputs(": ");
    print_d(info->line_count, STDERR_FILENO);
    _eputs(": ");
    _eputs(info->argv[0]);
    _eputs(": ");
    _eputs(estr);
}

/**
 * Prints a decimal (integer) number.
 * @input: The input number.
 * @fd: The file descriptor to write to.
 * Return: The number of characters printed.
 */
int print_d(int input, int fd)
{
    int (*__putchar)(char) = (fd == STDERR_FILENO) ? _eputchar : _putchar;
    int i, count = 0;
    unsigned int _abs_, current;

    if (input < 0)
    {
        _abs_ = -input;
        __putchar('-');
        count++;
    }
    else
        _abs_ = input;

    current = _abs_;
    for (i = 1000000000; i > 1; i /= 10)
    {
        if (_abs_ / i)
        {
            __putchar('0' + current / i);
            count++;
        }
        current %= i;
    }
    __putchar('0' + current);
    count++;

    return count;
}

/**
 * Converts a number to a string.
 * @num: The number.
 * @base: The base.
 * @flags: Argument flags.
 * Return: The converted string.
 */
char *convert_number(long int num, int base, int flags)
{
    static char *array;
    static char buffer[50];
    char sign = 0;
    char *ptr;
    unsigned long n = num;

    if (!(flags & CONVERT_UNSIGNED) && num < 0)
    {
        n = -num;
        sign = '-';
    }

    array = (flags & CONVERT_LOWERCASE) ? "0123456789abcdef" : "0123456789ABCDEF";
    ptr = &buffer[49];
    *ptr = '\0';

    do
    {
        *--ptr = array[n % base];
        n /= base;
    } while (n != 0);

    if (sign)
        *--ptr = sign;

    return ptr;
}

/**
 * Replaces the first instance of '#' with '\0'.
 * @buf: The address of the string to modify.
 */
void remove_comments(char *buf)
{
    int i;

    for (i = 0; buf[i] != '\0'; i++)
    {
        if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
        {
            buf[i] = '\0';
            break;
        }
    }
}

