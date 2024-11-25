#include "rsa.h"

// key_type:
//   0 => secret key
//   1 => public key
EVP_PKEY *read_key(char key_type, const char *file_name)
{
    EVP_PKEY *key;
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        return NULL;
    }

    if (key_type == PRIVATE_KEY)
    {

        key = PEM_read_PrivateKey(fp, NULL, NULL, NULL);
    }
    else if (key_type == PUBLIC_KEY)
    {

        key = PEM_read_PUBKEY(fp, NULL, NULL, NULL);
    }
    else
    {
        return NULL;
    }

    fclose(fp);
    return key;
}