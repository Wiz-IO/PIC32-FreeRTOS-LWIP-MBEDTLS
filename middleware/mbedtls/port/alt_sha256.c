#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif

#if defined(MBEDTLS_SHA1_C)
#include "mbedtls/sha256.h"

#if defined(MBEDTLS_SHA1_ALT)
#include "pic32mz-crypt.h"

////////////////////////////////////////////////////////////////////////////////

int wc_InitSha224_ex(Sha224 * sha224, void * heap, int devId) {
    (void) heap;
    (void) devId;
    if (sha224 == NULL)
        return BAD_FUNC_ARG;
    return wc_InitSha224(sha224);
}

int wc_Sha224Update(Sha224 * sha224, const byte* data, word32 len) {
    if (sha224 == NULL || (data == NULL && len > 0))
        return BAD_FUNC_ARG;
    return wc_Sha256Update((Sha256*) sha224, data, len);
}

int wc_Sha224Final(Sha224 * sha224, byte* hash) {
    int ret;
    if (sha224 == NULL || hash == NULL)
        return BAD_FUNC_ARG;
    ret = wc_Pic32HashFinal(&sha224->cache, (byte*) sha224->buffer, sha224->digest, hash, SHA224_DIGEST_SIZE, PIC32_ALGO_SHA256, NULL);
    if (ret != 0)
        return ret;
    XMEMCPY(hash, sha224->digest, WC_SHA224_DIGEST_SIZE);
    return wc_InitSha224(sha224); /* reset state */
}
////////////////////////////////////////////////////////////////////////////////


void mbedtls_sha256_init(mbedtls_sha256_context *ctx) {
    memset(ctx, 0, sizeof (mbedtls_sha256_context));
}

void mbedtls_sha256_free(mbedtls_sha256_context *ctx) {
    if (ctx == NULL)
        return;
    memset(ctx, 0, sizeof (mbedtls_sha256_context));
}

void mbedtls_sha256_clone(mbedtls_sha256_context *dst, const mbedtls_sha256_context *src) {
    *dst = *src;
}

void mbedtls_sha256_starts(mbedtls_sha256_context *ctx, int is224) {
    mbedtls_sha256_init(ctx);
    if (is224 == 1) {
        wc_InitSha224_ex((Sha224*)ctx, NULL, 0);
    } else {
        wc_InitSha256_ex(ctx, NULL, 0);
    }
}

void mbedtls_sha256_update(mbedtls_sha256_context *ctx, const unsigned char *input, size_t ilen) {
    wc_Sha256Update(ctx, (const byte*) input, (word32) ilen);
}

void mbedtls_sha256_finish(mbedtls_sha256_context *ctx, unsigned char output[32]) {
    wc_Sha256Final(ctx, (byte*) output);
}

void mbedtls_sha256_process(mbedtls_sha256_context *ctx, const unsigned char data[64]) {
    unsigned char output[65] = {0};
    mbedtls_sha256_starts(ctx, 0);
    mbedtls_sha256_update(ctx, data, 64);
    mbedtls_sha256_finish(ctx, output);
}


#endif /*MBEDTLS_SHA256_ALT*/
#endif /*MBEDTLS_SHA256_C*/
