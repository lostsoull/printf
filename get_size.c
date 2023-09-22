#include "main.h"

/**
 * get_size - Determines the appropriate size to cast the argument
 * @format: Formatted string specifying the argument type
 * @i: Index of the current argument in the format string
 *
 * Return: The size of the argument.
 */
int get_size(const char *format, int *i)
{
    int curr_i = *i + 1;
    int size = 0;

    if (format[curr_i] == 'l')
        size = S_LONG;
    else if (format[curr_i] == 'h')
        size = S_SHORT;

    if (size == 0)
        *i = curr_i - 1;
    else
        *i = curr_i;

    return size;
}

