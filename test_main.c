#include "main.h"

int main(void)
{
    int len;
    len = _printf("Let's try to printf a simple sentence.\n");
    _printf("Length:[%d]\n", len);
    len = _printf("Character:[%c]\n", 'H');
    _printf("Length:[%d]\n", len);
    len = _printf("Integer:[%d]\n", 12345);
    _printf("Length:[%d]\n", len);
    len = _printf("Binary:[%b]\n", 98);
    _printf("Length:[%d]\n", len);
    len = _printf("Unsigned:[%u]\n", 4294967295U);
    _printf("Length:[%d]\n", len);
    len = _printf("Octal:[%o]\n", 12345);
    _printf("Length:[%d]\n", len);
    len = _printf("Hex:[%x]\n", 255);
    _printf("Length:[%d]\n", len);
    len = _printf("Uppercase Hex:[%X]\n", 255);
    _printf("Length:[%d]\n", len);
    len = _printf("String with non-printable:[%S]\n", "Hello, \x01World!");
    _printf("Length:[%d]\n", len);
    return (0);
}
