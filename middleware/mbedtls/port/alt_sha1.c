#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif

#if defined(MBEDTLS_SHA1_C)
#include "mbedtls/sha1.h"

#if defined(MBEDTLS_SHA1_ALT)
#include "pic32mz-crypt.h"

void mbedtls_sha1_init(mbedtls_sha1_context *ctx) {
    memset(ctx, 0, sizeof (mbedtls_sha1_context));
}

void mbedtls_sha1_free(mbedtls_sha1_context *ctx) {
    if (ctx == NULL)
        return;
    memset(ctx, 0, sizeof (mbedtls_sha1_context));
}

void mbedtls_sha1_clone(mbedtls_sha1_context *dst, const mbedtls_sha1_context *src) {
    *dst = *src;
}

void mbedtls_sha1_starts(mbedtls_sha1_context *ctx) {
    wc_InitSha_ex(ctx, NULL, 0);
}

void mbedtls_sha1_update(mbedtls_sha1_context *ctx, const unsigned char *input, size_t ilen) {
    wc_ShaUpdate(ctx, (const byte*) input, (word32) ilen);
}

void mbedtls_sha1_finish(mbedtls_sha1_context *ctx, unsigned char output[20]) {
    wc_ShaFinal(ctx, (byte*) output);
}

void mbedtls_sha1_process(mbedtls_sha1_context *ctx, const unsigned char data[64]) {
    unsigned char output[65] = {0};
    mbedtls_sha1_init(ctx);
    mbedtls_sha1_starts(ctx);
    mbedtls_sha1_update(ctx, data, 64);
    mbedtls_sha1_finish(ctx, output);
}

#endif /*MBEDTLS_SHA1_ALT*/
#endif /*MBEDTLS_SHA1_C*/