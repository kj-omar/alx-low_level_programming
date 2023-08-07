#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    FILE *from = fopen(argv[1], "r");
    if (!from)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    FILE *to = fopen(argv[2], "w");
    if (!to)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        fclose(from);
        exit(99);
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead, bytesWritten;

    do {
        bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, from);
        bytesWritten = fwrite(buffer, sizeof(char), bytesRead, to);

        if (bytesRead != bytesWritten || ferror(from) || ferror(to))
        {
            dprintf(STDERR_FILENO, "Error: Failed to copy the file\n");
            fclose(from);
            fclose(to);
            exit(100);
        }

    } while (bytesRead > 0);

    fclose(from);
    fclose(to);

    return 0;
}
