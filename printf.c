#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function with limited format specifiers
 * @format: The format string containing format specifiers
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    char buffer[1024];
    int charCount = 0;
    int bufferIndex = 0;

    while (*format != '\0') {
        if (*format == '%') {
            format++; /* Move past the '%' */
            if (*format == '\0') {
                break;
            }
            if (*format == 'c') {
                char c = va_arg(args, int);
                buffer[bufferIndex++] = c;
                charCount++;
            } else if (*format == 's') {
                char *str = va_arg(args, char *);
                while (*str != '\0') {
                    buffer[bufferIndex++] = *str;
                    str++;
                    charCount++;
                }
            } else if (*format == 'd' || *format == 'i') {
                int num = va_arg(args, int);
                int len = snprintf(buffer + bufferIndex, sizeof(buffer) - bufferIndex, "%d", num);
                if (len > 0) {
                    bufferIndex += len;
                    charCount += len;
                }
            } else if (*format == 'b') {
                unsigned int num = va_arg(args, unsigned int);
                char binary[33];
                for (int i = 31; i >= 0; i--) {
                    binary[i] = (num & 1) ? '1' : '0';
                    num >>= 1;
                }
                binary[32] = '\0';
                for (int i = 0; i < 32; i++) {
                    buffer[bufferIndex++] = binary[i];
                    charCount++;
                }
            } else if (*format == 'u') {
                unsigned int num = va_arg(args, unsigned int);
                int len = snprintf(buffer + bufferIndex, sizeof(buffer) - bufferIndex, "%u", num);
                if (len > 0) {
                    bufferIndex += len;
                    charCount += len;
                }
            } else if (*format == 'o') {
                unsigned int num = va_arg(args, unsigned int);
                int len = snprintf(buffer + bufferIndex, sizeof(buffer) - bufferIndex, "%o", num);
                if (len > 0) {
                    bufferIndex += len;
                    charCount += len;
                }
            } else if (*format == 'x' || *format == 'X') {
                unsigned int num = va_arg(args, unsigned int);
                int len = snprintf(buffer + bufferIndex, sizeof(buffer) - bufferIndex, (*format == 'x') ? "%x" : "%X", num);
                if (len > 0) {
                    bufferIndex += len;
                    charCount += len;
                }
            } else if (*format == '%') {
                buffer[bufferIndex++] = '%';
                charCount++;
            }
        } else {
            buffer[bufferIndex++] = *format;
            charCount++;
        }

        if (bufferIndex >= 1024 - 1) {
            write(1, buffer, bufferIndex);
            bufferIndex = 0;
        }

        format++; /* Move to the next character in the format string */
    }

    if (bufferIndex > 0) {
        write(1, buffer, bufferIndex);
    }

    va_end(args);

    return charCount;
}

int main() {
    unsigned int num = 42;
    int count = _printf("Unsigned: %u\nOctal: %o\nLowercase Hex: %x\nUppercase Hex: %X\n", num, num, num, num);
    printf("\nTotal characters printed: %d\n", count);

    return 0;
}
