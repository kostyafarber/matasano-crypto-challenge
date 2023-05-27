#include "string_to_hex.h"

struct key_pair {
    char *s;
    char *k;
};

struct key_pair
init_key_pair()
{
    struct key_pair kp;
    kp.s = NULL;
    kp.k = NULL;

    return kp;
    
} 

void free_key_pair(struct key_pair *kp)
{
    free(kp->s);
    free(kp->k);
}

void
create_key_pair_array(char *string, char *key, struct key_pair *kp)
{

    char *s = realloc(kp->s, 2);
    char *k = realloc(kp->k, 2);
    kp->s = s;
    kp->k = k;
    memcpy(kp->s, string, 1);
    memcpy(kp->k, key, 1);

    kp->s[1] = '\0';
    kp->k[1] = '\0';
}

int
main(int argc, char **argv)
{
      if (argc != 3) {
        fprintf(stderr, "usage: %s str key\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    
    struct key_pair kp = init_key_pair();
    char *string = argv[1];
    char *key = argv[2];
    size_t str_len = strlen(argv[1]);
    
    char cipher[str_len];
    printf("%s\n", string);
    printf("%s\n", key);

    for (int i = 0; i < str_len; i++) {

        create_key_pair_array(string, key, &kp);
      
        int s_i = (int) strtol(kp.s, NULL, 16);
        int k_i = (int) strtol(kp.k, NULL, 16);

        cipher[i] = s_i ^ k_i;
        string++;
        key++;
    }

    free_key_pair(&kp);
    for (int i = 0; i < str_len; i++) {
        printf("%0x", cipher[i]);
    }
    printf("\n");
}