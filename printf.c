#include "main.h"
#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...)
{
    va_list args;
    char buffer[BUFFER_SIZE];
    int count = 0;
    int i = 0;
    int print_char(va_list args);
    int print_string(va_list args);
    int print_integer(va_list args);
    int print_binary(va_list args);
    int print_unsigned(va_list args, char format);
    int print_str_non_printable(va_list args);

    va_start(args, format);
    while (format && *format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0')
                return (-1);

            
	    if (*format == 'c')
                count += print_char(args);
            else if (*format == 's')
                count += print_string(args);
            else if (*format == '%')
            {
                write(1, "%", 1);
                count++;
            }
            else if (*format == 'd' || *format == 'i')
                count += print_integer(args);
            else if (*format == 'b')
                count += print_binary(args);
            else if (*format == 'u' || *format == 'o' || *format == 'x' || *format == 'X')
                count += print_unsigned(args, *format);
            else if (*format == 'S')
                count += print_str_non_printable(args);
        }
        else
        {
            if (i == BUFFER_SIZE - 1)
            {
                write(1, buffer, i);
                i = 0;
            }
            buffer[i] = *format;
            count++;
            i++;
        }
        format++;
    }
    if (i > 0)
        write(1, buffer, i);

    va_end(args);
    return count;
}
