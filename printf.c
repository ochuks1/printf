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
    char buffer[1024]; /* Local buffer */

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
                buffer[printed_chars] = c;
                printed_chars++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                if (str == NULL)
                {
                    str = "(null)";
                }
                while (*str)
                {
                    buffer[printed_chars] = *str;
                    str++;
                    printed_chars++;
                }
            }
            else if (*format == '%')
            {
                buffer[printed_chars] = '%';
                printed_chars++;
            }

	    
            else if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
		printf("The value of num is %d\n", num);
		     printf("%d", num);
            } else {
                putchar('%');
	    }
	    

                /* Handling for %d and %i (Task 1) */
                
 
	}
	{
	else if (*format == 'b')
            {
                unsigned int num = va_arg(args, unsigned int);
		printf("The value of num is %u\n", num);
		 print_binary(num);
            } else {
                putchar('%');
	    }
               
	       
		/* Handling for %b (Task 2) */
            }
        }
        else
        {
            buffer[printed_chars] = *format;
            printed_chars++;
        }
{
        if (printed_chars == 1024) /* Flush the buffer */
        {
            write(1, buffer, 1024);
            printed_chars = 0;
        }
}
{
if (*format == 'u') {
                unsigned int num = va_arg(args, unsigned int);
                printf("%u", num);
            } else if (*format == 'o') {
                unsigned int num = va_arg(args, unsigned int);
                printf("%o", num);
            } else if (*format == 'x') {
                unsigned int num = va_arg(args, unsigned int);
                printf("%x", num);
            } else if (*format == 'X') {
                unsigned int num = va_arg(args, unsigned int);
                printf("%X", num);
            } else {
                putchar('%');
	    }
}
        format++;
    }

    va_end(args);

    void print_binary(unsigned int num) {
    if (num > 1) {
        print_binary(num / 2);
    }
    putchar('0' + num % 2);
}

int main(void) {
    custom_printf("This is a number in binary: %b\n", 42);
    return 0;
}


    if (printed_chars > 0)
    {
        write(1, buffer, printed_chars); /* Flush any remaining characters */
    }

    return printed_chars;
}
