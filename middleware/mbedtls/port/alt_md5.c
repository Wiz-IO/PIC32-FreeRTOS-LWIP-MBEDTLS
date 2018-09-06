#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif

#if defined(MBEDTLS_MD5_C)
#include "mbedtls/md5.h"

#ifdef MBEDTLS_MD5_ALT
#include "pic32mz-crypt.h"   

void mbedtls_md5_init(mbedtls_md5_context * ctx) {
    memset(ctx, 0, sizeof ( mbedtls_md5_context));
}

void mbedtls_md5_free(mbedtls_md5_context *ctx) {
    if (ctx == NULL)
        return;    
    memset(ctx, 0, sizeof ( mbedtls_md5_context));
}

void mbedtls_md5_clone(mbedtls_md5_context *dst, const mbedtls_md5_context *src) {
    *dst = *src;
}

void mbedtls_md5_starts(mbedtls_md5_context *ctx) { 
    wc_InitMd5_ex(ctx, NULL, 0);
}

void mbedtls_md5_update(mbedtls_md5_context * ctx, const unsigned char * input, size_t ilen) {
    wc_Md5Update(ctx, input, (uint32_t) ilen);
}

void mbedtls_md5_finish(mbedtls_md5_context * ctx, unsigned char output[16]) {
    wc_Md5Final(ctx, (uint8_t*) output);
}

void mbedtls_md5_process(mbedtls_md5_context *ctx, const unsigned char data[64]) {
    unsigned char output[65] = {0};
    mbedtls_md5_starts(ctx);
    mbedtls_md5_update(ctx, data, 64);
    mbedtls_md5_finish(ctx, output);
}

#endif /* MBEDTLS_MD5_ALT */
#endif /* MBEDTLS_MD5_C */