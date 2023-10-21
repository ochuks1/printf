#include "main.h"
#include <unistd.h>

/**
 * print_char - Print a character
 * @c: Character to print
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
 * @str: String to print
 *
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;
    while (str && *str)
    {
        write(1, str, 1);
        count++;
        str++;
    }
    return count;
}

/**
 * print_integer - Print an integer
 * @n: Integer to print
 *
 * Return: Number of characters printed
 */
int print_integer(va_list args)
{
    int n = va_arg(args, int);
    /* Implement the logic to convert and print the integer */
    /* You can use print_base or similar functions here */
    return 0;  /* Update this to return the actual count */
}

/**
 * print_binary - Print an unsigned integer in binary
 * @num: Unsigned integer to print in binary
 *
 * Return: Number of characters printed
 */
int print_binary(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    /* Implement the logic to convert and print the integer in binary */
    return 0;  /* Update this to return the actual count */
}
/* Implement other print functions for 'u', 'o', 'x', 'X', and 'S' */
