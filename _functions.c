#include "main.h"
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>


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
    return (count);
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
    return (count);
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
    return (count);
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
return (count);
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
char hex[5];
/* "\x00" + NULL terminator */
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
return (count);
}
