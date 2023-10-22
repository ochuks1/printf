#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
int printed_chars = 0;
va_list args;
va_start(args, format);
while (*format)
{
if (*format != '%')
{
putchar(*format);
printed_chars++;
}
else
{
format++;
if (*format == 'c')
{
int character = va_arg(args, int);
putchar(character);
printed_chars++;
}
else if (*format == 's')
{
char *str = va_arg(args, char *);
while (*str)
{
putchar(*str);
printed_chars++;
str++;
}
}
else if (*format == '%')
{
putchar('%');
printed_chars++;
}
}
format++;
}
va_end(args);
return printed_chars;
}
