#include "main.h"
#include <unistd.h>
#include <stdarg.h>

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
    int count = 0;
    unsigned int temp = num;

    while (temp > 0)
    {
        temp = temp / 2;
        count++;
    }

    if (count == 0)
    {
        write(1, "0", 1);
        printed_chars++;
    }
    else
    {
        char *binary = malloc(count);
        if (binary == NULL)
            return -1;

        binary[count] = '\0';
        count--;

        while (num > 0)
        {
            binary[count] = (num % 2) + '0';
            num = num / 2;
            count--;
        }

        write(1, binary, count + 1);
        printed_chars += count + 1;
        free(binary);
    }
}

/* for task 3 */

else if (*format == 'u')
{
    unsigned int num = va_arg(args, unsigned int);
    print_number(num, &printed_chars);
}
else if (*format == 'o')
{
    unsigned int num = va_arg(args, unsigned int);
    if (num == 0)
    {
        write(1, "0", 1);
        printed_chars++;
    }
    else
    {
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

