#include "sys.h"
#include "osal.h"
#include "pic32_crypto.h"

#undef LG_I 
#undef LG_E 

#define LG_I 
#define LG_E LOG

static SemaphoreHandle_t crypto_mutex = NULL;

static void crypto_mutex_lock(void) {
    int state = xTaskGetSchedulerState();
    if (taskSCHEDULER_NOT_STARTED == state) return; // FOR SELF TEST in main()
    if (NULL == crypto_mutex) {
        crypto_mutex = xSemaphoreCreateMutex();
        if (NULL == crypto_mutex)
            vAssertCalled(__FILE__, __LINE__);
    }
    if (state == taskSCHEDULER_RUNNING)
        while (pdFALSE == xSemaphoreTake(crypto_mutex, portMAX_DELAY));
}

static void crypto_mutex_unlock(void) {
    int state = xTaskGetSchedulerState();
    if (taskSCHEDULER_NOT_STARTED == state) return; // FOR SELF TEST in main()
    while (pdFALSE == xSemaphoreGive(crypto_mutex));
}

inline __attribute__((always_inline)) uint32_t rotlFixed(uint32_t x, uint32_t y) {
    return (x << y) | (x >> (sizeof (y) * 8 - y));
}

inline __attribute__((always_inline)) uint32_t rotrFixed(uint32_t x, uint32_t y) {
    return (x >> y) | (x << (sizeof (y) * 8 - y));
}

inline __attribute__((always_inline)) uint32_t ByteReverseWord32(uint32_t value) {
    value = ((value & 0xFF00FF00) >> 8) | ((value & 0x00FF00FF) << 8);
    return rotlFixed(value, 16U);
}

static void ByteReverseWords(uint32_t* out, const uint32_t* in, uint32_t uint8_tCount) {
    uint32_t count = uint8_tCount / (uint32_t)sizeof (uint32_t), i;
    for (i = 0; i < count; i++)
        out[i] = ByteReverseWord32(in[i]);
}

static uint8_t * realign(uint8_t * buffer, uint32_t size, int * isCopy, int isInput) {
    *isCopy = 0;
    /* check pointer alignment - must be word aligned */
    if (((uint32_t) buffer % sizeof (uint32_t)) == 0)
        return buffer;
    uint8_t * newBuffer = (uint8_t*) pvPortMalloc(size);
    *isCopy = (bool) newBuffer;
    if (newBuffer && isInput) {
        memcpy(newBuffer, buffer, size);
        LG_I("[N-I] %X, %X, %d, %d\n", newBuffer, buffer, size, (int) newBuffer % sizeof (uint32_t));
    } else {
        LG_I("[N-O] %X, %X, %d, %d\n", newBuffer, buffer, size, (int) newBuffer % sizeof (uint32_t));
    }
    return newBuffer;
}

int Pic32Crypto(const uint8_t * input, uint32_t inLen, uint32_t * output, uint32_t outLen,
        uint32_t dir, uint32_t algo, uint32_t cryptoalgo,
        uint32_t * key, uint32_t keyLen, uint32_t * iv, uint32_t ivLen) {
    volatile bufferDescriptor bd __attribute__((aligned(8)));
    securityAssociation sa __attribute__((aligned(8)));
    securityAssociation *sa_p;
    bufferDescriptor *bd_p;
    uint8_t *out_p, *in_p, *in, *out;
    uint32_t *dst;
    uint32_t padRemain;
    int inputCopy = 0, outputCopy = 0, ret = 0;
    /* check args *************************************************************/
    if (input == NULL || inLen == 0 || output == NULL || outLen == 0) {
        LG_E("[ERROR] crypto arguments\n");
        return BAD_ARG_E;
    }
    in = realign((uint8_t *) input, inLen, &inputCopy, 1);
    if (NULL == in) {
        ret = MEMORY_E;
        LG_E("[ERROR] crypto input\n");
        goto END;
    }
    out = realign((uint8_t *) output, outLen, &outputCopy, 0);
    if (NULL == out) {
        ret = MEMORY_E;
        LG_E("[ERROR] crypto output\n");
        goto END;
    }
    if (((size_t) in % sizeof (uint32_t)) || ((size_t) out % sizeof (uint32_t))) {
        LG_E("[ERROR] crypto buffer is not aligned: %X, %X\n", in, out);
        ret = MEMORY_E;
        goto END; /* buffer is not aligned */
    }
    /**************************************************************************/
    /* get uncached address */   
    out_p = KVA0_TO_KVA1(out);
    in_p = KVA0_TO_KVA1(in);
    /* Sync cache if in physical memory (not flash) */
    if (PIC32MZ_IF_RAM(in_p))
        memcpy(in_p, in, inLen);

    /* Set up the Security Association */
    sa_p = KVA0_TO_KVA1(&sa);
    memset(sa_p, 0, sizeof (sa));
    sa_p->SA_CTRL.ALGO = algo;
    sa_p->SA_CTRL.ENCTYPE = dir;
    sa_p->SA_CTRL.FB = 1; /* first block */
    sa_p->SA_CTRL.LNC = 1; /* Load new set of keys */
    if (key) {
        /* cipher */
        sa_p->SA_CTRL.CRYPTOALGO = cryptoalgo;
        switch (keyLen) {
            case 32:
                sa_p->SA_CTRL.KEYSIZE = PIC32_KEYSIZE_256;
                break;
            case 24:
            case 8: /* DES */
                sa_p->SA_CTRL.KEYSIZE = PIC32_KEYSIZE_192;
                break;
            case 16:
                sa_p->SA_CTRL.KEYSIZE = PIC32_KEYSIZE_128;
                break;
        }
dst = (uint32_t*) KVA0_TO_KVA1(sa.SA_ENCKEY + (sizeof (sa.SA_ENCKEY) / sizeof (uint32_t)) - (keyLen / sizeof (uint32_t)));
ByteReverseWords(dst, key, keyLen);
        if (iv && ivLen > 0) {
            sa_p->SA_CTRL.LOADIV = 1;
dst = (uint32_t*) KVA0_TO_KVA1(sa.SA_ENCIV + (sizeof (sa.SA_ENCIV) / sizeof (uint32_t)) - (ivLen / sizeof (uint32_t)));
ByteReverseWords(dst, iv, ivLen);
        }
    } else {
        /* hashing */
        sa_p->SA_CTRL.LOADIV = 1;
        sa_p->SA_CTRL.IRFLAG = 0; /* immediate result for hashing */
dst = (uint32_t*) KVA0_TO_KVA1(sa.SA_AUTHIV + (sizeof (sa.SA_AUTHIV) / sizeof (uint32_t)) - (outLen / sizeof (uint32_t)));
ByteReverseWords(dst, (uint32_t*) out, outLen);
    }

    /* Set up the Buffer Descriptor */
    bd_p = KVA0_TO_KVA1(&bd);
    memset(bd_p, 0, sizeof (bd));
    bd_p->BD_CTRL.BUFLEN = inLen;
    padRemain = (inLen % 4); /* make sure buffer is 4-byte multiple */
    if (padRemain != 0)
        bd_p->BD_CTRL.BUFLEN += (4 - padRemain);
    bd_p->BD_CTRL.SA_FETCH_EN = 1; /* Fetch the security association */
    bd_p->BD_CTRL.PKT_INT_EN = 1; /* enable interrupt */
    bd_p->BD_CTRL.LAST_BD = 1; /* last buffer desc in chain */
    bd_p->BD_CTRL.LIFM = 1; /* last in frame */
    bd_p->SA_ADDR = (unsigned int) KVA_TO_PA(&sa);
    bd_p->SRCADDR = (unsigned int) KVA_TO_PA(in);
    if (key) {
        /* cipher */
        if (input != (uint8_t*) output)
            memset(out_p, 0, outLen); /* clear output buffer */
        bd_p->DSTADDR = (unsigned int) KVA_TO_PA(out);
    } else {
        /* hashing */
        /* digest result returned in UPDPTR */
        bd_p->UPDPTR = (unsigned int) KVA_TO_PA(out);
    }
    bd_p->NXTPTR = (unsigned int) KVA_TO_PA(&bd);
    bd_p->MSGLEN = inLen; /* actual message size */
    bd_p->BD_CTRL.DESC_EN = 1; /* enable this descriptor */

    //ENTER_CRITICAL();
    crypto_mutex_lock(); /*****************************************************/
    CECON = 1 << 6; /* Software Reset & Start Engine */
    while (CECON);
    CEINTSRC = 0xF; /* Clear the interrupt flags */
    /*** Run the engine ***/
    CEPOLLCON = 10; ////// How often (in bus cycles) to poll the BD Control word
    CEBDPADDR = (unsigned int) KVA_TO_PA(&bd);
    CEINTEN = 0x07; /* enable DMA Packet Completion Interrupt */
    /* input swap, enable BD fetch and start DMA */
#if PIC32_NO_OUT_SWAP
    CECON = 0x25;
#else
    CECON = 0xA5; /* bit 7 = enable out swap */
#endif        
    int timeout = 0x1FFFFFF;
    while (CEINTSRCbits.PKTIF == 0 && --timeout > 0); /* wait for operation to complete */
    CEINTSRC = 0xF; /* Clear the interrupt flags */
    /* check for errors */
    if (CESTATbits.ERROP || timeout < 1) {
        LG_E("[ERROR] CESTAT.ERROP: %u, timeout: %d\n", (uint32_t)CESTATbits.ERROP, timeout);
        ret = -CESTATbits.ERROP; //ASYNC_OP_E;
    }
    CECON = 1 << 6; /* Software Reset & Start Engine */
    while (CECON);
    CEINTSRC = 0xF; /* Clear the interrupt flags */
    crypto_mutex_unlock(); /***************************************************/
    //EXIT_CRITICAL();

    if (iv && ivLen > 0) {
        /* set iv for the next call */
        if (dir == PIC32_ENCRYPTION) {
            memcpy(iv, KVA0_TO_KVA1(out + (outLen - ivLen)), ivLen);
#if !PIC32_NO_OUT_SWAP
            /* hardware already swapped output, so we need to swap back */
            ByteReverseWords(iv, iv, ivLen);
#endif
        } else {
            ByteReverseWords(iv, KVA0_TO_KVA1(in + (inLen - ivLen)), ivLen);
        }
    }
    /* copy result to output */
#if PIC32_NO_OUT_SWAP
    /* swap bytes */
    ByteReverseWords(output, (uint32_t*) out_p, outLen);
#elif defined(_SYS_DEVCON_LOCAL_H)
    /* sync cache */
    SYS_DEVCON_DataCacheInvalidate((uint32_t) out, outLen);
#else
    memcpy(output, out_p, outLen);
#endif

END:
    if (outputCopy) {
        LG_I("[F-O] %X, %X\n", out, output);
        if (out)
            free(out);
        out = NULL;
    }
    if (inputCopy) {
        LG_I("[F-I] %X, %X\n", in, input);
        if (in)
            free(in);
        in = NULL;
    }
    if (ret) {
        LG_E("[ERROR] crypto: %d\n", ret);
    }
    return ret;
}

void cacheUpdate(hash_cache_t * cache, const uint8_t * src, size_t srcSize) {
    if (NULL == cache || NULL == src || 0 == srcSize) return;
    size_t newSize = cache->size + srcSize;
    if (newSize >= PIC32_MAX_MEMORY_LIMIT)
        goto error;
    cache->data = pvPortRealloc(cache->data, newSize);
    if (cache->data) {
        memcpy(cache->data + cache->size, src, srcSize);
        cache->size = newSize;
    } else {
error:
        if (cache->data)
            free(cache->data);
        cache->data = NULL;
        cache->size = -1;
        LG_E("[ERROR] HASH LIMIT\n");
    }
}



#undef LG_I 
#undef LG_E 










