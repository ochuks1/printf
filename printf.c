#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Print formatted text to stdout.
 * @format: A pointer to the format string.
 * @...: Optional arguments for the format string.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;        /* Stores the variable arguments */
	int count = 0;       /* Keeps track of the character count */
	const char *c = format; /* Pointer to the format string */
	char buffer[1024];    /* Local buffer for output */

	va_start(args, format); /* Initialize the variable arguments */

	while (*c)
	{
		if (*c == '%')
		{
			c++;

			/* Initialize flags to zero */
			int plus_flag = 0;
			int space_flag = 0;
			int hash_flag = 0;

			/* Check for flags */
			while (*c == '+' || *c == ' ' || *c == '#')
			{
				if (*c == '+')
					plus_flag = 1;
				else if (*c == ' ')
					space_flag = 1;
				else if (*c == '#')
					hash_flag = 1;
				c++;
			}

			if (*c == 'd' || *c == 'i')
			{
				/* Handle d and i with flags */
				int num = va_arg(args, int);
				char format_str[8] = "%";
				if (plus_flag)
					strcat(format_str, "+");
				if (space_flag)
					strcat(format_str, " ");
				if (hash_flag)
					strcat(format_str, "#");
				strcat(format_str, "d");
				int n = snprintf(buffer + count, sizeof(buffer) - count, format_str, num);
				if (n < 0)
					return -1; /* Handle error */
				count += n;
			}
			/* Handle other conversion specifiers similarly */
		}
		else
		{
			buffer[count] = *c;
			count++;
		}

		if (count >= sizeof(buffer) - 1)
		{
			buffer[count] = '\0';
			write(1, buffer, count);
			count = 0;
		}

		c++;
	}

	if (count > 0)
	{
		buffer[count] = '\0';
		write(1, buffer, count);
	}

	va_end(args);
	return count;
}
