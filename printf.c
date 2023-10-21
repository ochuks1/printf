#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_number - Helper function to print integers
 * @n: Integer to print
 * @count: Pointer to the count of printed characters
 */
void print_number(int n, int *count)
{
    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
        (*count)++;
    }

    if (n / 10 != 0)
        print_number(n / 10, count);

    char c = (n % 10) + '0';
    write(1, &c, 1);
    (*count)++;
}

/**
 * print_binary - Helper function to print binary numbers
 * @num: Binary number to print
 * @count: Pointer to the count of printed characters
 */
void print_binary(unsigned int num, int *count)
{
    if (num / 2 != 0)
        print_binary(num / 2, count);

    char c = (num % 2) + '0';
    write(1, &c, 1);
    (*count)++;
}

/**
 * _printf - Our custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed.
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

            if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
                print_number(num, &printed_chars);
            }
            else if (*format == 'b')
            {
                unsigned int num = va_arg(args, unsigned int);
                print_binary(num, &printed_chars);
            }
            else if (*format == 'u')
            {
                unsigned int num = va_arg(args, unsigned int);
                print_number(num, &printed_chars);
            }
            else if (*format == 'o')
            {
                unsigned int num = va_arg(args, unsigned int);
                int count = 0;
                unsigned int temp = num;

                while (temp > 0)
                {
                    temp = temp / 8;
                    count++;
                }

                char *octal = malloc(count);
                if (octal == NULL)
                    return -1;

                octal[count] = '\0';
                count--;

                while (num > 0)
                {
                    octal[count] = (num % 8) + '0';
                    num = num / 8;
                    count--;
                }

                write(1, octal, count + 1);
                printed_chars += count + 1;
                free(octal);
            }
            else if (*format == 'x' || *format == 'X')
            {
                unsigned int num = va_arg(args, unsigned int);
                int count = 0;
                unsigned int temp = num;

                while (temp > 0)
                {
                    temp = temp / 16;
                    count++;
                }

                char *hex = malloc(count);
                if (hex == NULL)
                    return -1;

                hex[count] = '\0';
                count--;

                while (num > 0)
                {
                    int rem = num % 16;
                    if (rem < 10)
                        hex[count] = rem + '0';
                    else
                        hex[count] = (rem - 10) + ((*format == 'x') ? 'a' : 'A');
                    num = num / 16;
                   count--;
                }

                write(1, hex, count + 1);
                printed_chars += count + 1;
                free(hex);
            }
            /* Continue with similar code blocks for others */
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

