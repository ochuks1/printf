#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"


/**
 * _strlen - Calculate the length of a string
 * @s: The input string
 *
 * Return: The length of the string
 */
int _strlen(const char *s)
{
    int len = 0;

    while (s[len])
        len++;

    return len;
}

/**
 * itoa - Convert an integer to a string
 * @n: The integer to convert
 * @s: The buffer to store the result
 */
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do
    {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/**
 * itoa_binary - Convert an integer to a binary string
 * @n: The integer to convert
 * @s: The buffer to store the result
 */
void itoa_binary(unsigned int n, char s[])
{
    int i = 0;

    if (n == 0)
    {
        s[i] = '0';
        s[i + 1] = '\0';
        return;
    }

    while (n > 0)
    {
        s[i++] = (n & 1) + '0';
        n >>= 1;
    }
    s[i] = '\0';

    reverse(s);
}

/**
 * itoa_octal - Convert an integer to an octal string
 * @n: The integer to convert
 * @s: The buffer to store the result
 */
void itoa_octal(unsigned int n, char s[])
{
    int i = 0;

    if (n == 0)
    {
        s[i] = '0';
        s[i + 1] = '\0';
        return;
    }

    while (n > 0)
    {
        s[i++] = (n % 8) + '0';
        n /= 8;
    }
    s[i] = '\0';

    reverse(s);
}

/**
 * itoa_hex - Convert an integer to a hexadecimal string
 * @n: The integer to convert
 * @s: The buffer to store the result
 * @format: The format specifier ('x' or 'X')
 */
void itoa_hex(unsigned int n, char s[], char format)
{
    int i = 0;
    char hexChars[] = "0123456789abcdef";

    while (n > 0)
    {
        if (format == 'X')
            s[i++] = hexChars[(n % 16) - 10];
        else
            s[i++] = hexChars[n % 16];
        n /= 16;
    }

    s[i] = '\0';

    reverse(s);
}

/**
 * reverse - Reverse a string
 * @s: The string to reverse
 */
void reverse(char s[])
{
    int i, j;
    char c;

    for (i = 0, j = _strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/**
 * _printf - Custom printf function
 * @format: The format string
 * @...: Additional arguments
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;

    va_start(args, format);

    while (format && *format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c')
                count += print_char(args);
            else if (*format == 's')
                count += print_string(args);
            else if (*format == 'd' || *format == 'i')
                count += print_integer(args);
            else if (*format == 'b')
                count += print_binary(args);
            else if (*format == 'u')
                count += print_unsigned(args, *format);
            else if (*format == 'o' || *format == 'x' || *format == 'X')
                count += print_unsigned(args, *format);
            else if (*format == 'S')
                count += print_str_non_printable(args);
            else if (*format == 'p')
                count += print_pointer(args);
            else if (*format == '%')
                count += print_percent();
            format++;
        }
        else
        {
            write(1, format, 1);
            count++;
            format++;
        }
    }

    va_end(args);
    return count;
}

/**
 * print_char - Print a character
 * @args: The va_list containing the character
 *
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);
    return write(1, &c, 1);
}

/**
 * print_string - Print a string
 * @args: The va_list containing the string
 *
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    if (str == NULL)
        str = "(null)";
    return write(1, str, _strlen(str));
}

/**
 * print_integer - Print an integer
 * @args: The va_list containing the integer
 *
 * Return: Number of characters printed
 */
int print_integer(va_list args)
{
    int n = va_arg(args, int);
    char buffer[11];
    int count = 0;

    itoa(n, buffer);
    while (buffer[count])
    {
        count += write(1, &buffer[count], 1);
    }

    return count;
}

/**
 * print_binary - Print an unsigned integer in binary
 * @args: The va_list containing the integer
 *
 * Return: Number of characters printed
 */
int print_binary(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    char binary[32];
    int count = 0;

    if (n == 0)
        return write(1, "0", 1);

    itoa_binary(n, binary);

    while (binary[count])
    {
        count += write(1, &binary[count], 1);
    }

    return count;
}

/**
 * print_unsigned - Print an unsigned integer in various bases
 * @args: The va_list containing the integer
 * @format: The format specifier ('u', 'o', 'x', 'X')
 *
 * Return: Number of characters printed
 */
int print_unsigned(va_list args, char format)
{
    unsigned int n = va_arg(args, unsigned int);
    char buffer[20];
    int count = 0;

    if (format == 'u')
        itoa(n, buffer);
    else if (format == 'o')
        itoa_octal(n, buffer);
    else if (format == 'x' || format == 'X')
        itoa_hex(n, buffer, format);

    while (buffer[count])
    {
        count += write(1, &buffer[count], 1);
    }

    return count;
}

/**
 * print_str_non_printable - Print a string with non-printable characters escaped
 * @args: The va_list containing the string
 *
 * Return: Number of characters printed
 */
int print_str_non_printable(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (str == NULL)
        str = "(null)";

    for (int i = 0; str[i]; i++)
    {
        if (str[i] < 32 || str[i] >= 127)
        {
            write(1, "\\x", 2);
            if (str[i] < 16)
                write(1, "0", 1);
            itoa_hex((int)str[i], buffer, 'x');
            write(1, buffer, 2);
            count += 4;
        }
        else
        {
            write(1, &str[i], 1);
            count++;
        }
    }

    return count;
}

/**
 * print_percent - Print a percent character
 *
 * Return: Number of characters printed
 */
int print_percent(void)
{
    return write(1, "%", 1);
}

/**
 * print_pointer - Print a pointer address
 * @args: The va_list containing the pointer
 *
 * Return: Number of characters printed
 */
int print_pointer(va_list args)
{
    void *ptr = va_arg(args, void *);
    char buffer[20];
    int count = 0;

    write(1, "0x", 2);
    itoa_hex((unsigned long)ptr, buffer, 'x');
    write(1, buffer, 16);
    count += 18;

    return count;
}
