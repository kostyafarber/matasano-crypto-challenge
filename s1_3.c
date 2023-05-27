#include "string_to_hex.h"
#include <ctype.h>

char *
create_hex_array(char *encrypted, int i)
{
    char *hex;
    hex = malloc(3);
    hex[0] = encrypted[i];
    hex[1] = encrypted[i + 1]; 
    hex[2] = '\0';

    return hex;
}

int
main(int argc, char **argv)
{
    char encrypted[] = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
    size_t len = strlen(encrypted);
    printf("%s\n", encrypted);
    /* Try all keys */
    for (int i = 0; i < 256; ++i) {
        int key = i;
        if (isascii(key)) {
            printf("Trying key %c\n", i);
            for (int j = 0; j < len; j += 2) {
                char *hex_str = create_hex_array(encrypted, j);
                int i_c = (int) strtol(hex_str, NULL, 16);
                char xor = key ^ i_c; /* single byte xor */
                if (isalpha(xor) || isspace(xor))
                    printf("%c", xor);
            }
            printf("\n\n");
        }
    }
}