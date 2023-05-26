#include "string_to_hex.h"

void string_to_hex(char *input_str, char *output_buf) {
    int j = 0;
    while (*input_str) {
        sprintf(output_buf, "%0X", *input_str);
        output_buf += 2;
        input_str++;
    }
    output_buf[++j] = '\0';
}