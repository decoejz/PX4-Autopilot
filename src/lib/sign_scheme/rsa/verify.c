#include "rsa.h"

// To compile:
// gcc ver_rsa.c -o ver_rsa -lcrypto

// RES:
// 0 => Invalid Signature
// 1 => Signature Correct
// else => Error
int verify(unsigned char *sigma, int sigma_len, uint8_t *message, unsigned int msglen, EVP_PKEY *public_key)
{
    EVP_PKEY_CTX *ctx = EVP_PKEY_CTX_new(public_key, NULL);

    EVP_PKEY_verify_init(ctx);
    int res = EVP_PKEY_verify(ctx, sigma, sigma_len, message, msglen);

    EVP_PKEY_CTX_free(ctx);
    return res;
}