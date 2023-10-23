#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - custom printf function.
 * @format: format string
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
va_list args;
char buffer[1024];
int char_count = 0;
int i = 0;
va_start(args, format);

while (format[i] != '\0')
{
if (format[i] != '%')
{
buffer[char_count++] = format[i];
if (char_count == 1023)
{
buffer[char_count] = '\0';
write(1, buffer, char_count);
char_count = 0;
}
}
else
{
i++; /* Move past the '%' */

if (format[i] == '\0')
{
break; /* Format string ends with a '%', so we break. */
}
if (format[i] == 'c')
{
char c = va_arg(args, int);
buffer[char_count++] = c;
}
else if (format[i] == 's')
{
const char *str = va_arg(args, const char *);
while (*str)
{
buffer[char_count++] = *str++;
if (char_count == 1024)
{
buffer[char_count] = '\0';
write(1, buffer, char_count);
char_count = 0;
}
}
}
else if (format[i] == '%')
{
buffer[char_count++] = '%';
}
else if (format[i] == 'd' || format[i] == 'i')
{
int num = va_arg(args, int);
char_count += sprintf(buffer + char_count, "%d", num);
}
else if (format[i] == 'b')
{
unsigned int num = va_arg(args, unsigned int);
char_count += sprintf(buffer + char_count, "%b", num);
}
else if (format[i] == 'u')
{
unsigned int num = va_arg(args, unsigned int);
char_count += sprintf(buffer + char_count, "%u", num);
}
else if (format[i] == 'o')
{
unsigned int num = va_arg(args, unsigned int);
char_count += sprintf(buffer + char_count, "%o", num);
}
else if (format[i] == 'x' || format[i] == 'X')
{
unsigned int num = va_arg(args, unsigned int);
char_count += sprintf(buffer + char_count, format[i] == 'x' ? "%x" : "%X", num);
}
else if (format[i] == 'S')
{
const char *str = va_arg(args, const char *);
while (*str)
{
if (*str >= 32 && *str < 127)
{
buffer[char_count++] = *str++;
}
else
{
char_count += sprintf(buffer + char_count, "\\x%02X", *str);
str++;
}
if (char_count == 1024)
{
buffer[char_count] = '\0';
write(1, buffer, char_count);
char_count = 0;
}
}
}
}

if (char_count == 1024)
{
buffer[char_count] = '\0';
write(1, buffer, char_count);
char_count = 0;
}
i++;
}
buffer[char_count] = '\0';
write(1, buffer, char_count);
va_end(args);
return (char_count);
{
return -1;
}
}
