#include "rsa.h"

// Documentation:
// https://docs.openssl.org/3.0/man3/EVP_PKEY_verify/#notes

// RES:
// 0 => Invalid Signature
// 1 => Signature Correct
// else => Error
int verify(unsigned char *sigma, int sigma_len, uint8_t *message, unsigned int msglen, EVP_PKEY *public_key)
{
    if (public_key == NULL)
    {
        fprintf(stderr, "Validation ERROR - key is NULL\n");
        return -1;
    }

    EVP_PKEY_CTX *ctx = EVP_PKEY_CTX_new(public_key, NULL);
    if (!ctx)
    {
        fprintf(stderr, "Validation ERROR - Failed to create EVP_PKEY_CTX\n");
        ERR_print_errors_fp(stderr);
        return -1;
    }

    if (EVP_PKEY_verify_init(ctx) <= 0)
    {
        fprintf(stderr, "Validation ERROR - Failed to initialize EVP_PKEY_CTX\n");
        EVP_PKEY_CTX_free(ctx);
        return -1;
    }

    int res = EVP_PKEY_verify(ctx, sigma, sigma_len, message, msglen);
    if (res != 0 && res != 1)
    {
        fprintf(stderr, "Validation ERROR - code %d\n", res);
    }

    EVP_PKEY_CTX_free(ctx);
    return res;
}
