#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...)
{
    int printed_chars = 0;
    va_list args;

    /* Implement handling of %c, %s, and %% here */

    va_start(args, format);

    /* Loop through the format string and handle conversions */
    while (*format)
    {
        if (*format == '%')
        {
            format++; /* Move to the next character */
            if (*format == '\0') /* Handle format string ending with '%' */
                break;
            if (*format == 'c')
            {
                /* Handle %c */
                char c = va_arg(args, int);
                /* Print the character c here */
                /* Increment printed_chars accordingly */
            }
            else if (*format == 's')
            {
                /* Handle %s */
                char *str = va_arg(args, char *);
                if (str == NULL)
                {
                    /* Handle NULL string */
                    /* Print (null) and increment printed_chars */
                }
                else
                {
                    /* Print the string str and increment printed_chars */
                }
            }
            else if (*format == '%')
            {
                /* Handle %% */
                /* Print % and increment printed_chars */
            }
            /* Handle other conversion specifiers as needed */
        }
        else
        {
            /* Handle regular characters */
            /* Print the character and increment printed_chars */
        }
        format++; /* Move to the next character in the format string */
    }
    else if (*format == 'b')
{
    /* Handle %b */
    unsigned int num = va_arg(args, unsigned int);
    /* Convert num to binary and print it */
    /* Increment printed_chars accordingly */
}
else if (*format == 'u')
{
    /* Handle %u */
    unsigned int num = va_arg(args, unsigned int);
    /* Print the unsigned integer num and increment printed_chars */
}
else if (*format == 'o')
{
    /* Handle %o */
    unsigned int num = va_arg(args, unsigned int);
    /* Convert num to octal and print it */
    /* Increment printed_chars accordingly */
}
else if (*format == 'x' || *format == 'X')
{
    /* Handle %x and %X */
    unsigned int num = va_arg(args, unsigned int);
    /* Convert num to hexadecimal (lowercase or uppercase) and print it */
    /* Increment printed_chars accordingly */
}
/* Define a local buffer of 1024 chars for efficient writing */
char buffer[1024];
int buffer_index = 0;

else if (*format == 'p')
{
    /* Handle %p */
    void *ptr = va_arg(args, void *);
    /* Print the pointer address in hexadecimal format */
    /* Increment printed_chars accordingly */
}
else if (*format == 'R')
{
    /* Handle %R */
    char *str = va_arg(args, char *);
    if (str == NULL)
    {
        /* Handle NULL string */
        /* Print (null) and increment printed_chars */
    }
    else
    {
        /* Apply ROT13 transformation to the string str and print it */
        /* Increment printed_chars accordingly */
    }
}

    va_end(args);

    return printed_chars;
}
