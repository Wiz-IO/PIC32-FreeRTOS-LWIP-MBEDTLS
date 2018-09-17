#include "mbedtls/config.h"

#if defined(MBEDTLS_MD5_C)
#include "mbedtls/md5_alt.h"

#ifdef MBEDTLS_MD5_ALT

#undef CRYPTO_CONTEXT
#undef CRYPTO_DBG 
#undef CRYPTO_MTD 
#undef CRYPTO_ALG 
#undef DIGEST_SIZE 
#undef EMPTY_STR

#define CRYPTO_CONTEXT  mbedtls_md5_context
#define CRYPTO_DBG      
#define CRYPTO_MTD      PIC32_ENCRYPTION 
#define CRYPTO_ALG      PIC32_ALGO_MD5
#define DIGEST_SIZE     16
#define EMPTY_STR       "\xd4\x1d\x8c\xd9\x8f\x00\xb2\x04\xe9\x80\x09\x98\xec\xf8\x42\x7e"

static void mbedtls_md5_reset(CRYPTO_CONTEXT * ctx) {
    if (ctx) {
        if (ctx->cache.data) {
            free(ctx->cache.data);
            ctx->cache.data = NULL;
            ctx->cache.size = 0;
            //CRYPTO_DBG("[MD5] R: %X\n", ctx);
        }
        memset(ctx, 0, sizeof (CRYPTO_CONTEXT));
    }
}

void mbedtls_md5_init(CRYPTO_CONTEXT * ctx) {
    CRYPTO_DBG("[MD5] +: %X\n", ctx);
    memset(ctx, 0, sizeof (CRYPTO_CONTEXT));
}

void mbedtls_md5_starts(CRYPTO_CONTEXT * ctx) {
    CRYPTO_DBG("[MD5] S: %X\n", ctx);
    memset(ctx, 0, sizeof (CRYPTO_CONTEXT));
}

void mbedtls_md5_free(CRYPTO_CONTEXT * ctx) {
    CRYPTO_DBG("[MD5] -: %X\n", ctx);
    mbedtls_md5_reset(ctx);
}

void mbedtls_md5_clone(CRYPTO_CONTEXT * dst, const CRYPTO_CONTEXT * src) {
    CRYPTO_DBG("[MD5] C: %X <<< %X\n", dst, src);
    //memcpy(dst, src, sizeof (CRYPTO_CONTEXT));
    dst->cache.data = (uint8_t*) pvPortMalloc(src->cache.size);
    if (dst->cache.data) {
        if (src->cache.data && src->cache.size)
            memcpy(dst->cache.data, src->cache.data, src->cache.size);
        dst->cache.size = src->cache.size;
    } else {
        dst->cache.size = -1; // mark error
        CRYPTO_DBG("[ERROR] MD5 CLONE\n");
    }
}

void mbedtls_md5_update(CRYPTO_CONTEXT * ctx, const unsigned char * input, size_t ilen) {
    CRYPTO_DBG("[MD5] U: %X\n", ctx);
    if (0 == ilen || ctx->cache.size >= PIC32_MAX_MEMORY_LIMIT) return;
    cacheUpdate(&ctx->cache, input, ilen);
    if (ctx->cache.size >= PIC32_MAX_MEMORY_LIMIT) {
        CRYPTO_DBG("[ERROR] MD5 LIMIT\n");
    }
}

void mbedtls_md5_finish(CRYPTO_CONTEXT * ctx, unsigned char output[16]) {
    CRYPTO_DBG("[MD5] F: %X\n", ctx);
    if (NULL == ctx->cache.data ||
            ctx->cache.size >= PIC32_MAX_MEMORY_LIMIT ||
            Pic32Crypto((const uint8_t *) ctx->cache.data, ctx->cache.size,
            (uint32_t*) output, DIGEST_SIZE, CRYPTO_MTD, CRYPTO_ALG, 0, NULL, 0, NULL, 0))
        memcpy(output, EMPTY_STR, DIGEST_SIZE);
    mbedtls_md5_reset(ctx);
    //PrintHex("[MD5] ", (char*) output, DIGEST_SIZE, "\n");
}

void mbedtls_md5_process(CRYPTO_CONTEXT * ctx, const unsigned char data[64]) {
    CRYPTO_DBG("[MD5] P: %X\n", ctx);
    //mbedtls_md5_init(ctx);
    //mbedtls_md5_update(ctx, data, 64);
    //mbedtls_md5_finish(ctx, ctx->buf);
    //mbedtls_md5_free(ctx);
    (void) data;
}

#undef CRYPTO_CONTEXT
#undef CRYPTO_DBG 
#undef CRYPTO_MTD 
#undef CRYPTO_ALG 
#undef DIGEST_SIZE 
#undef EMPTY_STR

#endif /* MBEDTLS_MD5_ALT */
#endif /* MBEDTLS_MD5_C */