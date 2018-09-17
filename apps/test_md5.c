#include "sys.h"

typedef struct {
    uint32_t total[2]; /*!< number of bytes processed  */
    uint32_t state[4]; /*!< intermediate digest state  */
    unsigned char buffer[64]; /*!< data block being processed */
    unsigned char iv[64];
} md5_context;

#define PUT_UINT32_LE(n,b,i)                                    \
{                                                               \
    (b)[(i)    ] = (unsigned char) ( ( (n)       ) & 0xFF );    \
    (b)[(i) + 1] = (unsigned char) ( ( (n) >>  8 ) & 0xFF );    \
    (b)[(i) + 2] = (unsigned char) ( ( (n) >> 16 ) & 0xFF );    \
    (b)[(i) + 3] = (unsigned char) ( ( (n) >> 24 ) & 0xFF );    \
}

void printhex(char * b, char * p, int size, char * e) {
    int i;
    if (b) LOG("%s: ", b);
    for (i = 0; i < size; i++)
        LOG("%02X", (int) p[i] & 0xFF);
    if (e) LOG("%s", e);
}

void md5_starts(md5_context * ctx) {
    ctx->total[0] = 0;
    ctx->total[1] = 0;
    ctx->state[0] = 0x67452301;
    ctx->state[1] = 0xEFCDAB89;
    ctx->state[2] = 0x98BADCFE;
    ctx->state[3] = 0x10325476;
}

void md5_update(md5_context *ctx, const unsigned char *input, size_t ilen) {
    size_t fill;
    uint32_t left;
    if (ilen == 0)
        return;
    left = ctx->total[0] & 0x3F;
    fill = 64 - left;
    ctx->total[0] += (uint32_t) ilen;
    ctx->total[0] &= 0xFFFFFFFF;
    if (ctx->total[0] < (uint32_t) ilen)
        ctx->total[1]++;
    if (left && ilen >= fill) {
        LOG("FILL: %d\n", fill);
        memcpy((void *) (ctx->buffer + left), input, fill);
        Pic32Crypto(ctx->buffer, 64, (unsigned long*) ctx->buffer, 64, 1, 0b00001000, 0, NULL, 0, ctx->iv, 64);
        input += fill;
        ilen -= fill;
        left = 0;
        printhex("IV: ", ctx->iv, 64, "\n");
        printhex("BF: ", ctx->buffer, 64, "\n");        
    }
    while (ilen >= 64) {
        LOG("ILEN: %d\n", ilen);
        Pic32Crypto(input, 64, (unsigned long*) ctx->buffer, 64, 1, 0b00001000, 0, NULL, 0, ctx->iv, 64);
        input += 64;
        ilen -= 64;
        printhex("IV: ", ctx->iv, 64, "\n");
        printhex("BF: ", ctx->buffer, 64, "\n");
    }
    if (ilen > 0) {
        memcpy((void *) (ctx->buffer + left), input, ilen);
    }
}

static const unsigned char xmd5_padding[64] = {
    0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

void md5_finish(md5_context * ctx, unsigned char output[16]) {
    uint32_t last, padn;
    uint32_t high, low;
    unsigned char msglen[8];
    high = (ctx->total[0] >> 29) | (ctx->total[1] << 3);
    low = (ctx->total[0] << 3);
    PUT_UINT32_LE(low, msglen, 0);
    PUT_UINT32_LE(high, msglen, 4);
    last = ctx->total[0] & 0x3F;
    padn = (last < 56) ? (56 - last) : (120 - last);
    md5_update(ctx, xmd5_padding, padn);
    md5_update(ctx, msglen, 8);
    PUT_UINT32_LE(ctx->state[0], output, 0);
    PUT_UINT32_LE(ctx->state[1], output, 4);
    PUT_UINT32_LE(ctx->state[2], output, 8);
    PUT_UINT32_LE(ctx->state[3], output, 12);
}

void md5() {
    md5_context c;
    unsigned char output[16];
    memset(&c, 0, sizeof (c));
    md5_starts(&c);
    md5_update(&c, "1234567890123456123456789012345612345678901234561234567890123456", 64);
    //md5_update(&c, "1234567890123456", 16);
    md5_finish(&c, output);
    while (1);
}