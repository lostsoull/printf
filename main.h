#ifndef CUSTOM_PRINTF_H
#define CUSTOM_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

/* FLAGS */
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

/* SIZES */
#define SIZE_LONG 2
#define SIZE_SHORT 1

/**
 * struct custom_format - Struct format_t
 *
 * @format: The format.
 * @function: The associated function.
 */
struct custom_format
{
    char format;
    int (*function)(va_list, char[], int, int, int, int);
};

typedef struct custom_format custom_format_t;

int custom_printf(const char *format, ...);
int handle_custom_print(const char *format, int *i,
                       va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Functions to print characters and strings */
int print_custom_char(va_list args, char buffer[],
                     int flags, int width, int precision, int size);
int print_custom_string(va_list args, char buffer[],
                       int flags, int width, int precision, int size);
int print_custom_percent(va_list args, char buffer[],
                        int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_custom_int(va_list args, char buffer[],
                    int flags, int width, int precision, int size);
int print_custom_binary(va_list args, char buffer[],
                        int flags, int width, int precision, int size);
int print_custom_unsigned(va_list args, char buffer[],
                         int flags, int width, int precision, int size);
int print_custom_octal(va_list args, char buffer[],
                       int flags, int width, int precision, int size);
int print_custom_hexadecimal(va_list args, char buffer[],
                            int flags, int width, int precision, int size);
int print_custom_hexa_upper(va_list args, char buffer[],
                            int flags, int width, int precision, int size);

int print_custom_hexa(va_list args, char map_to[], char buffer[], int flags,
                      char flag_ch, int width, int precision, int size);

/* Function to print non-printable characters */
int print_custom_non_printable(va_list args, char buffer[],
                               int flags, int width, int precision, int size);

/* Function to print memory addresses */
int print_custom_pointer(va_list args, char buffer[],
                        int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int get_custom_flags(const char *format, int *i);
int get_custom_width(const char *format, int *i, va_list list);
int get_custom_precision(const char *format, int *i, va_list list);
int get_custom_size(const char *format, int *i);

/* Function to print strings in reverse */
int print_custom_reverse(va_list args, char buffer[],
                        int flags, int width, int precision, int size);

/* Function to print a string in ROT13 */
int print_custom_rot13_string(va_list args, char buffer[],
                              int flags, int width, int precision, int size);

/* Width handler */
int handle_custom_write_char(char c, char buffer[], int flags, int width, int precision, int size);
int write_custom_number(int is_positive, int ind, char buffer[], int flags, int width, int precision, int size);
int write_custom_num(int ind, char bff[], int flags, int width, int precision, int length, char padd, char extra_c);
int write_custom_pointer(char buffer[], int ind, int length, int width, int flags, char padd, char extra_c, int padd_start);
int write_custom_unsigned(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_custom_printable(char ch);
int append_custom_hexa_code(char hex, char buffer[], int ind);
int is_custom_digit(char ch);

long int custom_convert_size_number(long int num, int size);
long int custom_convert_size_unsigned(unsigned long int num, int size);

#endif /* CUSTOM_PRINTF_H */
