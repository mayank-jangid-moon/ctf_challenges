#include <stdio.h>

int main()
{
    FILE *file;
    unsigned char byte;

    // Open the file in binary mode
    file = fopen("file2", "rb");

    if (file == NULL)
    {
        printf("Error: Could not open file.\n");
        return 1;
    }
    int i = 0;
    // Read each byte and print its hexadecimal value
    while (fread(&byte, sizeof(byte), 1, file) == 1)
    {
        printf("'0x%02x' ", byte);
        i++;
        if (i % 8 == 0)
        {
            printf("\n");
        }
    }

    // Close the file
    fclose(file);

    return 0;
}
