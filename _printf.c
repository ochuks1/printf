#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Print formatted text to stdout
 * @format: The format string containing the format specifiers
 * @...: Variadic arguments to replace format specifiers
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *c = format;
	char buffer[1024];

	va_start(args, format);

	while (*c)
	{
		if (*c == '%')
		{
			c++;
			if (*c == 'c')
			{
				int ch = va_arg(args, int);
				buffer[count] = (char)ch;
				count++;
			}
			else if (*c == 's')
			{
				char *str = va_arg(args, char *);
				while (*str)
				{
					buffer[count] = *str;
					count++;
					str++;
				}
			}
			else if (*c == 'd' || *c == 'i')
			{
				int num = va_arg(args, int);
				int n = snprintf(buffer + count, (int)(sizeof(buffer) - count), "%d", num);
				if (n < 0)
					return -1; /* Handle error */
				count += n;
			}
			else if (*c == 'u')
			{
				unsigned int num = va_arg(args, unsigned int);
				int n = snprintf(buffer + count, (int)(sizeof(buffer) - count), "%u", num);
				if (n < 0)
					return -1; /* Handle error */
				count += n;
			}
			else if (*c == 'o')
			{
				unsigned int num = va_arg(args, unsigned int);
				int n = snprintf(buffer + count, (int)(sizeof(buffer) - count), "%o", num);
				if (n < 0)
					return -1; /* Handle error */
				count += n;
			}
			else if (*c == 'x')
			{
				unsigned int num = va_arg(args, unsigned int);
				int n = snprintf(buffer + count, (int)(sizeof(buffer) - count), "%x", num);
				if (n < 0)
					return -1; /* Handle error */
				count += n;
			}
			else if (*c == 'X')
			{
				unsigned int num = va_arg(args, unsigned int);
				int n = snprintf(buffer + count, (int)(sizeof(buffer) - count), "%X", num);
				if (n < 0)
					return -1; /* Handle error */
				count += n;
			}
		}
		else
		{
			buffer[count] = *c;
			count++;
		}

		/* Check if the buffer is almost full and write if necessary */
		if (count >= (int)(sizeof(buffer) - 1))
		{
			buffer[count] = '\0'; /* Null-terminate the buffer */
			write(1, buffer, (int)count); /* Write to stdout */
			count = 0; /* Reset the count */
		}

		c++;
	}

	/* Write any remaining content in the buffer */
	if (count > 0)
	{
		buffer[count] = '\0'; /* Null-terminate the buffer */
		write(1, buffer, (int)count); /* Write to stdout */
	}

	va_end(args);
	return count;
}
