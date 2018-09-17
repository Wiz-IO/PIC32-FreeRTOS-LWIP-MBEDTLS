/* 
 * File:   pic32_crypto.h
 * Author: Georgi Angelov
 *
 * Created on 09.09.2018, 14:53
 */

#ifndef PIC32_CRYPTO_H
#define	PIC32_CRYPTO_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "sys.h"

#define BAD_ARG_E           (-1)
#define ASYNC_OP_E          (-2)
#define MEMORY_E            (-3)    


/* PIC32 Crypto Structures */
typedef struct saCtrl {
    unsigned int CRYPTOALGO : 4;
    unsigned int MULTITASK  : 3;
    unsigned int KEYSIZE    : 2;
    unsigned int ENCTYPE    : 1;
    unsigned int ALGO       : 7;
    unsigned int            : 3;
    unsigned int FLAGS      : 1;
    unsigned int FB         : 1;
    unsigned int LOADIV     : 1;
    unsigned int LNC        : 1;
    unsigned int IRFLAG     : 1;
    unsigned int ICVONLY    : 1;
    unsigned int OR_EN      : 1;
    unsigned int NO_RX      : 1;
    unsigned int            : 1;
    unsigned int VERIFY     : 1;
    unsigned int            : 2;
} saCtrl;

typedef struct securityAssociation {
    saCtrl SA_CTRL;
    unsigned int SA_AUTHKEY[8];
    unsigned int SA_ENCKEY[8];
    unsigned int SA_AUTHIV[8];
    unsigned int SA_ENCIV[4];
} securityAssociation;

typedef struct bdCtrl {
    unsigned int BUFLEN             : 16;
    unsigned int CBD_INT_EN         : 1;
    unsigned int PKT_INT_EN         : 1;
    unsigned int LIFM               : 1;
    unsigned int LAST_BD            : 1;
    unsigned int CRDMA_EN           : 1;
    unsigned int UPD_RES            : 1;
    unsigned int SA_FETCH_EN        : 1;
    unsigned int SEC_CODE           : 8;
    volatile unsigned int DESC_EN   : 1;
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
    
    
/* Direction */
#define PIC32_ENCRYPTION        0b1
#define PIC32_DECRYPTION        0b0

/* Algorithm */
#define PIC32_ALGO_HMAC1        0b01000000
#define PIC32_ALGO_SHA256       0b00100000
#define PIC32_ALGO_SHA1         0b00010000
#define PIC32_ALGO_MD5          0b00001000
#define PIC32_ALGO_AES          0b00000100
#define PIC32_ALGO_TDES         0b00000010
#define PIC32_ALGO_DES          0b00000001

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
#define PIC32_MAX_MEMORY_LIMIT      (8*1024)
#define PIC32_BLOCKSIZE_HASH        64
#define PIC32_BLOCKSIZE_HMAC        PIC32_BLOCKSIZE_HASH
#define PIC32_BLOCKSIZE_MD5         PIC32_BLOCKSIZE_HASH
#define PIC32_BLOCKSIZE_SHA1        PIC32_BLOCKSIZE_HASH
#define PIC32_BLOCKSIZE_SHA256      PIC32_BLOCKSIZE_HASH
#define PIC32_BLOCKSIZE_AES         16
#define PIC32_BLOCKSIZE_TDES        24
#define PIC32_BLOCKSIZE_DES         8
#define PIC32_DIGEST_SIZE           32

/* Helper Macros */
#define PIC32MZ_IF_RAM(addr) (KVA_TO_PA(addr) < 0x1D000000)

/* If EF part then Crypto engine supports swapping output bytes */
#define PIC32_NO_OUT_SWAP    ((__PIC32_FEATURE_SET0 == 'E') && (__PIC32_FEATURE_SET1 == 'C'))

int Pic32Crypto(const uint8_t * in, uint32_t inLen, uint32_t* out, uint32_t outLen, 
        uint32_t dir, uint32_t algo, uint32_t cryptoalgo,
        uint32_t * key, uint32_t keyLen, uint32_t * iv, uint32_t ivLen); 

typedef struct {
    uint8_t * data;
    size_t size;    
} hash_cache_t;

void cacheUpdate(hash_cache_t * cache, const uint8_t * src, size_t srcSize);

#ifdef	__cplusplus
}
#endif

#endif	/* PIC32_CRYPTO_H */

