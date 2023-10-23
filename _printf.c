#include <stdio.h>

/**
* print_binary - Prints the binary representation of an unsigned integer.
* @n: The unsigned integer to convert and print.
*/
void print_binary(unsigned int n)
{
if (n > 1)
{
print_binary(n / 2);
}
putchar('0' + n % 2);
}
/**
* main - Entry point of the program.
*
* Return: 0 (Success).
*/
int main(void)
{
unsigned int value = 42;
printf("Binary representation: ");
print_binary(value);
printf("\n");
return (0);
}
