/* pic32mz-crypt.h
 *
 * Copyright (C) 2006-2017 wolfSSL Inc.
 *
 * This file is part of wolfSSL.
 *
 * wolfSSL is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * wolfSSL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1335, USA
 */

#ifndef PIC32MZ_CRYPT_H
#define PIC32MZ_CRYPT_H
#ifdef __cplusplus
    extern "C" {
#endif
        
//[WizIO] 
#include "sys.h"
#define XMEMSET                 memset   
#define XMEMCPY                 memcpy
#define XMEMCMP                 memcmp
#define XMALLOC(SIZE, H, M)     malloc(SIZE)
#define XFREE(PTR, H, M)        free(PTR)
#define ALIGN16
          
#define wolfSSL_CryptHwMutexUnLock()    do{}while(0)
#define wolfSSL_CryptHwMutexLock()      (0)
         
#define BAD_FUNC_ARG    -1
#define BUFFER_E        -2  
#define MEMORY_E        -3
#define ASYNC_OP_E      -4
#define INVALID_DEVID   BAD_FUNC_ARG
        
#define WOLFSSL_MICROCHIP_PIC32MZ        
        
#define WOLFSSL_PIC32MZ_HASH       
//#define NO_MD5                          
#define NO_SHA                          
#define NO_SHA256   
        
//#define WOLFSSL_PIC32MZ_CRYPT        
//#define NO_AES                          
//#define NO_DES3                         



        
        
        
        

#ifdef WOLFSSL_MICROCHIP_PIC32MZ

//[WizIO]  
typedef unsigned char byte;        
typedef unsigned long word32;        
        
#ifndef MICROCHIP_PIC32
    #define MICROCHIP_PIC32
#endif

/* If algos aren't enabled then turn off */
#ifdef WOLFSSL_PIC32MZ_HASH
    #if defined(NO_MD5) && defined(NO_SHA) && defined(NO_SHA256)
        #undef WOLFSSL_PIC32MZ_HASH
    #endif
#endif

#ifdef WOLFSSL_PIC32MZ_CRYPT
    #if defined(NO_AES) && defined(NO_DES3)
        #undef WOLFSSL_PIC32MZ_CRYPT
    #endif
#endif

/* Enables support for large hashing */
/* requires exclusive access to crypto hardware done at application layer 
    DO NOT ENABLE
*/
//#define WOLFSSL_PIC32MZ_LARGE_HASH


#include <xc.h>
//#include <sys/endian.h>
//#include <sys/kmem.h>


/* PIC32 Crypto Structures */
typedef struct saCtrl {
    unsigned int CRYPTOALGO : 4;
    unsigned int MULTITASK : 3;
    unsigned int KEYSIZE : 2;
    unsigned int ENCTYPE : 1;
    unsigned int ALGO : 7;
    unsigned int : 3;
    unsigned int FLAGS : 1;
    unsigned int FB : 1;
    unsigned int LOADIV : 1;
    unsigned int LNC : 1;
    unsigned int IRFLAG : 1;
    unsigned int ICVONLY : 1;
    unsigned int OR_EN : 1;
    unsigned int NO_RX : 1;
    unsigned int : 1;
    unsigned int VERIFY : 1;
    unsigned int : 2;
} saCtrl;

typedef struct securityAssociation {
    saCtrl SA_CTRL;
    unsigned int SA_AUTHKEY[8];
    unsigned int SA_ENCKEY[8];
    unsigned int SA_AUTHIV[8];
    unsigned int SA_ENCIV[4];
} securityAssociation;

typedef struct bdCtrl {
    unsigned int BUFLEN : 16;
    unsigned int CBD_INT_EN : 1;
    unsigned int PKT_INT_EN : 1;
    unsigned int LIFM : 1;
    unsigned int LAST_BD : 1;
    unsigned int CRDMA_EN : 1;
    unsigned int UPD_RES : 1;
    unsigned int SA_FETCH_EN : 1;
    unsigned int SEC_CODE : 8;
    volatile unsigned int DESC_EN : 1;
} bdCtrl;

typedef struct bufferDescriptor {
    bdCtrl BD_CTRL;
    unsigned int SA_ADDR;
    unsigned int SRCADDR;
    unsigned int DSTADDR;
    unsigned int NXTPTR;
    unsigned int UPDPTR;
    unsigned int MSGLEN;
    unsigned int ENCOFF;
} bufferDescriptor;


/* Cache Updates Struct */
typedef struct hashUpdCache {
    unsigned char*  buf;
    unsigned int    bufLen;
    unsigned int    updLen;
    int             isCopy;
#ifdef WOLFSSL_PIC32MZ_LARGE_HASH
    unsigned int    finalLen;
#endif
} hashUpdCache;


/* Direction */
#define PIC32_ENCRYPTION     0b1
#define PIC32_DECRYPTION     0b0

/* Algorithm */
#define PIC32_ALGO_HMAC1     0b01000000
#define PIC32_ALGO_SHA256    0b00100000
#define PIC32_ALGO_SHA1      0b00010000
#define PIC32_ALGO_MD5       0b00001000

#define PIC32_ALGO_AES       0b00000100
#define PIC32_ALGO_TDES      0b00000010
#define PIC32_ALGO_DES       0b00000001

/* Crypto Algo */
/* AES */
#define PIC32_CRYPTOALGO_AES_GCM  0b1110
#define PIC32_CRYPTOALGO_RCTR     0b1101
#define PIC32_CRYPTOALGO_RCBC_MAC 0b1100
#define PIC32_CRYPTOALGO_ROFB     0b1011
#define PIC32_CRYPTOALGO_RCFB     0b1010
#define PIC32_CRYPTOALGO_RCBC     0b1001
#define PIC32_CRYPTOALGO_RECB     0b1000
/* Triple-DES */
#define PIC32_CRYPTOALGO_TOFB     0b0111
#define PIC32_CRYPTOALGO_TCFB     0b0110
#define PIC32_CRYPTOALGO_TCBC     0b0101
#define PIC32_CRYPTOALGO_TECB     0b0100
/* DES */
#define PIC32_CRYPTOALGO_OFB      0b0011
#define PIC32_CRYPTOALGO_CFB      0b0010
#define PIC32_CRYPTOALGO_CBC      0b0001
#define PIC32_CRYPTOALGO_ECB      0b0000

/* Key Size */
#define PIC32_KEYSIZE_256         0b10
#define PIC32_KEYSIZE_192         0b01
#define PIC32_KEYSIZE_128         0b00

/* PIC32 Minimum Buffer/Block Sizes */
#define PIC32_BLOCKSIZE_HASH    64
#define PIC32_BLOCKSIZE_HMAC    PIC32_BLOCKSIZE_HASH
#define PIC32_BLOCKSIZE_MD5     PIC32_BLOCKSIZE_HASH
#define PIC32_BLOCKSIZE_SHA1    PIC32_BLOCKSIZE_HASH
#define PIC32_BLOCKSIZE_SHA256  PIC32_BLOCKSIZE_HASH
#define PIC32_BLOCKSIZE_AES     16
#define PIC32_BLOCKSIZE_TDES    24
#define PIC32_BLOCKSIZE_DES     8
#define PIC32_DIGEST_SIZE       32


/* Helper Macros */
#define PIC32MZ_IF_RAM(addr) (KVA_TO_PA(addr) < 0x1D000000)

/* If EF part then Crypto engine supports swapping output bytes */
#define PIC32_NO_OUT_SWAP    ((__PIC32_FEATURE_SET0 == 'E') && \
                              (__PIC32_FEATURE_SET1 == 'C'))


#ifndef NO_AES
int wc_Pic32AesCrypt(word32 *key, int keyLen, word32 *iv, int ivLen,
        byte* out, const byte* in, word32 sz,
        int dir, int algo, int cryptoalgo);
#endif
#ifndef NO_DES3
int wc_Pic32DesCrypt(word32 *key, int keyLen, word32 *iv, int ivLen,
        byte* out, const byte* in, word32 sz,
        int dir, int algo, int cryptoalgo);
#endif

#ifdef WOLFSSL_PIC32MZ_HASH
int wc_Pic32Hash(const byte* in, int inLen, word32* out, int outLen, int algo);
int wc_Pic32HashCopy(hashUpdCache* src, hashUpdCache* dst);
#endif

#endif /* WOLFSSL_MICROCHIP_PIC32MZ */



////////////////////////////////////////////////////////////////////////////////
#define PIC32MZ_MAX_BD   2
#define PIC32_HASH_SIZE 32  
////////////////////////////////////////////////////////////////////////////////
#define MD5_HASH_SIZE 16
enum { /* in bytes */
    WC_MD5             =  0, /* hash type unique */
    WC_MD5_BLOCK_SIZE  = 64,
    WC_MD5_DIGEST_SIZE = 16,
    WC_MD5_PAD_SIZE    = 56
};
#define MD5_DIGEST_SIZE WC_MD5_DIGEST_SIZE

/* MD5 digest */
typedef struct Md5 {
#ifdef STM32_HASH
    STM32_HASH_Context stmCtx;
#else
    word32  buffLen;   /* in bytes          */
    word32  loLen;     /* length in bytes   */
    word32  hiLen;     /* length in bytes   */
    word32  buffer[WC_MD5_BLOCK_SIZE  / sizeof(word32)];
#ifdef WOLFSSL_PIC32MZ_HASH
    word32  digest[PIC32_DIGEST_SIZE / sizeof(word32)];
#else
    word32  digest[WC_MD5_DIGEST_SIZE / sizeof(word32)];
#endif
    void*   heap;
#ifdef WOLFSSL_PIC32MZ_HASH
    hashUpdCache cache; /* cache for updates */
#endif
#endif /* STM32_HASH */
#ifdef WOLFSSL_ASYNC_CRYPT
    WC_ASYNC_DEV asyncDev;
#endif /* WOLFSSL_ASYNC_CRYPT */
} Md5;

////////////////////////////////////////////////////////////////////////////////

/* in bytes */
enum {
    WC_SHA              =  1,    /* hash type unique */
    WC_SHA_BLOCK_SIZE   = 64,
    WC_SHA_DIGEST_SIZE  = 20,
    WC_SHA_PAD_SIZE     = 56
};
#define SHA_DIGEST_SIZE WC_SHA_DIGEST_SIZE

typedef struct Sha {
    word32  buffLen;   /* in bytes          */
    word32  loLen;     /* length in bytes   */
    word32  hiLen;     /* length in bytes   */
    word32  buffer[WC_SHA_BLOCK_SIZE  / sizeof(word32)];
    #ifdef WOLFSSL_PIC32MZ_HASH
        word32  digest[PIC32_DIGEST_SIZE / sizeof(word32)];
    #else
        word32  digest[WC_SHA_DIGEST_SIZE / sizeof(word32)];
    #endif
        void*   heap;
    #ifdef WOLFSSL_PIC32MZ_HASH
        hashUpdCache cache; /* cache for updates */
    #endif
} Sha;

////////////////////////////////////////////////////////////////////////////////
/* in bytes */
enum {
    WC_SHA256              =  2,   /* hash type unique */
    WC_SHA256_BLOCK_SIZE   = 64,
    WC_SHA256_DIGEST_SIZE  = 32,
    WC_SHA256_PAD_SIZE     = 56
};
#define SHA256_DIGEST_SIZE WC_SHA256_DIGEST_SIZE

typedef struct Sha256 {
#ifdef FREESCALE_LTC_SHA
    ltc_hash_ctx_t ctx;
#elif defined(STM32_HASH)
    STM32_HASH_Context stmCtx;
#else
    /* alignment on digest and buffer speeds up ARMv8 crypto operations */
    ALIGN16 word32  digest[WC_SHA256_DIGEST_SIZE / sizeof(word32)];
    ALIGN16 word32  buffer[WC_SHA256_BLOCK_SIZE  / sizeof(word32)];
    word32  buffLen;   /* in bytes          */
    word32  loLen;     /* length in bytes   */
    word32  hiLen;     /* length in bytes   */
    void*   heap;
#ifdef USE_INTEL_SPEEDUP
    const byte* data;
#endif
#ifdef WOLFSSL_PIC32MZ_HASH
    hashUpdCache cache; /* cache for updates */
#endif
#ifdef WOLFSSL_ASYNC_CRYPT
    WC_ASYNC_DEV asyncDev;
#endif /* WOLFSSL_ASYNC_CRYPT */
#endif
} Sha256;

/* in bytes */
enum {
    WC_SHA224              =   8,   /* hash type unique */
    WC_SHA224_BLOCK_SIZE   =   WC_SHA256_BLOCK_SIZE,
    WC_SHA224_DIGEST_SIZE  =   28,
    WC_SHA224_PAD_SIZE     =   WC_SHA256_PAD_SIZE
};
#define SHA224_DIGEST_SIZE WC_SHA224_DIGEST_SIZE
typedef Sha256 Sha224;
////////////////////////////////////////////////////////////////////////////////

enum {
    AES_ENC_TYPE   = 1,   /* cipher unique type */
    AES_ENCRYPTION = 0,
    AES_DECRYPTION = 1,
    KEYWRAP_BLOCK_SIZE = 8,
    AES_BLOCK_SIZE = 16
};

typedef struct Aes {
    /* AESNI needs key first, rounds 2nd, not sure why yet */
    ALIGN16 word32 key[60];
    word32  rounds;
    int     keylen;

    ALIGN16 word32 reg[AES_BLOCK_SIZE / sizeof(word32)];      /* for CBC mode */
    ALIGN16 word32 tmp[AES_BLOCK_SIZE / sizeof(word32)];      /* same         */

#ifdef HAVE_AESGCM
    ALIGN16 byte H[AES_BLOCK_SIZE];
#ifdef GCM_TABLE
    /* key-based fast multiplication table. */
    ALIGN16 byte M0[256][AES_BLOCK_SIZE];
#endif /* GCM_TABLE */
#endif /* HAVE_AESGCM */
#ifdef WOLFSSL_AESNI
    byte use_aesni;
#endif /* WOLFSSL_AESNI */
#ifdef WOLFSSL_ASYNC_CRYPT
    word32 asyncKey[AES_MAX_KEY_SIZE/8/sizeof(word32)]; /* raw key */
    word32 asyncIv[AES_BLOCK_SIZE/sizeof(word32)]; /* raw IV */
    WC_ASYNC_DEV asyncDev;
#endif /* WOLFSSL_ASYNC_CRYPT */
#if defined(WOLFSSL_AES_COUNTER) || defined(WOLFSSL_AES_CFB)
    word32  left;            /* unused bytes left from last call */
#endif
#ifdef WOLFSSL_XILINX_CRYPT
    XSecure_Aes xilAes;
    XCsuDma     dma;
    word32      key_init[8];
    word32      kup;
#endif
    void*  heap; /* memory hint to use */
} Aes;



#ifdef __cplusplus
    } /* extern "C" */
#endif
#endif /* PIC32MZ_CRYPT_H */
