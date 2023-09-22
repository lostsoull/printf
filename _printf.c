#include "main.h"

void output_buffer(char buffer[], int *buff_ind);

/**
 * custom_printf - Custom printf function
 * @format: Format string.
 * Return: Number of characters printed.
 */
int custom_printf(const char *format, ...)
{
    int i, printed = 0, printed_chars = 0;
    int flags, width, precision, size, buff_index = 0;
    va_list args;
    char output_buffer[BUFFER_SIZE];

    if (format == NULL)
        return (-1);

    va_start(args, format);

    for (i = 0; format && format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            output_buffer[buff_index++] = format[i];
            if (buff_index == BUFFER_SIZE)
                output_buffer(output_buffer, &buff_index);
            printed_chars++;
        }
        else
        {
            output_buffer(output_buffer, &buff_index);
            flags = get_flags(format, &i);
            width = get_width(format, &i, args);
            precision = get_precision(format, &i, args);
            size = get_size(format, &i);
            ++i;
            printed = handle_print(format, &i, args, output_buffer,
                                    flags, width, precision, size);
            if (printed == -1)
                return (-1);
            printed_chars += printed;
        }
    }

    output_buffer(output_buffer, &buff_index);

    va_end(args);

    return (printed_chars);
}

/**
 * output_buffer - Outputs the contents of the buffer if it exists
 * @buffer: Character array buffer
 * @buff_index: Index to add the next character (represents the length).
 */
void output_buffer(char buffer[], int *buff_index)
{
    if (*buff_index > 0)
        write(1, &buffer[0], *buff_index);

    *buff_index = 0;
}
