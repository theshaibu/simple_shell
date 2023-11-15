#include "shell.h"

/**
 * get_length - Computes the length of an integer.
 * @n: Integer value.
 * Return: Length of the integer.
 */
int get_length(int n) {
    unsigned int n1;
    int length = 1;

    if (n < 0) {
        length++;
        n1 = n * -1;
    } else {
        n1 = n;
    }

    while (n1 > 9) {
        length++;
        n1 = n1 / 10;
    }

    return (length);
}

/**
 * aux_itoa - Converts an integer to a string.
 * @n: Integer value.
 * Return: String representation of the integer.
 */
char *aux_itoa(int n) {
    unsigned int n1;
    int length = get_length(n);
    char *buffer;

    buffer = malloc(sizeof(char) * (length + 1));
    if (buffer == 0)
        return (NULL);

    *(buffer + length) = '\0';

    if (n < 0) {
        n1 = n * -1;
        buffer[0] = '-';
    } else {
        n1 = n;
    }

    length--;
    do {
        *(buffer + length) = (n1 % 10) + '0';
        n1 = n1 / 10;
        length--;
    } while (n1 > 0);

    return (buffer);
}

/**
 * _atoi - Converts a string to an integer.
 * @s: Input string.
 * Return: Converted integer value.
 */
int _atoi(char *s) {
    unsigned int count = 0, size = 0, result = 0, sign = 1, multiplier = 1, i;

    while (*(s + count) != '\0') {
        if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
            break;

        if (*(s + count) == '-')
            sign *= -1;

        if ((*(s + count) >= '0') && (*(s + count) <= '9')) {
            if (size > 0)
                multiplier *= 10;
            size++;
        }
        count++;
    }

    for (i = count - size; i < count; i++) {
        result = result + ((*(s + i) - '0') * multiplier);
        multiplier /= 10;
    }

    return (result * sign);
}

