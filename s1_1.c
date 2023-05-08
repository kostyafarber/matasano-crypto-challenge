/*
* Base64 encoder. Takes a hex string as input and returns 
* the base64 encoded string.
*
* Example:
*    decoded = 49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d 
*    encoded = SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t
*  
* 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 6
char hex_buf[BUF_SIZE];
char base64_table[] = {
    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
    'Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f',
    'g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v',
    'w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/'
};

int
main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s' str\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // TODO: Add cases when last block contains 1 or 2 characters
    char *hex_string = argv[1];
    char base_64_encoded[strlen(hex_string)];

    int sextet = 0b111111;
    int i = 0;
    while (i < strlen(hex_string)) {
        memcpy(hex_buf, &hex_string[i], 6);
        int int_hex = (int) strtol(hex_buf, NULL, 16);
        for (int j = 18; j >= 0; j -= 6) {
            int group = int_hex;
            group &= ((sextet << j) | 0);
            group >>= j;
            strncat(&base_64_encoded[0], &base64_table[group], 1);
        }
        memset(hex_buf, 0, 6);
        i += 6;
    }

    printf("Decoded: %s\n", hex_string);
    printf("Encoded: %s\n", base_64_encoded);
}