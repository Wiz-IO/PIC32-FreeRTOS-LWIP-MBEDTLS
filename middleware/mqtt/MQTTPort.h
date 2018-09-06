#ifndef __MQTT_PORT__
#define __MQTT_PORT__

#include "sys.h"

#ifdef MQTT_SSL
#include "mbedtls/compat-1.3.h"
#include "mbedtls/net.h"
#include "mbedtls/ssl.h"
#include "mbedtls/certs.h"
#endif

typedef struct Network Network;

/**
 * @addtogroup MQTT
 * @{
 * Open source MQTT client implementation is part of Paho project aimed at new, existing, and emerging applications for Machine‑to‑Machine (M2M) and Internet of Things (IoT). For more details, please refer to <a href="http://www.eclipse.org/paho"> Paho project </a>.
 * In this release, MediaTek has integrated Paho MQTT protocol with mbed TLS and lwIP. New APIs related to the network connectivity are also introduced in this section.
 * The MQTT add-on APIs follow the original Paho project coding style.
 * A reference example can be found under /project/mt7687_hdk/apps/mqtt_client folder.
 *
 * Terms and Acronyms
 * ======
 * |Terms                         |Details                                                                 |
 * |------------------------------|------------------------------------------------------------------------|
 * |\b MQTT                       | MQ Telemetry Transport. For more details, please refer to <a href="https://en.wikipedia.org/wiki/MQTT">wikipedia MQTT</a>. |
 * |\b TLS                        | Transport Layer Security. |
 * |\b lwIP                       | Lightweight IP is a widely used open source TCP/IP stack designed for embedded systems. |
 * |\b Wi-Fi                      | Wi-Fi is a local area wireless computer networking technology. For more details, please refer to <a href="https://en.wikipedia.org/wiki/Wi-Fi">wikipedia Wi-Fi</a>. |
 *
 */

/** @defgroup mqtt_struct Struct
  * @{
  */

/**
 * @brief The structure of MQTT network connection used in the MQTT library. The user has to allocate memory for this structure.
 */
struct Network {
    int my_socket;                                                /**< Connect the socket handle. */
    int (*mqttread)(Network *, unsigned char *, int, int);        /**< Read data from server function pointer. */
    int (*mqttwrite)(Network *, unsigned char *, int, int);       /**< Send data to server function pointer. */
    void (*disconnect)(Network *);    /**< Disconnect the network function pointer. */
#ifdef MQTT_SSL
    mbedtls_ssl_context ssl;          /**< mbed TLS control context. */
    mbedtls_net_context fd;           /**< mbed TLS network context. */
    mbedtls_ssl_config conf;          /**< mbed TLS configuration context. */
    mbedtls_x509_crt cacertl;         /**< mbed TLS CA certification. */
    mbedtls_x509_crt clicert;         /**< mbed TLS Client certification. */
    mbedtls_pk_context pkey;          /**< mbed TLS Client key. */
#endif
};

/**
 * @}
 */

/**
 * @brief This function initializes the network structure.
 * @param[in] n is the network structure pointer. The user is responsible to allocate memory before calling this function. Call this function before #ConnectNetwork() and #TLSConnectNetwork().
 * @sa #ConnectNetwork();
 * @return None
 */
void NewNetwork(Network *n);


/**
 * @brief This function connects to the MQTT server without TLS, and returns a value that indicates whether the connection is created successfully or not. Call #NewNetwork() to initialize network structure before calling this function.
 * @param[in] n is a pointer to the network structure.
 * @param[in] addr is the server hostname or IP address.
 * @param[in] port is the server port.
 * @sa #NewNetwork();
 * @return If the return value is 0, the connection is created successfully. If the return value is -1, then calling lwIP #socket() has failed. If the return value is -2, then calling lwIP #connect() has failed. Any other value indicates that calling lwIP #getaddrinfo() has failed.
 */
int ConnectNetwork(Network *n, char *addr,  char *port);


/**
 * @brief This function connects to a MQTT server with TLS, and returns a value that indicates whether the connection is create successfully or not. Call #NewNetwork() to initialize network structure before calling this function.
 * @param[in] n is the the network structure pointer.
 * @param[in] addr is the Server Host name or IP address.
 * @param[in] port is the Server Port.
 * @param[in] ca_crt is the Server's CA certification.
 * @param[in] ca_crt_len is the length of Server's CA certification.
 * @param[in] client_crt is the client certification.
 * @param[in] client_crt_len is the length of client certification.
 * @param[in] client_key is the client key.
 * @param[in] client_key_len is the length of client key.
 * @param[in] client_pwd is the password of client key.
 * @param[in] client_pwd_len is the length of client key's password.
 * @sa #NewNetwork();
 * @return If the return value is 0, the connection is created successfully. If the return value is -1, then calling lwIP #socket() has failed. If the return value is -2, then calling lwIP #connect() has failed. Any other value indicates that calling lwIP #getaddrinfo() has failed.
 */
int TLSConnectNetwork(Network *n, const char *addr, const char *port,
                      const char *ca_crt, size_t ca_crt_len,
                      const char *client_crt,    size_t client_crt_len,
                      const char *client_key,    size_t client_key_len,
                      const char *client_pwd, size_t client_pwd_len);


/**
 * @}
 */


/* The following content is used inside the MQTT module. */
typedef struct Timer Timer;
struct Timer {
    unsigned int systick_period;
    unsigned int end_time;
};

char expired(Timer *timer);
void countdown_ms(Timer *timer, unsigned int timeout);
void countdown(Timer *timer, unsigned int timeout);
unsigned int left_ms(Timer *timer);
void InitTimer(Timer *timer);

/** Define 0 to disable logging, define 1 to enable logging. */
#ifndef MTK_DEBUG_LEVEL_NONE
#define MTK_MQTT_DEBUG 1
#else
#define MTK_MQTT_DEBUG 0
#endif

#if MTK_MQTT_DEBUG
#define MQTT_DBG(fmt,arg...)  TRACE("[MQTT-D]: "fmt,##arg)
#define MQTT_WARN(fmt,arg...) TRACE("[MQTT-W]: "fmt,##arg)
#define MQTT_ERR(fmt,arg...)  TRACE("[MQTT-E]: "fmt,##arg)
#else
#define MQTT_DBG(x, ...)
#define MQTT_WARN(x, ...)
#define MQTT_ERR(x, ...)
#endif

#endif /* __MQTT_PORT__ */
