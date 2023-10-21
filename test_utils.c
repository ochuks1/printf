#include "main.h"
#include <stdio.h>

int main(void)
{
    char format_specifiers[] = {'c', 's', 'd', 'i', 'b', 'u', 'o', 'x', 'X', 'S'};
    int i;
    int (*func)(va_list);

    for (i = 0; i < sizeof(format_specifiers) / sizeof(format_specifiers[0]); i++)
    {
        func = get_print_func(format_specifiers[i]);
        if (func)
            printf("Format specifier '%c' maps to a function\n", format_specifiers[i]);
        else
            printf("Format specifier '%c' is unsupported\n", format_specifiers[i]);
    }

    return (0);
}
