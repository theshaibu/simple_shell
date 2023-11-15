#include "shell.h"

/**
 * _memcpy - Copy data from one memory location to another.
 * @newptr: Destination memory address.
 * @ptr: Source memory address.
 * @size: Number of bytes to copy.
 *
 * Return: None.
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size) {
    // Typecast pointers to characters for byte-wise copy
    char *char_ptr = (char *)ptr;
    char *char_newptr = (char *)newptr;
    unsigned int i;

    // Copy each byte from the source to the destination
    for (i = 0; i < size; i++)
        char_newptr[i] = char_ptr[i];
}

/**
 * _realloc - Resize the memory block pointed to by ptr.
 * @ptr: Pointer to the original memory block.
 * @old_size: Size of the original memory block.
 * @new_size: Size of the desired new memory block.
 *
 * Return: Pointer to the resized memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size) {
    void *newptr;

    // If ptr is NULL, allocate a new block of size new_size
    if (ptr == NULL)
        return (malloc(new_size));

    // If new_size is 0, free the original block and return NULL
    if (new_size == 0) {
        free(ptr);
        return (NULL);
    }

    // If new_size is equal to old_size, return the original block
    if (new_size == old_size)
        return (ptr);

    // Allocate a new block of size new_size
    newptr = malloc(new_size);
    if (newptr == NULL)
        return (NULL);

    // Copy data from the original block to the new block
    if (new_size < old_size)
        _memcpy(newptr, ptr, new_size);
    else
        _memcpy(newptr, ptr, old_size);

    // Free the original block
    free(ptr);
    return (newptr);
}

/**
 * _reallocdp - Resize an array of pointers.
 * @ptr: Pointer to the original array.
 * @old_size: Size of the original array.
 * @new_size: Size of the desired new array.
 *
 * Return: Pointer to the resized array.
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size) {
    char **newptr;
    unsigned int i;

    // If ptr is NULL, allocate a new array of size new_size
    if (ptr == NULL)
        return (malloc(sizeof(char *) * new_size));

    // If new_size is equal to old_size, return the original array
    if (new_size == old_size)
        return (ptr);

    // Allocate a new array of size new_size
    newptr = malloc(sizeof(char *) * new_size);
    if (newptr == NULL)
        return (NULL);

    // Copy pointers from the original array to the new array
    for (i = 0; i < old_size; i++)
        newptr[i] = ptr[i];

    // Free the original array
    free(ptr);

    return (newptr);
}

