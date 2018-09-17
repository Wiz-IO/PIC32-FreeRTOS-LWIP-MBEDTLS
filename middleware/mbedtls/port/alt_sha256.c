#include "mbedtls/config.h"

#if defined(MBEDTLS_SHA1_C)
#include "mbedtls/sha256_alt.h" 

#if defined(MBEDTLS_SHA256_ALT)

#undef CRYPTO_CONTEXT
#undef CRYPTO_DBG 
#undef CRYPTO_MTD 
#undef CRYPTO_ALG 
#undef DIGEST_SIZE 
#undef EMPTY_STR

#define CRYPTO_CONTEXT  mbedtls_sha256_context
#define CRYPTO_DBG      
#define CRYPTO_MTD      PIC32_ENCRYPTION 
#define CRYPTO_ALG      PIC32_ALGO_SHA256
#define DIGEST_SIZE     32
#define EMPTY_STR       "\xe3\xb0\xc4\x42\x98\xfc\x1c\x14\x9a\xfb\xf4\xc8\x99\x6f\xb9\x24\x27\xae\x41\xe4\x64\x9b\x93\x4c\xa4\x95\x99\x1b\x78\x52\xb8\x55"

static void mbedtls_sha256_reset(CRYPTO_CONTEXT * ctx) {
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

void mbedtls_sha256_init(CRYPTO_CONTEXT * ctx) {
    CRYPTO_DBG("[SHA256] +: %X\n", ctx);
    memset(ctx, 0, sizeof (CRYPTO_CONTEXT));
}

void mbedtls_sha256_starts(CRYPTO_CONTEXT * ctx, int is224) {
    CRYPTO_DBG("[SHA256] S: %X\n", ctx);
    memset(ctx, 0, sizeof (CRYPTO_CONTEXT));
    if (is224) {
        CRYPTO_DBG("[ERROR] SHA224 NS\n", ctx);
        ctx->cache.size = -1; // mark error
    }
}

void mbedtls_sha256_free(CRYPTO_CONTEXT * ctx) {
    CRYPTO_DBG("[SHA256] -: %X\n", ctx);
    mbedtls_sha256_reset(ctx);
}

void mbedtls_sha256_clone(CRYPTO_CONTEXT * dst, const CRYPTO_CONTEXT * src) {
    CRYPTO_DBG("[SHA256] C: %X <<< %X\n", dst, src);
    //memcpy(dst, src, sizeof (CRYPTO_CONTEXT));
    dst->cache.data = (uint8_t*) pvPortMalloc(src->cache.size);
    if (dst->cache.data) {
        if (src->cache.data && src->cache.size)
            memcpy(dst->cache.data, src->cache.data, src->cache.size);
        dst->cache.size = src->cache.size;
    } else {
        dst->cache.size = -1; // mark error
        CRYPTO_DBG("[ERROR] SHA256 ERRORCLONE\n");
    }
}

void mbedtls_sha256_update(CRYPTO_CONTEXT * ctx, const unsigned char * input, size_t ilen) {
    CRYPTO_DBG("[SHA256] U: %X\n", ctx);
    if (0 == ilen || ctx->cache.size >= PIC32_MAX_MEMORY_LIMIT) return;
    cacheUpdate(&ctx->cache, input, ilen);
    if (ctx->cache.size >= PIC32_MAX_MEMORY_LIMIT) {
        CRYPTO_DBG("[ERROR] SHA256 LIMIT\n");
    }
}

void mbedtls_sha256_finish(CRYPTO_CONTEXT * ctx, unsigned char output[32]) {
    CRYPTO_DBG("[SHA256] F: %X\n", ctx);
    if (NULL == ctx->cache.data ||
            ctx->cache.size >= PIC32_MAX_MEMORY_LIMIT ||
            Pic32Crypto((const uint8_t *) ctx->cache.data, ctx->cache.size,
            (uint32_t*) output, DIGEST_SIZE, CRYPTO_MTD, CRYPTO_ALG, 0, NULL, 0, NULL, 0))
        memcpy(output, EMPTY_STR, DIGEST_SIZE);
    mbedtls_sha256_reset(ctx);
    //PrintHex("[SHA256] ", (char*) output, DIGEST_SIZE, "\n");
}

void mbedtls_sha256_process(CRYPTO_CONTEXT *ctx, const unsigned char data[64]) {
    CRYPTO_DBG("[SHA256] P: %X\n", ctx);
    //mbedtls_sha256_init(ctx);
    //mbedtls_sha256_update(ctx, data, 64);
    //mbedtls_sha256_finish(ctx, ctx->buf);
    //mbedtls_sha256_free(ctx);
    (void) data;
}

#undef CRYPTO_CONTEXT
#undef CRYPTO_DBG 
#undef CRYPTO_MTD 
#undef CRYPTO_ALG 
#undef DIGEST_SIZE 
#undef EMPTY_STR

#endif /*MBEDTLS_SHA256_ALT*/
#endif /*MBEDTLS_SHA256_C*/
