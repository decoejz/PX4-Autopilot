#ifdef __cplusplus
extern "C"
{
#endif

#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <stdio.h>

#define PRIVATE_KEY 0
#define PUBLIC_KEY 1
#define SIGMA_LEN 256

    // ! Define unique interface
    EVP_PKEY *read_key(char key_type, const char *file_name);
    int verify(unsigned char *sigma, int sigma_len, uint8_t *message, unsigned int msglen, EVP_PKEY *public_key);
    int key_gen(const char *secret_name, const char *public_name);
    int sign(unsigned char *sigma, unsigned int *sigma_len, uint8_t *message, unsigned int msglen, EVP_PKEY *secret_key);

#ifdef __cplusplus
}
#endif
