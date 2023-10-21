#include <stdio.h>
#include <stdlib.h>

/**
 * write_data_to_file - Write data to a file using a buffer to minimize write calls
 * @filename: The name of the file to write to
 */
void write_data_to_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to open the file");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];  /* Initialize a 1024-character buffer */
    size_t buffer_size = 0;

    for (int i = 1; i <= 1000; i++) {
        int data_written = snprintf(buffer + buffer_size, sizeof(buffer) - buffer_size, "Data %d\n", i);

        if (data_written < 0) {
            perror("Failed to format data");
            exit(EXIT_FAILURE);
        }

        buffer_size += (size_t)data_written;

        /* Check if the buffer is full (1024 characters) */
        if (buffer_size >= sizeof(buffer)) {
            if (fwrite(buffer, 1, buffer_size, file) != buffer_size) {
                perror("Failed to write data to the file");
                exit(EXIT_FAILURE);
            }

            buffer_size = 0;  /* Reset the buffer */
        }
    }

    /* Write any remaining data in the buffer */
    if (buffer_size > 0) {
        if (fwrite(buffer, 1, buffer_size, file) != buffer_size) {
            perror("Failed to write data to the file");
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
}

/**
 * main - Entry point of the program
 * Return: 0 on success, 1 on failure
 */
int main(void) {
    const char *filename = "output.txt";
    write_data_to_file(filename);

    return 0;
}

