#include <stdio.h>

void remove_newlines(const char *input_file, const char *output_file) {
    FILE *in_fp = fopen(input_file, "r");
    FILE *out_fp = fopen(output_file, "w");

    if (in_fp == NULL || out_fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char ch;

    // Read each character from the input file
    while ((ch = fgetc(in_fp)) != EOF) {
        // If the character is not a newline, write it to the output file
        if (ch != '\n') {
            fputc(ch, out_fp);
        }
    }

    printf("Newlines removed and written to %s\n", output_file);

    // Close both files
    fclose(in_fp);
    fclose(out_fp);
}

int main() {
    const char *input_code_file = "file2.txt";  // Replace with your code file path
    const char *output_code_file = "hex2.txt";  // Replace with your desired output file

    remove_newlines(input_code_file, output_code_file);

    return 0;
}
