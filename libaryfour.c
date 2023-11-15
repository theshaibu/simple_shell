#include "shell.h"

/**
 * _strcat - Concatenates two strings.
 * @dest: Destination string to which the source is appended.
 * @src: Source string to be appended to the destination.
 * Return: Pointer to the destination string.
 */
char *_strcat(char *dest, const char *src) {
    int i, j;

    for (i = 0; dest[i] != '\0'; i++)
        ;

    for (j = 0; src[j] != '\0'; j++) {
        dest[i] = src[j];
        i++;
    }

    dest[i] = '\0';
    return dest;
}

/**
 * _strcpy - Copies a string.
 * @dest: Destination string where the source is copied.
 * @src: Source string to be copied.
 * Return: Pointer to the destination string.
 */
char *_strcpy(char *dest, char *src) {
    size_t a;

    for (a = 0; src[a] != '\0'; a++) {
        dest[a] = src[a];
    }
    dest[a] = '\0';

    return dest;
}

/**
 * _strcmp - Compares two strings.
 * @s1: First string for comparison.
 * @s2: Second string for comparison.
 * Return: 0 if strings are equal, positive if s1 > s2, negative if s1 < s2.
 */
int _strcmp(char *s1, char *s2) {
    int i;

    for (i = 0; s1[i] == s2[i] && s1[i]; i++)
        ;

    if (s1[i] > s2[i])
        return 1;
    if (s1[i] < s2[i])
        return -1;
    return 0;
}

/**
 * _strchr - Locates a character in a string.
 * @s: String to be searched.
 * @c: Character to be located.
 * Return: Pointer to the first occurrence of the character, or '\0' if not found.
 */
char *_strchr(char *s, char c) {
    unsigned int i = 0;

    for (; *(s + i) != '\0'; i++)
        if (*(s + i) == c)
            return (s + i);
    if (*(s + i) == c)
        return (s + i);
    return '\0';
}

/**
 * _strspn - Calculates the length of the initial segment of a string
 * consisting of only characters from another string.
 * @s: String to be searched.
 * @accept: String containing the characters to match.
 * Return: Number of characters in the initial segment that match the characters in accept.
 */
int _strspn(char *s, char *accept) {
    int i, j, bool;

    for (i = 0; *(s + i) != '\0'; i++) {
        bool = 1;
        for (j = 0; *(accept + j) != '\0'; j++) {
            if (*(s + i) == *(accept + j)) {
                bool = 0;
                break;
            }
        }
        if (bool == 1)
            break;
    }
    return i;
}

