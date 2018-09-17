
#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif

#if defined(MBEDTLS_DES_C)
#include "mbedtls/des.h"

#if defined(MBEDTLS_DES_ALT)

void mbedtls_des_init(mbedtls_des_context *ctx) {
    if (ctx == NULL)
        return;
    memset(ctx, 0, sizeof (mbedtls_des_context));
}

void mbedtls_des_free(mbedtls_des_context *ctx) {
    mbedtls_des_init(ctx);
}

void mbedtls_des3_init(mbedtls_des3_context *ctx) {
    mbedtls_des_init((mbedtls_des3_context*) ctx);
}

void mbedtls_des3_free(mbedtls_des3_context *ctx) {
    mbedtls_des_free((mbedtls_des3_context*) ctx);
}

int mbedtls_des_setkey_enc(mbedtls_des_context *ctx, const unsigned char key[MBEDTLS_DES_KEY_SIZE]) {
    ctx->keyLen = MBEDTLS_DES_KEY_SIZE;
    memcpy(ctx->key, key, ctx->keyLen);
    ctx->mode = MBEDTLS_DES_ENCRYPT;
    return 0;
}

int mbedtls_des_setkey_dec(mbedtls_des_context *ctx, const unsigned char key[MBEDTLS_DES_KEY_SIZE]) {
    ctx->keyLen = MBEDTLS_DES_KEY_SIZE;
    memcpy(ctx->key, key, ctx->keyLen);
    ctx->mode = MBEDTLS_DES_DECRYPT;
    return 0;
}

int mbedtls_des3_set2key_enc(mbedtls_des3_context *ctx, const unsigned char key[MBEDTLS_DES_KEY_SIZE * 2]) {
    ctx->keyLen = MBEDTLS_DES_KEY_SIZE * 2;
    //memcpy(ctx->key, key, ctx->keyLen);
    //ctx->mode = MBEDTLS_DES_ENCRYPT;
    return -1; /* 2DES is not support */
}

int mbedtls_des3_set2key_dec(mbedtls_des3_context *ctx, const unsigned char key[MBEDTLS_DES_KEY_SIZE * 2]) {
    ctx->keyLen = MBEDTLS_DES_KEY_SIZE * 2;
    //memcpy(ctx->key, key, ctx->keyLen);
    //ctx->mode = MBEDTLS_DES_DECRYPT;
    return -1; /* 2DES is not support */
}

int mbedtls_des3_set3key_enc(mbedtls_des3_context *ctx, const unsigned char key[MBEDTLS_DES_KEY_SIZE * 3]) {
    ctx->keyLen = MBEDTLS_DES_KEY_SIZE * 3;
    memcpy(ctx->key, key, ctx->keyLen);
    ctx->mode = MBEDTLS_DES_ENCRYPT;
    return 0;
}

int mbedtls_des3_set3key_dec(mbedtls_des3_context *ctx, const unsigned char key[MBEDTLS_DES_KEY_SIZE * 3]) {
    ctx->keyLen = MBEDTLS_DES_KEY_SIZE * 3;
    memcpy(ctx->key, key, ctx->keyLen);
    ctx->mode = MBEDTLS_DES_DECRYPT;
    return 0;
}

int mbedtls_des_crypt_ecb(mbedtls_des_context *ctx,
        const unsigned char input[8],
        unsigned char output[8]) {
    int ret;
    if (ctx->mode == MBEDTLS_DES_ENCRYPT)
        ret = Pic32Crypto(input, 8, (uint32_t*) output, 8,
                PIC32_ENCRYPTION, PIC32_ALGO_DES, PIC32_CRYPTOALGO_ECB,
                ctx->key, ctx->keyLen, NULL, 0); 
    else
        ret = Pic32Crypto(input, 8, (uint32_t*) output, 8,
                PIC32_DECRYPTION, PIC32_ALGO_DES, PIC32_CRYPTOALGO_ECB,
                ctx->key, ctx->keyLen, NULL, 0);      
    return ret;
}

int mbedtls_des_crypt_cbc(mbedtls_des_context * ctx,
        int mode,
        size_t sz,
        unsigned char iv[8],
        const unsigned char * input,
        unsigned char * output) {
    int ret;
    if (sz % 8)
        return ( MBEDTLS_ERR_DES_INVALID_INPUT_LENGTH);
    if (mode == MBEDTLS_DES_ENCRYPT) {
        ret = Pic32Crypto(input, sz, (uint32_t*) output, sz,
                PIC32_ENCRYPTION, PIC32_ALGO_DES, PIC32_CRYPTOALGO_CBC,
                ctx->key, ctx->keyLen, (uint32_t*) iv, 8);         
        if (0 == ret) 
            memcpy(iv, output + sz - 8, 8);
    } else {
        memcpy(ctx->tmp, input + sz - 8, 8);
        ret = Pic32Crypto(input, sz, (uint32_t*) output, sz,
                PIC32_DECRYPTION, PIC32_ALGO_DES, PIC32_CRYPTOALGO_CBC,
                ctx->key, ctx->keyLen, (uint32_t*) iv, 8);         
        if (0 == ret) 
            memcpy(iv, ctx->tmp, 8);
    }
    return ret;
}

int mbedtls_des3_crypt_ecb(mbedtls_des3_context *ctx,
        const unsigned char input[8],
        unsigned char output[8]) {
    if (ctx->keyLen == 16) 
        return -1; /* 2DES is not support */
    int ret;
    if (ctx->mode == MBEDTLS_DES_ENCRYPT)
        ret = Pic32Crypto(input, 8, (uint32_t*) output, 8,
                PIC32_ENCRYPTION, PIC32_ALGO_TDES, PIC32_CRYPTOALGO_TECB,
                ctx->key, ctx->keyLen, NULL, 0);      
    else
        ret = Pic32Crypto(input, 8, (uint32_t*) output, 8,
                PIC32_DECRYPTION, PIC32_ALGO_TDES, PIC32_CRYPTOALGO_TECB,
                ctx->key, ctx->keyLen, NULL, 0);    
    return ret;
}

int mbedtls_des3_crypt_cbc(mbedtls_des3_context *ctx,
        int mode,
        size_t sz,
        unsigned char iv[8],
        const unsigned char * input,
        unsigned char * output) {
    if (ctx->keyLen == 16) 
        return -1; /* 2DES is not support */
    int ret;
    if (sz % 8) 
        return ( MBEDTLS_ERR_DES_INVALID_INPUT_LENGTH);
    if (mode == MBEDTLS_DES_ENCRYPT) {
        ret = Pic32Crypto(input, sz, (uint32_t*) output, sz,
                PIC32_ENCRYPTION, PIC32_ALGO_TDES, PIC32_CRYPTOALGO_TCBC,
                ctx->key, ctx->keyLen, (uint32_t*)iv, 8);
        if (0 == ret)
            memcpy(iv, output + sz - 8, 8);
    } else {
        memcpy(ctx->tmp, input + sz - 8, 8);
        ret = Pic32Crypto(input, sz, (uint32_t*) output, sz,
                PIC32_DECRYPTION, PIC32_ALGO_TDES, PIC32_CRYPTOALGO_TCBC,
                ctx->key, ctx->keyLen, (uint32_t*)iv, 8);
        if (0 == ret)
            memcpy(iv, ctx->tmp, 8);
    }
    return ret;
}

#endif /*MBEDTLS_DES_ALT*/
#endif /*MBEDTLS_DES_C*/