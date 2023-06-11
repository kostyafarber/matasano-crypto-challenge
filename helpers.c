#include "helpers.h"

void
hex_to_bytes(char *string, int len, int *byte_array)
{
    for (int i = 0; i < len - 1; i += 2) {
        char *hex_str = malloc(3);
        strncpy(hex_str, string, 2);
        
        int int_hex = (int) strtol(hex_str, NULL, 16);
        byte_array[i] = int_hex;
        string += 2;
        printf("hex string is: %s, integer is: %d\n", hex_str, int_hex);
    }
}

void string_to_hex(char *input_str, char *output_buf) {
    int j = 0;
    while (*input_str) {
        sprintf(output_buf, "%0X", *input_str);
        output_buf += 2;
        input_str++;
    }
    output_buf[j] = '\0';
}