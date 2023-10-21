#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    int printed_chars = 0;
    va_list args;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0')
                break;

            if (*format == 'c')
            {
                char c = va_arg(args, int);
                write(1, &c, 1);
                printed_chars++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                if (str == NULL)
                {
                    write(1, "(null)", 6);
                    printed_chars += 6;
                }
                else
                {
                    while (*str)
                    {
                        write(1, str, 1);
                        str++;
                        printed_chars++;
                    }
                }
            }
            else if (*format == '%')
            {
                write(1, "%", 1);
                printed_chars++;
            }
            else if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
                char buffer[12]; /* Maximum number of digits in a 32-bit integer */
                int count = 0;
                
                if (num < 0)
                {
                    write(1, "-", 1);
                    printed_chars++;
                    num = -num;
                }
                
                if (num == 0)
                {
                    write(1, "0", 1);
                    printed_chars++;
                }
                else
                {
                    while (num > 0)
                    {
                        buffer[count++] = (num % 10) + '0';
                        num /= 10;
                    }
                    while (count > 0)
                    {
                        write(1, &buffer[--count], 1);
                        printed_chars++;
                    }

		     else if (*format == 'b')
            {
                unsigned int num = va_arg(args, unsigned int);
                char binary[32]; // Maximum bits for a 32-bit integer
                int i = 0;

                while (i < 32)
                {
                    binary[i] = (num & 1) + '0';
                    num >>= 1;
                    i++;
                }

                while (i > 0)
                {
                    write(1, &binary[--i], 1);
                    printed_chars++;
		}
                }
            }
        }
        else
        {
            write(1, format, 1);
            printed_chars++;
        }
        format++;
    }

    va_end(args);

    return printed_chars;
}
