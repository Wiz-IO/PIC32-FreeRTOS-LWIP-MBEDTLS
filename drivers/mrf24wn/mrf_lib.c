/*
 *  Created on: 30.08.2018
 *      Author: Georgi Angelov
 */

#include "mrf.h"

/* Used from static LIB */
WDRV_MRF24WN_PRIV g_wdrv_priv = {
    .initConn = true,
    .isDisconnectRequested = true
};
WDRV_SCAN_STATUS g_wdrv_scanStatus;

static WDRV_CONFIG_DATA s_wdrv_configData;
WDRV_CONFIG_DATA *p_wdrv_configData = &s_wdrv_configData;

static TCPIP_MAC_ADDR s_MulticastFilter[MAX_MULTICAST_FILTER_SIZE];

/* LIB */
void wc_ErrorString(int error, char * buffer) {
    LOG("[MRF] wc_ErrorString( %d )\n", error);
    sprintf(buffer, "[MRF] ERROR %d", error);
}

/* LIB */
void WDRV_Assert(int condition, const char * msg, const char * file, int line) {
    if (!condition) {
        portDISABLE_INTERRUPTS();
        if (*msg)
            LOG("\n[MRF] Driver ASSERTS: %s\n%s, line %u\n", msg, file, line);
        else
            LOG("\n[MRF] Driver ASSERTS:\n%s, line %u\n", file, line);
        while(1);
    }
}

static void netModeSet(uint8_t networkType) {
    switch (networkType) {
        case WDRV_NETWORK_TYPE_INFRASTRUCTURE:
            WDRV_EXT_CmdNetModeBSSSet();
            break;
        case WDRV_NETWORK_TYPE_ADHOC:
            WDRV_ASSERT(false, "[MRF] Ad-Hoc is not supported for now");
            break;
        case WDRV_NETWORK_TYPE_SOFT_AP:
            WDRV_EXT_CmdNetModeAPSet();
            break;
        case WDRV_NETWORK_TYPE_P2P:
            WDRV_ASSERT(false, "[MRF] P2P is not supported for now");
            break;
        default:
            WDRV_ASSERT(false, "[MRF] Undefined network type");
            break;
    }
}

static void securitySet(uint8_t securityMode) {
    bool pinMode;
    switch (securityMode) {
        case WDRV_SECURITY_OPEN:
            WDRV_EXT_CmdSecNoneSet();
            break;
        case WDRV_SECURITY_WEP_40:
        case WDRV_SECURITY_WEP_104:
            if ((WDRV_CONFIG_PARAMS(securityKeyLen) == 5) || (WDRV_CONFIG_PARAMS(securityKeyLen) == 13)) {
                // coverting security key to ASCII code
                uint8_t i, originalKeyChar;
                uint8_t asciiKey[26];
                for (i = 0; i < WDRV_CONFIG_PARAMS(securityKeyLen) * 2; ++i) {
                    originalKeyChar = (i % 2 == 0) ? (WDRV_CONFIG_PARAMS(securityKey)[i / 2] >> 4) : (WDRV_CONFIG_PARAMS(securityKey)[i / 2] & 0x0F);
                    asciiKey[i] = (originalKeyChar > 9) ? ('A' + originalKeyChar - 0x0A) : ('0' + originalKeyChar - 0x00);
                }
                WDRV_CONFIG_PARAMS(securityKeyLen) *= 2;
                memcpy(WDRV_CONFIG_PARAMS(securityKey), asciiKey, WDRV_CONFIG_PARAMS(securityKeyLen));
                WDRV_CONFIG_PARAMS(securityKey)[WDRV_CONFIG_PARAMS(securityKeyLen)] = 0x00;
            }
            WDRV_EXT_CmdSecWEPSet(WDRV_CONFIG_PARAMS(securityKey), WDRV_CONFIG_PARAMS(securityKeyLen));
            break;
        case WDRV_SECURITY_WPA_WITH_PASS_PHRASE:
            WDRV_EXT_CmdSecWPASet(WDRV_CONFIG_PARAMS(securityKey), WDRV_CONFIG_PARAMS(securityKeyLen));
            break;
        case WDRV_SECURITY_WPA2_WITH_PASS_PHRASE:
            WDRV_EXT_CmdSecWPA2Set(WDRV_CONFIG_PARAMS(securityKey), WDRV_CONFIG_PARAMS(securityKeyLen));
            break;
        case WDRV_SECURITY_WPS_PIN:
        case WDRV_SECURITY_WPS_PUSH_BUTTON:
            pinMode = WDRV_CONFIG_PARAMS(securityMode) == WDRV_SECURITY_WPS_PIN ? true : false;
            WDRV_EXT_CmdSecWpsSet(pinMode, WDRV_CONFIG_PARAMS(securityKey), WDRV_CONFIG_PARAMS(securityKeyLen));
            break;
        default:
            WDRV_ASSERT(false, "[MRF] Undefined security mode");
            break;
    }
}

void WDRV_Config(void) {
    memcpy(WDRV_CONFIG_PARAMS(ssid), (const void *) WDRV_DEFAULT_SSID, sizeof (WDRV_DEFAULT_SSID));
    WDRV_CONFIG_PARAMS(ssidLen) = sizeof (WDRV_DEFAULT_SSID) - 1;
    WDRV_CONFIG_PARAMS(networkType) = WDRV_DEFAULT_NETWORK_TYPE;
    WDRV_CONFIG_PARAMS(securityMode) = WDRV_DEFAULT_SECURITY_MODE;
    switch (WDRV_CONFIG_PARAMS(securityMode)) {
        case WDRV_SECURITY_OPEN:
            memset(WDRV_CONFIG_PARAMS(securityKey), 0x00, sizeof (WDRV_CONFIG_PARAMS(securityKey)));
            WDRV_CONFIG_PARAMS(securityKeyLen) = 0;
            break;
        case WDRV_SECURITY_WEP_40:
            memcpy(WDRV_CONFIG_PARAMS(securityKey), (const void *) WDRV_DEFAULT_WEP_KEYS_40, sizeof (WDRV_DEFAULT_WEP_KEYS_40) - 1);
            WDRV_CONFIG_PARAMS(securityKeyLen) = sizeof (WDRV_DEFAULT_WEP_KEYS_40) - 1;
            break;
        case WDRV_SECURITY_WEP_104:
            memcpy(WDRV_CONFIG_PARAMS(securityKey), (const void *) WDRV_DEFAULT_WEP_KEYS_104, sizeof (WDRV_DEFAULT_WEP_KEYS_104) - 1);
            WDRV_CONFIG_PARAMS(securityKeyLen) = sizeof (WDRV_DEFAULT_WEP_KEYS_104) - 1;
            break;
        case WDRV_SECURITY_WPA_WITH_PASS_PHRASE:
        case WDRV_SECURITY_WPA2_WITH_PASS_PHRASE:
            memcpy(WDRV_CONFIG_PARAMS(securityKey), (const void *) WDRV_DEFAULT_PSK_PHRASE, sizeof (WDRV_DEFAULT_PSK_PHRASE) - 1);
            WDRV_CONFIG_PARAMS(securityKeyLen) = sizeof (WDRV_DEFAULT_PSK_PHRASE) - 1;
            break;
        case WDRV_SECURITY_WPS_PUSH_BUTTON:
            memset(WDRV_CONFIG_PARAMS(securityKey), 0x00, sizeof (WDRV_CONFIG_PARAMS(securityKey)));
            WDRV_CONFIG_PARAMS(securityKeyLen) = 0;
            break;
        case WDRV_SECURITY_WPS_PIN:
            memcpy(WDRV_CONFIG_PARAMS(securityKey), (const void *) WDRV_DEFAULT_WPS_PIN, sizeof (WDRV_DEFAULT_WPS_PIN));
            WDRV_CONFIG_PARAMS(securityKeyLen) = sizeof (WDRV_DEFAULT_WPS_PIN);
            break;
        default:
            LOG("[MRF] Unsupported security mode\n");
            break;
    }
}

static bool isBroadcastPacket(const uint8_t *addr) {
    int i;
    for (i = 0; i < 6; i++) {
        if (addr[i] != 0xff)
            return false;
    }
    return true;
}

static bool isMulticastPacket(uint8_t const *const frame) {
    if (((frame[0] & 0x01) == 0x01) && (!isBroadcastPacket(&frame[0])))
        return true;
    else
        return false;
}

static bool isMulticastAddrSet(const TCPIP_MAC_ADDR *addr) {
    int i;
    for (i = 0; i < MAX_MULTICAST_FILTER_SIZE; i++) {
        if (memcmp(addr, &s_MulticastFilter[i], 6) == 0)
            return true;
    }
    return false;
}

static bool isSolicitedMulticastPacket(uint8_t const *const frame) {
    return isMulticastAddrSet((TCPIP_MAC_ADDR *) frame);
}

bool WDRV_isPacketValid(uint8_t const *const frame) {
    if (isMulticastPacket(frame)) {
        if (isSolicitedMulticastPacket(frame))
            return true;
        else
            return false;
    } else {
        return true;
    }
    return false;
}

void MRF_ClientCacheUpdate(bool connected, uint8_t *mac) {
    int i;
    int idx = 0;
    if (connected) {
        /* Check if the MAC address is already in the table. If so, we just update timestamp and return. */
        if (g_wdrv_priv.clientCache.bitMap) {
            for (i = 0; i < WDRV_MAX_CLIENT_TABLE_SLOTS; ++i) {
                if (g_wdrv_priv.clientCache.bitMap & 1 << i) {
                    if (!memcmp(g_wdrv_priv.clientCache.mac[i].addr, mac, 6)) {
                        g_wdrv_priv.clientCache.mac[i].timeStamp = g_wdrv_priv.clientCache.seqNum++;
                        return;
                    }
                }
            }
        }
        /* Try to find an empty slot in the table. */
        for (i = 0; i < WDRV_MAX_CLIENT_TABLE_SLOTS; ++i) {
            if (!(g_wdrv_priv.clientCache.bitMap & 1 << i)) {
                idx = i;
                g_wdrv_priv.clientCache.bitMap |= 1 << idx;
                g_wdrv_priv.clientCache.updated |= 1 << idx;
                memcpy(g_wdrv_priv.clientCache.mac[idx].addr, mac, 6);
                g_wdrv_priv.clientCache.mac[idx].timeStamp = g_wdrv_priv.clientCache.seqNum++;
                return;
            }
        }
        /* Cache table is full. Let's kick out the oldest. */
        for (i = 0; i < WDRV_MAX_CLIENT_TABLE_SLOTS; ++i) {
            uint32_t min = 0;
            if (g_wdrv_priv.clientCache.mac[i].timeStamp >= min) {
                min = g_wdrv_priv.clientCache.mac[i].timeStamp;
                idx = i;
            }
        }
        g_wdrv_priv.clientCache.bitMap |= 1 << idx;
        g_wdrv_priv.clientCache.updated |= 1 << idx;
        memcpy(g_wdrv_priv.clientCache.mac[idx].addr, mac, 6);
        g_wdrv_priv.clientCache.mac[idx].timeStamp = g_wdrv_priv.clientCache.seqNum++;
        return;
    } else {
        /* If the MAC address is in the table, update its status to unconnected. */
        for (i = 0; i < WDRV_MAX_CLIENT_TABLE_SLOTS; ++i) {
            if (g_wdrv_priv.clientCache.bitMap & 1 << i) {
                if (!memcmp(mac, g_wdrv_priv.clientCache.mac[i].addr, 6)) {
                    g_wdrv_priv.clientCache.bitMap &= ~(1 << i);
                    g_wdrv_priv.clientCache.updated |= 1 << i;
                    return;
                }
            }
        }
    }
}

void WDRV_Connect(void) {
    netModeSet(WDRV_CONFIG_PARAMS(networkType));
    if (WDRV_CONFIG_PARAMS(networkType) == WDRV_NETWORK_TYPE_SOFT_AP)
        WDRV_EXT_CmdChannelSet(WDRV_DEFAULT_CHANNEL);
    WDRV_EXT_CmdSSIDSet(WDRV_CONFIG_PARAMS(ssid), WDRV_CONFIG_PARAMS(ssidLen));
    securitySet(WDRV_CONFIG_PARAMS(securityMode));
    WDRV_EXT_CmdPowerSavePut(false);
    if ((WDRV_CONFIG_PARAMS(securityMode) != WDRV_SECURITY_WPS_PIN) &&
            (WDRV_CONFIG_PARAMS(securityMode) != WDRV_SECURITY_WPS_PUSH_BUTTON)) {
        LOG("[MRF] WIFI Connecting . . .\n");
        WDRV_EXT_CmdConnect();
    }
}