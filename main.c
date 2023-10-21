#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Variable number of arguments
 *
 * Return: Number of characters printed
 */
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
                count += print_char(va_arg(args, int));
            else if (*format == 's')
                count += print_string(va_arg(args, char *));
            else if (*format == 'd' || *format == 'i')
                count += print_integer(va_arg(args, int));
            else if (*format == 'b')
                count += print_binary(va_arg(args, unsigned int));
            /* Implement other format specifiers as needed */
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
    return (0);
}
