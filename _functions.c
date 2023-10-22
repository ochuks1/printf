#include "main.h"
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

/**
 * print_char - Print a character
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);
    write(1, &c, 1);
    return 1;
}

/**
 * print_string - Print a string
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;
    if (str)
    {
        while (*str)
        {
            write(1, str, 1);
            count++;
            str++;
        }
    }
    return count;
}

/**
 * print_integer - Print an integer
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_integer(va_list args)
{
    int n = va_arg(args, int);
    char buf[12]; /* Sufficient for 32-bit integers */
    int count = snprintf(buf, sizeof(buf), "%d", n);
    write(1, buf, count);
    return count;
}

/**
 * print_binary - Print an unsigned integer in binary format
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_binary(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    char buf[33]; /* 32 binary digits + NULL terminator */
    int i, count = 0;

    if (num == 0)
    {
        write(1, "0", 1);
        return 1;
    }

    for (i = 31; i >= 0; i--)
    {
        buf[i] = (num & 1) + '0';
        num >>= 1;
    }

    buf[32] = '\0';
    while (buf[count] == '0')
        count++;

    write(1, &buf[count], 32 - count);
    return 32 - count;
}

/**
 * print_unsigned - Print an unsigned integer
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_unsigned(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    char buf[12]; /* Sufficient for 32-bit unsigned integers */
    int count = snprintf(buf, sizeof(buf), "%u", num);
    write(1, buf, count);
    return count;
}

/**
 * print_octal - Print an integer in octal format
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_octal(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    char buf[12]; /* Sufficient for 32-bit integers */
    int count = snprintf(buf, sizeof(buf), "%o", num);
    write(1, buf, count);
    return count;
}

/**
 * print_hex - Print an integer in hexadecimal format
 * @args: List of arguments
 * @uppercase: Uppercase if 1, lowercase if 0
 *
 * Return: Number of characters printed
 */
int print_hex(va_list args, int uppercase)
{
    unsigned int num = va_arg(args, unsigned int);
    char buf[12]; /* Sufficient for 32-bit integers */
    int count = 0;

    if (uppercase)
        count = snprintf(buf, sizeof(buf), "%X", num);
    else
        count = snprintf(buf, sizeof(buf), "%x", num);

    write(1, buf, count);
    return count;
}

/**
 * print_str_non_printable - Print a string with non-printable characters
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_str_non_printable(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (str)
    {
        while (*str)
        {
            if (*str < 32 || *str >= 127)
            {
                char hex[5]; /* "\x00" + NULL terminator */
                snprintf(hex, sizeof(hex), "\\x%02X", (unsigned char)(*str));
                write(1, hex, 4);
                count += 4;
            }
            else
            {
                write(1, str, 1);
                count++;
            }
            str++;
        }
    }
    return count;
}
