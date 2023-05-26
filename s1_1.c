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

#include "string_to_hex.h"

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
        fprintf(stderr, "usage: %s str\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // TODO: Add cases when last block contains 1 or 2 characters
    char *string = argv[1];
    size_t str_len = strlen(argv[1]);
    char hex_string[(str_len * 2) + 1];
    string_to_hex(string, hex_string);
    char str_hex_len = strlen(hex_string);
    char base_64_encoded[str_hex_len];
    memset(base_64_encoded, 0, str_hex_len);

    int sextet = 0x3f;
    int i = 0;
    while (i < str_hex_len - 6) {
        memcpy(hex_buf, &hex_string[i], 6);
        // hex_buf[i + 6] = '\0';
        printf("Current 6 chars is: %s\n", hex_buf);
        int int_hex = (int) strtol(hex_buf, NULL, 16);
        for (int j = 18; j >= 0; j -= 6) {
            int group = int_hex;
            group &= ((sextet << j) | 0);
            group >>= j;
            printf("index number is: %d\n", group);
            strncat(base_64_encoded, &base64_table[group], 1);
        }
        printf("current enocding is: %s\n", base_64_encoded);
        memset(hex_buf, 0, 6);
        i += 6;
    }

    printf("string length: %d, i: %d, last n chars: %s\n", str_hex_len, i, &hex_string[i]);
    const char pad[] = "=";
    if ((i + 6) == str_hex_len) {  
        memcpy(hex_buf, &hex_string[i], 6);
        int int_hex = (int) strtol(hex_buf, NULL, 16);
        for (int j = 18; j >= 0; j -= 6) {
            int group = int_hex;
            group &= ((sextet << j) | 0);
            group >>= j;
            strncat(base_64_encoded, &base64_table[group], 1);
        }
    } else if ((i + 2) == str_hex_len) {
        memcpy(hex_buf, &hex_string[i], 2);
        int int_hex = (int) strtol(hex_buf, NULL, 16);
        int group = int_hex;
        group &= ((sextet) << 2 | 0);
        group >>= 2;
        strncat(&base_64_encoded[0], &base64_table[group], 1);
        
        group = int_hex;
        group &= (0b11 | 0);
        group <<= 4;
        strncat(&base_64_encoded[0], &base64_table[group], 1);  
        strncat(&base_64_encoded[0], pad, 1);
        strncat(&base_64_encoded[0], pad, 1);
    } else if ((i + 4) == str_hex_len) {
        memcpy(hex_buf, &hex_string[i], 4);
        printf("Current 4 chars is: %s\n", hex_buf);
        int int_hex = (int) strtol(hex_buf, NULL, 16);
        for (int j = 12; j >= 0; j -= 6) {
            int group = int_hex;
            group &= ((sextet << j) | 0);
            group >>= j;
            printf("index number is: %d\n", group);
            strncat(base_64_encoded, &base64_table[group], 1);
        } 
        int group = int_hex;
        group &= (0xF | 0);
        group <<= 2;
        strncat(base_64_encoded, &base64_table[group], 1);
        // group = int_hex;
        // group &= (0b11 | 0);
        // group <<= 4;
        strncat(base_64_encoded, pad, 1);
    }   
    printf("Original string: %s\n", string);
    printf("Decoded: %s\n", hex_string);
    printf("Encoded: %s\n", &base_64_encoded[0]);
}