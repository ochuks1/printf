#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>


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
    void itoa_hex(unsigned int n, char* buffer, char format);
    void itoa_octal(unsigned int n, char* buffer);
    void itoa_unsigned(unsigned int n, char* buffer);
    int print_string(va_list args, int precision);
     char *str = va_arg(args, char *);
    int printed = 0;
    int print_integer(va_list args, char format, int is_positive, int width);
    int print_integer(va_list args, char format, int is_positive);
    int n = va_arg(args, int);
    char buffer[12];
    itoa(n, buffer, is_positive);



    va_start(args, format);
    while (format && *format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0')
                return (-1);

	    if (precision >= 0)
    {
        int len = _strlen(str);
        if (len > precision)
        {
            str = _strndup(str, precision);
        }
    }

    printed += _puts(str);
    return (printed);

     if (format == '+' && n >= 0)
    {
        printed += _putchar('+');
    }
    else if (format == ' ' && n >= 0)
    {
        printed += _putchar(' ');
    }

    printed += _puts(buffer);
    return (printed);

     itoa(n, buffer, is_positive);
    int printed = 0;

    if (format == '+' && n >= 0)
    {
        printed += _putchar('+');
        width--;
    }
    else if (format == ' ' && n >= 0)
    {
        printed += _putchar(' ');
        width--;
    }

    while (width > 0)
    {
        printed += _putchar(' ');
        width--;
    }

    printed += _puts(buffer);
    return (printed);

            
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

	     while (format && format[i])
    {
        if (format[i] != '%')
        {
            putchar(format[i]);
            count++;
        }

	    else
        {
            i++;
    
        }

	    else if (format[i] == 'u')
{
    count += print_unsigned(va_arg(args, unsigned int));
}
else if (format[i] == 'o')
{
    count += print_octal(va_arg(args, unsigned int));
}
else if (format[i] == 'x' || format[i] == 'X')
{
    count += print_hex(va_arg(args, unsigned int), format[i]);
}


        format++;
    }
    if (i > 0)
        write(1, buffer, i);

    va_end(args);
    return count;
return -1;

}
