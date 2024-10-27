// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     FILE *fp = fopen("hex.txt", "rb");
//     char ch;
//     char hex[3];
//     if (fp == NULL)
//     {
//         printf("Error opening the file!\n");
//     }
//     while (1)
//     {
//         for (int i = 0; i < 2; i++)
//         {
//             ch = fgetc(fp);
//             while (ch == ' ' || ch == '\n' || ch == '\r')
//             {
//                 ch = fgetc(fp);
//             }
//             hex[i] = ch;
//         }

//     }
//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hex digit to its decimal value
int hex_to_decimal(char hex_char) {
    if (hex_char >= '0' && hex_char <= '9') {
        return hex_char - '0';
    } else if (hex_char >= 'A' && hex_char <= 'F') {
        return hex_char - 'A' + 10;
    } else if (hex_char >= 'a' && hex_char <= 'f') {
        return hex_char - 'a' + 10;
    } else {
        printf("Invalid hex digit: %c\n", hex_char);
        return -1;
    }
}

// Function to convert a hex string to its binary equivalent and write it to a file
void hex_to_bin_file(const char *hex_file, const char *bin_file) {
    FILE *hex_fp = fopen(hex_file, "r");
    FILE *bin_fp = fopen(bin_file, "wb");

    if (hex_fp == NULL || bin_fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char hex_buffer[3];  // Buffer to hold 2 hex digits (plus null terminator)
    unsigned char byte_value;

    // Read two hex digits at a time from the hex file
    while (fscanf(hex_fp, "%2s", hex_buffer) == 1) {
        
        // Convert each hex pair to its binary equivalent (1 byte)
        byte_value = (hex_to_decimal(hex_buffer[0]) << 4) | hex_to_decimal(hex_buffer[1]);

        // Write the binary byte to the .bin file
        fwrite(&byte_value, sizeof(unsigned char), 1, bin_fp);
    }

    printf("Hex data successfully converted to binary and written to %s\n", bin_file);

    // Close both files
    fclose(hex_fp);
    fclose(bin_fp);
}

int main() {
    const char *input_hex_file = "hex2.txt";  // Replace with your hex file path
    const char *output_bin_file = "output2.bin";  // Replace with desired output file

    hex_to_bin_file(input_hex_file, output_bin_file);

    return 0;
}
