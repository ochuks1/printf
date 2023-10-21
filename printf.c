#include <unistd.h>
#include "main.h"
#include <stdarg.h>

/**
 * _printf - Custom printf function.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	if (format)
	{
		va_start(args, format);
		while (*format)
		{
			if (*format == '%')
			{
				format++;
				if (*format == '\0')
					break;
				else if (*format == 'c')
					count += _putchar(va_arg(args, int));
				else if (*format == 's')
					count += print_string(va_arg(args, char *));
				else if (*format == '%')
					count += _putchar('%');
			}
			else
			{
				count += _putchar(*format);
			}
			format++;
		}
		va_end(args);
	}
	return (count);
}

/**
 * print_string - Print a string.
 * @str: The string to print.
 *
 * Return: The number of characters printed.
 */
int print_string(char *str)
{
	int count = 0;
	if (str)
	{
		while (*str)
		{
			count += _putchar(*str);
			str++;
		}
	}
	return (count);
}
