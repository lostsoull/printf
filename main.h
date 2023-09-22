#ifndef CUSTOM_PRINTF_H
#define CUSTOM_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED_PARAM(x) (void)(x)
#define BUFFER_SIZE 1024

/* Format Flags */
#define FORMAT_MINUS 1
#define FORMAT_PLUS 2
#define FORMAT_ZERO 4
#define FORMAT_HASH 8
#define FORMAT_SPACE 16

/* Size Specifiers */
#define SIZE_LONG 2
#define SIZE_SHORT 1

/**
 * struct FormatHandler - Structure for format specifier handler
 *
 * @fmt: The format specifier.
 * @handler_fn: The associated handler function.
 */
struct FormatHandler
{
    char fmt;
    int (*handler_fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct FormatHandler FormatHandler_t - Typedef for format specifier handler
 *
 * @fmt: The format specifier.
 * @handler_fn: The associated handler function.
 */
typedef struct FormatHandler FormatHandler_t;

int custom_printf(const char *format, ...);
int handle_format_specifier(const char *fmt, int *i,
    va_list arg_list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTION PROTOTYPES ******************/

/* Functions for printing characters and strings */
int print_char_handler(va_list arg_list, char buffer[],
    int flags, int width, int precision, int size);
int print_string_handler(va_list arg_list, char buffer[],
    int flags, int width, int precision, int size);
int print_percent_handler(va_list arg_list, char buffer[],
    int flags, int width, int precision, int size);

/* Functions for printing numbers */
int print_int_handler(va_list arg_list, char buffer[],
    int flags, int width, int precision, int size);
int print_binary_handler(va_list arg_list, char buffer[],
    int flags, int width, int precision, int size);
int print_unsigned_handler(va_list arg_list, char buffer[],
    int flags, int width, int precision, int size);
int print_octal_handler(va_list arg_list, char buffer[],
    int flags, int width, int precision, int size);
int print_hexadecimal_handler(va_list arg_list, char buffer[],
    int flags, int width, int precision, int size);
int print_hexa_upper_handler(va_list arg_list, char buffer[],
    int flags, int width, int precision, int size);

int print_hexadecimal_custom(va_list arg_list, char map_to[],
    char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function for printing non-printable characters */
int print_non_printable_handler(va_list arg_list, char buffer[],
    int flags, int width, int precision, int size);

/* Function for printing memory address */
int print_pointer_handler(va_list arg_list, char buffer[],
    int flags, int width, int precision, int size);

/* Functions for handling other specifiers */
int get_format_flags(const char *format, int *i);
int get_format_width(const char *format, int *i, va_list arg_list);
int get_format_precision(const char *format, int *i, va_list arg_list);
int get_format_size(const char *format, int *i);

/* Function for printing strings in reverse */
int print_reverse_string(va_list arg_list, char buffer[],
    int flags, int width, int precision, int size);

/* Function for printing a string in ROT13 */
int print_rot13_string(va_list arg_list, char buffer[],
    int flags, int width, int precision, int size);

/* Width handler functions */
int handle_char_write(char c, char buffer[],
    int flags, int width, int precision, int size);
int write_formatted_number(int is_positive, int ind, char buffer[],
    int flags, int width, int precision, int size);
int write_formatted_num(int ind, char bff[], int flags, int width, int precision,
    int length, char padd, char extra_c);
int write_formatted_pointer(char buffer[], int ind, int length,
    int width, int flags, char padd, char extra_c, int padd_start);

int write_formatted_unsgnd(int is_negative, int ind,
    char buffer[],
    int flags, int width, int precision, int size);

/****************** UTILITY FUNCTIONS ******************/
int is_printable_char(char);
int append_hexadecimal_code(char, char[], int);
int is_digit_char(char);

long int convert_formatted_number(long int num, int size);
long int convert_formatted_unsigned(unsigned long int num, int size);

#endif /* CUSTOM_PRINTF_H */

