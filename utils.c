#include "main.h"

/**
 * get_print_func - Get the appropriate print function for a format specifier
 * @c: Format specifier
 *
 * Return: Pointer to the print function, or NULL if not found
 */
int (*get_print_func(char c))(va_list)
{
    switch (c)
    {
    case 'c':
        return print_char;
    case 's':
        return print_string;
    case 'd':
    case 'i':
        return print_integer;
    case 'b':
        return print_binary;
    case 'u':
        return print_unsigned;
    case 'o':
        return print_octal;
    case 'x':
        return print_hex;
    case 'X':
        return print_hex;
    case 'S':
        return print_str_non_printable;
    default:
        return NULL;
    }
}
