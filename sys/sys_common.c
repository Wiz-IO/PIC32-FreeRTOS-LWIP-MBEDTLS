/*
 *  Created on: 30.08.2018
 *      Author: Georgi Angelov
 */

#include "sys_common.h"

unsigned char spi_calutate_brg(unsigned int pb_clk, unsigned int spi_clk) {
    unsigned int brg;
    brg = pb_clk / (2 * spi_clk);
    if (pb_clk % (2 * spi_clk))
        brg++;
    if (brg > 0x100)
        brg = 0x100;
    if (brg)
        brg--;
    return (unsigned char) brg;
}

void ByteToHexStr(unsigned char * source, char * dest, int sourceLen) {
    if (!source || !dest || !sourceLen)
        return;
    memset(dest, 0, sourceLen * 2 + 1);
    short i;
    unsigned char highByte, lowByte;
    for (i = 0; i < sourceLen; i++) {
        highByte = source[i] >> 4;
        lowByte = source[i] & 0x0f;
        highByte += 0x30;
        if (highByte > 0x39)
            dest[i * 2] = highByte + 0x07;
        else
            dest[i * 2] = highByte;
        lowByte += 0x30;
        if (lowByte > 0x39)
            dest[i * 2 + 1] = lowByte + 0x07;
        else
            dest[i * 2 + 1] = lowByte;
    }
}

/** returns 1 if line starts with prefix, 0 if it does not */
int strStartsWith(const char *line, const char *prefix) {
    for (; *line != '\0' && *prefix != '\0'; line++, prefix++) {
        if (*line != *prefix) {
            return 0;
        }
    }
    return *prefix == '\0';
}

int strncasecmp(const char *s1, const char *s2, size_t n) {
    int CompareVal;
    if (!s1 || !s2) return -1;
    if (n != 0) {
        do {
            CompareVal = tolower(*s1) - tolower(*s2);
            if (CompareVal != 0) {
                return (CompareVal);
            }
            ++s1;
            ++s2;
            if (*s1 == '\0') {
                break;
            }
        } while (--n != 0);
    }
    return (0);
}

