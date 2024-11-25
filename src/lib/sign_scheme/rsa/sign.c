#include "rsa.h"

#define SIGN_MAX_LEN 2048

// To compile:
// gcc sign_rsa.c -o sign_rsa -lcrypto

// Res:
// 0 => ERROR
// 1 => Success
int sign(unsigned char *sigma, unsigned int *sigma_len, uint8_t *message, unsigned int msglen, EVP_PKEY *secret_key)
{
    // Create a context
    EVP_PKEY_CTX *ctx = EVP_PKEY_CTX_new(secret_key, NULL);

    // Initialize signing
    EVP_PKEY_sign_init(ctx);
    size_t siglen = SIGN_MAX_LEN;
    if (!EVP_PKEY_sign(ctx, sigma, &siglen, message, (size_t)msglen))
    {
        return 0;
    }
    *sigma_len = siglen;
    EVP_PKEY_CTX_free(ctx);

    return 1;
}