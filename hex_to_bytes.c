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

// int
// main(int argc, char **argv)
// {
//     if (argc != 2) {
//         fprintf(stderr, "usage: %s str\n", argv[0]);
//         exit(EXIT_FAILURE);
//     }

//     char *string = argv[1];
//     size_t len = strlen(string);
//     int byte_array[len];

//     hex_to_bytes(string, len, byte_array);
//     // printf("%s\n", string);
//     // printf("%d\n", len);
// }