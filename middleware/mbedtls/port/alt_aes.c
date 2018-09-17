#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif

#if defined(MBEDTLS_AES_C)
#include "mbedtls/aes.h"

#if defined(MBEDTLS_AES_ALT)

void mbedtls_aes_init(mbedtls_aes_context *ctx) {
    if (ctx == NULL)
        return;
    memset(ctx, 0, sizeof (mbedtls_aes_context));
}

void mbedtls_aes_free(mbedtls_aes_context *ctx) {
    mbedtls_aes_init(ctx);
}

int mbedtls_aes_setkey_enc(mbedtls_aes_context *ctx, const unsigned char *key, unsigned int keybits) {
    switch (keybits) {
        case 128: ctx->keyLen = 16;
            break;
        case 192: ctx->keyLen = 24;
            break;
        case 256: ctx->keyLen = 32;
            break;
        default:
            return (MBEDTLS_ERR_AES_INVALID_KEY_LENGTH);
    }
    memcpy(ctx->key, key, ctx->keyLen);
    return 0;
}

int mbedtls_aes_setkey_dec(mbedtls_aes_context *ctx, const unsigned char *key, unsigned int keybits) {
    mbedtls_aes_setkey_enc(ctx, key, keybits);
    return 0;
}

int mbedtls_aes_crypt_ecb(mbedtls_aes_context *ctx,
        int mode,
        const unsigned char input[16],
        unsigned char output[16]) {
    int ret = 0;
    if (mode == MBEDTLS_AES_ENCRYPT) {
        ret = Pic32Crypto(input, 16, (uint32_t*) output, 16,
                PIC32_ENCRYPTION, PIC32_ALGO_AES, PIC32_CRYPTOALGO_RECB,
                ctx->key, ctx->keyLen, NULL, 0);         
    } else {
        ret = Pic32Crypto(input, 16, (uint32_t*) output, 16,
                PIC32_DECRYPTION, PIC32_ALGO_AES, PIC32_CRYPTOALGO_RECB,
                ctx->key, ctx->keyLen, NULL, 0);         
    }
    return ret;
}

int mbedtls_aes_crypt_cbc(mbedtls_aes_context *ctx,
        int mode,
        size_t sz,
        unsigned char iv[16],
        const unsigned char *input,
        unsigned char *output) {
    if (sz % 16) 
        return MBEDTLS_ERR_AES_INVALID_INPUT_LENGTH;
    int ret;
    if (mode == MBEDTLS_AES_ENCRYPT) {
        ret = Pic32Crypto(input, sz, (uint32_t*) output, sz,
                PIC32_ENCRYPTION, PIC32_ALGO_AES, PIC32_CRYPTOALGO_RCBC,
                ctx->key, ctx->keyLen, (uint32_t *) iv, 16);         
        if (0 == ret)
            memcpy(iv, output + sz - 16, 16);
    } else {
        //LOG("[AES] de-cbc\n");
        memcpy(ctx->tmp, input + sz - 16, 16);
        ret = Pic32Crypto(input, sz, (uint32_t*) output, sz,
                PIC32_DECRYPTION, PIC32_ALGO_AES, PIC32_CRYPTOALGO_RCBC,
                ctx->key, ctx->keyLen, (uint32_t *) iv, 16);          
        if (0 == ret) 
            memcpy(iv, ctx->tmp, 16);
    }
    return ret;
}

#endif /*MBEDTLS_AES_ALT*/
#endif /*MBEDTLS_AES_C*/


