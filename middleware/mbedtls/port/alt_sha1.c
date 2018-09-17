#include "mbedtls/config.h"

#if defined(MBEDTLS_SHA1_C)
#include "mbedtls/sha1_alt.h"

#if defined(MBEDTLS_SHA1_ALT)

#undef CRYPTO_CONTEXT
#undef CRYPTO_DBG 
#undef CRYPTO_MTD 
#undef CRYPTO_ALG 
#undef DIGEST_SIZE 
#undef EMPTY_STR

#define CRYPTO_CONTEXT  mbedtls_sha1_context
#define CRYPTO_DBG      
#define CRYPTO_MTD      PIC32_ENCRYPTION 
#define CRYPTO_ALG      PIC32_ALGO_SHA1
#define DIGEST_SIZE     20
#define EMPTY_STR       "\xda\x39\xa3\xee\x5e\x6b\x4b\x0d\x32\x55\xbf\xef\x95\x60\x18\x90\xaf\xd8\x07\x09"

static void mbedtls_sha1_reset(CRYPTO_CONTEXT * ctx) {
    if (ctx) {
        if (ctx->cache.data) {
            free(ctx->cache.data);
            ctx->cache.data = NULL;
            ctx->cache.size = 0;
            //CRYPTO_DBG("[SHA] R: %X\n", ctx);
        }
        memset(ctx, 0, sizeof (CRYPTO_CONTEXT));
    }
}

void mbedtls_sha1_init(CRYPTO_CONTEXT * ctx) {
    CRYPTO_DBG("[SHA] +: %X\n", ctx);
    memset(ctx, 0, sizeof (CRYPTO_CONTEXT));
}

void mbedtls_sha1_starts(CRYPTO_CONTEXT *ctx) {
    CRYPTO_DBG("[SHA] S: %X\n", ctx);
    memset(ctx, 0, sizeof (CRYPTO_CONTEXT));
}

void mbedtls_sha1_free(CRYPTO_CONTEXT * ctx) {
    CRYPTO_DBG("[SHA] -: %X\n", ctx);
    mbedtls_sha1_reset(ctx);
}

void mbedtls_sha1_clone(CRYPTO_CONTEXT *dst, const CRYPTO_CONTEXT *src) {
    CRYPTO_DBG("[SHA] C: %X <<< %X\n", dst, src);
    //memcpy(dst, src, sizeof (CRYPTO_CONTEXT));
    dst->cache.data = (uint8_t*) pvPortMalloc(src->cache.size);
    if (dst->cache.data) {
        if (src->cache.data && src->cache.size)
            memcpy(dst->cache.data, src->cache.data, src->cache.size);
        dst->cache.size = src->cache.size;
    } else {
        dst->cache.size = -1; // mark error
        CRYPTO_DBG("[ERROR] SHA CLONE\n");
    }
}

void mbedtls_sha1_update(CRYPTO_CONTEXT *ctx, const unsigned char *input, size_t ilen) {
    CRYPTO_DBG("[SHA] U: %X\n", ctx);
    if (0 == ilen || ctx->cache.size >= PIC32_MAX_MEMORY_LIMIT) return;
    cacheUpdate(&ctx->cache, input, ilen);
    if (ctx->cache.size >= PIC32_MAX_MEMORY_LIMIT) {
        CRYPTO_DBG("[ERROR] SHA LIMIT\n");
    }
}

void mbedtls_sha1_finish(CRYPTO_CONTEXT *ctx, unsigned char output[20]) {
    CRYPTO_DBG("[SHA] F: %X\n", ctx);
    if (NULL == ctx->cache.data ||
            ctx->cache.size >= PIC32_MAX_MEMORY_LIMIT ||
            Pic32Crypto((const uint8_t *) ctx->cache.data, ctx->cache.size,
            (uint32_t*) output, DIGEST_SIZE, CRYPTO_MTD, CRYPTO_ALG, 0, NULL, 0, NULL, 0))
        memcpy(output, EMPTY_STR, DIGEST_SIZE);
    mbedtls_sha1_reset(ctx);
    //PrintHex("[SHA] ", (char*) output, DIGEST_SIZE, "\n");
}

void mbedtls_sha1_process(CRYPTO_CONTEXT *ctx, const unsigned char data[64]) {
    CRYPTO_DBG("[SHA] P: %X\n", ctx);
    //mbedtls_sha1_init(ctx);
    //mbedtls_sha1_update(ctx, data, 64);
    //mbedtls_sha1_finish(ctx, ctx->buf);
    //mbedtls_sha1_free(ctx);
    (void) data;
}

#undef CRYPTO_CONTEXT
#undef CRYPTO_DBG 
#undef CRYPTO_MTD 
#undef CRYPTO_ALG 
#undef DIGEST_SIZE 
#undef EMPTY_STR

#endif /*MBEDTLS_SHA1_ALT*/
#endif /*MBEDTLS_SHA1_C*/