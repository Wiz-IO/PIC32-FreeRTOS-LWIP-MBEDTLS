/* 
 * File:   mrf.h
 * Author: Georgi Angelov
 *
 * Created on 28.08.2018 10:09
 */

#ifndef MRF_H
#define	MRF_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "sys.h"
#include "mrf_hal.h"
#include "mrf_osal.h"
#include "mrf_lib.h"

#define ETH_HEADER_SIZE                         14
#define MAX_IP_PACKET_SIZE                      1564 /* including header ??? */
#define MRF_MAX_PACKET_SIZE                     1518
#define MAX_MULTICAST_FILTER_SIZE               16

/* for INFRASTRUCTURE  */    
//#define WDRV_DEFAULT_SSID                       "Comet Guest Room"    
//#define WDRV_DEFAULT_SSID                       "THE WIZARD"
    
//define WDRV_DEFAULT_SSID                       "WizIO PIC32MZ" /* for AP */   
#define WDRV_DEFAULT_CHANNEL                    5   
#define WDRV_MAX_CLIENT_TABLE_SLOTS             2
#define WDRV_SECURITY_OPEN                      0
#define WDRV_SECURITY_WEP_40                    1
#define WDRV_SECURITY_WEP_104                   2
#define WDRV_SECURITY_WPA_WITH_PASS_PHRASE      3
#define WDRV_SECURITY_WPA2_WITH_PASS_PHRASE     4
#define WDRV_SECURITY_WPS_PUSH_BUTTON           6    
#define WDRV_SECURITY_WPS_PIN                   7
#define WDRV_NETWORK_TYPE_INFRASTRUCTURE        1
#define WDRV_NETWORK_TYPE_ADHOC                 2 
#define WDRV_NETWORK_TYPE_P2P                   3 
#define WDRV_NETWORK_TYPE_SOFT_AP               4
#define WDRV_DEFAULT_NETWORK_TYPE               WDRV_NETWORK_TYPE_INFRASTRUCTURE /* <------  */    
    
#define WDRV_BSSID_LENGTH                       6
#define WDRV_MAX_SSID_LENGTH                    32
#define WDRV_MAX_SECURITY_KEY_LENGTH            64
#define WDRV_DEFAULT_SECURITY_MODE              WDRV_SECURITY_OPEN
#define WDRV_DEFAULT_WEP_KEYS_40                "5AFB6C8E77" // default WEP40 key
#define WDRV_DEFAULT_WEP_KEYS_104               "90E96780C739409DA50034FCAA" // default WEP104 key
#define WDRV_DEFAULT_PSK_PHRASE                 "password" // default WPA-PSK or WPA2-PSK passphrase
#define WDRV_DEFAULT_WPS_PIN                    "12345678" // default WPS PIN


typedef struct {
    uint8_t addr[6];
    uint32_t timeStamp;
} MAC_ADDR;

typedef struct __attribute__((__packed__)) {
    uint8_t v[6];
} TCPIP_MAC_ADDR;

typedef struct {
    MAC_ADDR mac[WDRV_MAX_CLIENT_TABLE_SLOTS];
    uint16_t bitMap;
    uint32_t seqNum;
    uint16_t updated;
} WDRV_CLIENT_CACHE;

typedef struct {
    uint8_t macAddr[6];
    bool isDriverOpen;
    bool updateMacAddressRequired;
    bool isScanDone;
    bool initConn;
    bool isConnReestablished;
    bool isDisconnectRequested;
    OSAL_SEM_HANDLE_TYPE disconnectDoneSync;
    OSAL_SEM_HANDLE_TYPE dmaTxSync;
    OSAL_SEM_HANDLE_TYPE dmaRxSync;
    OSAL_MUTEX_HANDLE_TYPE * debugConsoleLock;
    WDRV_CLIENT_CACHE clientCache;
} WDRV_MRF24WN_PRIV;
extern WDRV_MRF24WN_PRIV g_wdrv_priv;

typedef struct {
    void (*CopyFrameToStackPacketBuffer_CB)(uint32_t len, uint8_t const *const frame);
    void (*ProceedConnectEvent_CB)(uint32_t connected, uint8_t devID, uint8_t *bssid, bool bssConn, uint8_t reason);
    void (*RFReady_CB)(uint8_t const *const addr);
    void (*ScanDone_CB)(uint32_t status);
    void (*InitDone_CB)(void);
    void (*WPSDone_CB)(void);
} WDRV_CALLBACKS;

typedef struct __attribute__((__packed__)) {
    uint32_t verifyFlag; // 0x00000000: empty; 0xffffffff: empty; 0x5a5a5a5a: verified.
    uint8_t networkType;
    uint8_t ssid[WDRV_MAX_SSID_LENGTH];
    uint8_t ssidLen;
    uint8_t securityMode; // WDRV_SECURITY_OPEN or one of the other security modes
    uint8_t securityKey[WDRV_MAX_SECURITY_KEY_LENGTH]; // Wi-Fi security key, or passphrase
    uint8_t securityKeyLen; // number of bytes in security key (can be 0)
} WDRV_CONFIG_DATA;
extern WDRV_CONFIG_DATA * p_wdrv_configData;
#define WDRV_CONFIG_PARAMS(params) p_wdrv_configData->params

typedef struct {
    /* Network BSSID value */
    uint8_t      bssid[WDRV_BSSID_LENGTH];
    /*  Network SSID value */
    uint8_t      ssid[WDRV_MAX_SSID_LENGTH];
    /* Access Point configuration (see description) */
    uint8_t      apConfig;
    /* not used */
    uint8_t      reserved;
    /* Network beacon interval */
    uint16_t     beaconPeriod;
    /* Only valid if bssType = WDRV_NETWORK_TYPE_INFRASTRUCTURE */
    uint16_t     atimWindow;
    /*
      List of Network basic rates.  Each rate has the following format:

          Bit 7
      * 0: rate is not part of the basic rates set
      * 1: rate is part of the basic rates set

          Bits 6:0
      Multiple of 500kbps giving the supported rate.  For example, a value of 2
      (2 * 500kbps) indicates that 1mbps is a supported rate.  A value of 4 in
      this field indicates a 2mbps rate (4 * 500kbps).
      */
    uint8_t      basicRateSet[8];
    uint8_t      extRateSet[4];
    /* Signal strength of received frame beacon or probe response.  Will range
       from a low of 43 to a high of 128. */
    uint8_t      rssi;
    /* Number of valid rates in basicRates */
    uint8_t      numRates;
    /* Part of TIM element */
    uint8_t      dtimPeriod;
    /* WDRV_NETWORK_TYPE_INFRASTRUCTURE or WDRV_NETWORK_TYPE_ADHOC */
    uint8_t      bssType;
    /* Channel number */
    uint8_t      channel;
    /* Number of valid characters in SSID */
    uint8_t      ssidLen;
} WDRV_SCAN_RESULT;

typedef struct {
    uint8_t scanState;
    uint16_t numberOfResults;
    uint16_t displayIdx;
} WDRV_SCAN_STATUS;
extern WDRV_SCAN_STATUS g_wdrv_scanStatus;
    
//typedef void (*GPIO_OUTLOW_T)(uint32_t channel, uint32_t bit_pos);
//typedef void (*GPIO_OUTHIGH_T)(uint32_t channel, uint32_t bit_pos);

#include "lwip/opt.h"
#include "lwip/def.h"
#include "lwip/mem.h"
#include "lwip/pbuf.h"
#include "lwip/inet.h"
#include "lwip/dhcp.h"
#include "lwip/prot/dhcp.h"
#include "netif/etharp.h"

extern struct netif wlan;
void WIFI_Start(const char * str_ip, const char * str_gw, const char * str_mask);
void WIFI_waitReady(void);

#include "mrf_api.h"

#ifdef	__cplusplus
}
#endif

#endif	/* MRF_H */

