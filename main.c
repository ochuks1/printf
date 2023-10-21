#include "main.h"
#include <unistd.h>
#include <stdarg.h>

int print_char(va_list args);
int print_string(va_list args);
int print_integer(va_list args);
int print_binary(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args, int uppercase);
int print_str_non_printable(va_list args);

int (*get_print_func(char c))(va_list);

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);
    while (format && *format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0')
                return (-1);  /* Incomplete format specifier */

            if (*format == 'c')
                count += print_char(args);
            else if (*format == 's')
                count += print_string(args);
            else if (*format == 'd' || *format == 'i')
                count += print_integer(args);
            else if (*format == 'b')
                count += print_binary(args);
            else if (*format == 'u')
                count += print_unsigned(args);
            else if (*format == 'o')
                count += print_octal(args);
            else if (*format == 'x')
                count += print_hex(args, 0); /* Lowercase hexadecimal */
            else if (*format == 'X')
                count += print_hex(args, 1); /* Uppercase hexadecimal */
            else if (*format == 'S')
                count += print_str_non_printable(args);
            else
                return (-1);  /* Unsupported format specifier */
        }
        else
        {
            write(1, format, 1);
            count++;
        }
        format++;
    }
    va_end(args);
    return count;
}

int main(void)
{
    int len;
    len = _printf("Let's try to printf a simple sentence.\n");
    _printf("Length:[%d]\n", len);
    len = _printf("Character:[%c]\n", 'H');
    _printf("Length:[%d]\n", len);
    len = _printf("Integer:[%d]\n", 12345);
    _printf("Length:[%d]\n", len);
    len = _printf("Binary:[%b]\n", 98);
    _printf("Length:[%d]\n", len);
    len = _printf("Unsigned:[%u]\n", 4294967295U);
    _printf("Length:[%d]\n", len);
    len = _printf("Octal:[%o]\n", 12345);
    _printf("Length:[%d]\n", len);
    len = _printf("Hex:[%x]\n", 255);
    _printf("Length:[%d]\n", len);
    len = _printf("Uppercase Hex:[%X]\n", 255);
    _printf("Length:[%d]\n", len);
    len = _printf("String with non-printable:[%S]\n", "Hello, \x01World!");
    _printf("Length:[%d]\n", len);
    return (0);
}
