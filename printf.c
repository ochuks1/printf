#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * _printf - Custom printf implementation with various format specifiers.
 * @format: The format string.
 * @...: Additional arguments for format specifiers.
 *
 * Return: Number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int chars_printed = 0;
    char buffer[BUFFER_SIZE];
    int buffer_index = 0;
    const char *str = va_arg(args, const char *);
    int num = va_arg(args, int);
    int printed_chars = snprintf(&buffer[buffer_index], BUFFER_SIZE - buffer_index, "%d", num);

    char c;

    while ((c = *format++) != '\0') {
        if (c != '%') {
            buffer[buffer_index++] = c;
            chars_printed++;
        } else {
            c = *format++;
            switch (c) {
                case 'c':
                    buffer[buffer_index++] = va_arg(args, int);
                    chars_printed++;
                    break;
                case 's': {
                  
                    while (*str) {
                        buffer[buffer_index++] = *str++;
                        chars_printed++;
                    }
                    break;
                }
                case '%':
                    buffer[buffer_index++] = '%';
                    chars_printed++;
                    break;
                case 'd':
                case 'i':
{
                     
    if (printed_chars > 0) {
        buffer_index += printed_chars;
        chars_printed += printed_chars;
}
                    
                    break;
                case 'u':
                    {
    unsigned int num = va_arg(args, unsigned int);
    int printed_chars = snprintf(&buffer[buffer_index], BUFFER_SIZE - buffer_index, "%u", num);
    if (printed_chars > 0) {
        buffer_index += printed_chars;
        chars_printed += printed_chars;
    }
                    break;
                case 'o':
                   {
    unsigned int num = va_arg(args, unsigned int);
    int printed_chars = snprintf(&buffer[buffer_index], BUFFER_SIZE - buffer_index, "%o", num);
    if (printed_chars > 0) {
        buffer_index += printed_chars;
        chars_printed += printed_chars;
    }
                    break;
                case 'x':
                case 'X':
                    {
    unsigned int num = va_arg(args, unsigned int);
    /* Use 'x' for lowercase and 'X' for uppercase hexadecimal representation */
    int printed_chars = snprintf(&buffer[buffer_index], BUFFER_SIZE - buffer_index, c == 'x' ? "%x" : "%X", num);
    if (printed_chars > 0) {
        buffer_index += printed_chars;
        chars_printed += printed_chars;
    }
                    break;
                case 'p':
                    {
    void *ptr = va_arg(args, void *);
    int printed_chars = snprintf(&buffer[buffer_index], BUFFER_SIZE - buffer_index, "%p", ptr);
    if (printed_chars > 0) {
        buffer_index += printed_chars;
        chars_printed += printed_chars;
    }
                    break;
                case 'e':
                case 'E':
                   {
    double num = va_arg(args, double);
    /* Use 'e' for lowercase and 'E' for uppercase scientific notation representation */
    int printed_chars = snprintf(&buffer[buffer_index], BUFFER_SIZE - buffer_index, c == 'e' ? "%e" : "%E", num);
    if (printed_chars > 0) {
        buffer_index += printed_chars;
        chars_printed += printed_chars;
    }
                    break;
                /* Add support for more format specifiers as needed */
                default:
                    /* Unsupported format specifier, ignore it. */
                    break;
            }
        }

        if (buffer_index >= BUFFER_SIZE) {
            write(STDOUT_FILENO, buffer, buffer_index);
            buffer_index = 0;
        }
    }

    if (buffer_index > 0) {
        write(STDOUT_FILENO, buffer, buffer_index);
    }
    format++;

    va_end(args);
    return chars_printed;
return -;
		   }
