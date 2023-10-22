#include <math.h>

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int _printf(const char *format, ...)
{
    int chars_printed = 0;
    va_list args;

    va_start(args, format);

    while (*format)
    {
        int width = 0;
        int precision = -1;
        

        if (*format != '%')
        {
            putchar(*format);
            chars_printed++;
        }
        else
        {
            format++;
            while (*format == '0')
            {
               
                format++;
            }

            while (*format >= '0' && *format <= '9')
            {
                width = width * 10 + (*format - '0');
                format++;
            }

            if (*format == '.')
            {
                format++;
                precision = 0;
                while (*format >= '0' && *format <= '9')
                {
                    precision = precision * 10 + (*format - '0');
                    format++;
                }
            }

            while (*format == 'l' || *format == 'h')
            {
                if (*format == 'l')
                    
                else if (*format == 'h')
         
                format++;
            }

            if (*format == 'c')
            {
                char c = va_arg(args, int);
                putchar(c);
                chars_printed++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                int i;
		
                int i = 0;
while (str[i] != '\0')
				i++;
                {
                    putchar(str[i]);
                    chars_printed++;
                }
            }
            else if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
                int count = 0;
                int temp = num;
                while (temp != 0)
                {
                    temp /= 10;
                    count++;
                }
               int i = 0;
	       while( i < count) 
		       i++;
                {
                    putchar('0' + (num / pow(10, count - i - 1)) % 10);
                    chars_printed++;
                }
            }
            else if (*format == 'u' || *format == 'o' || *format == 'x' || *format == 'X')
            {
                /* Handle other specifiers (u, o, x, X) */
            }
        }

        format++;
    }

    va_end(args);
    return chars_printed;
}
