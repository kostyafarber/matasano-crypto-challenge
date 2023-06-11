#include "helpers.h"

const char *file_name = "ice-ice-baby.txt";
const char *key = "ICE";

char *
read_file(const char * file_name);

int
main()
{
    char *line = read_file(file_name);
    char encrypted[1000];
    char encrypted_hex_encoded[1000];

    printf("Line is: %s\n", line);
    printf("Key is: %s\n", key);

    for (size_t i = 0; i < strlen(line); i++) {
        char c = key[i % 3];
        int e = line[i] ^ c;
        encrypted[i] = e;
    }

    for (size_t i = 0; i < strlen(encrypted); i++) {
        printf("%0x", encrypted[i]);
    }
    printf("\n");
}

char *
read_file(const char * file_name)
{
    FILE *fptr;
    fptr = fopen("ice-ice-baby.txt", "r");
    static char line[1000];
    fgets(line, 1000, fptr);
    return line;
}