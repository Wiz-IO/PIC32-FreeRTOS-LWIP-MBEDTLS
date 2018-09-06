#include <stdint.h>
#include <stdio.h>

#include "lwip/opt.h"
#include "lwip/netif.h"
#include "lwip/tcpip.h"
#include "lwip/sys.h"
#include "lwip/netdb.h"

#if LWIP_SOCKET
#include "lwip/sockets.h"
#endif

#ifdef MQTT_SSL
#include "mbedtls/debug.h"
#endif

#include "MQTTPort.h"

int mqtt_read(Network *n, unsigned char *buffer, int len, int timeout_ms);
int mqtt_write(Network *n, unsigned char *buffer, int len, int timeout_ms);
void mqtt_disconnect(Network *n);

static unsigned int mqtt_current_time_ms(void) {
    unsigned int current_ms = 0;
//TODO
    return current_ms;
}

char expired(Timer *timer) {
    unsigned int cur_time = 0;
    cur_time = mqtt_current_time_ms();
    if (timer->end_time < cur_time || timer->end_time == cur_time) {
        MQTT_DBG("MQTT expired enter");
        return 1;
    } else {
        MQTT_DBG("MQTT not expired");
        return 0;
    }
}

void countdown_ms(Timer *timer, unsigned int timeout) {
    timer->end_time = mqtt_current_time_ms() + timeout;
}

void countdown(Timer *timer, unsigned int timeout) {
    timer->end_time = mqtt_current_time_ms() + (timeout * 1000);
}

unsigned int left_ms(Timer *timer) {
    unsigned int cur_time = 0;
    cur_time = mqtt_current_time_ms();
    if (timer->end_time < cur_time || timer->end_time == cur_time) {
        return 0;
    } else {
        return timer->end_time - cur_time;
    }
}

void InitTimer(Timer *timer) {
    timer->end_time = 0;
}

int mqtt_read(Network *n, unsigned char *buffer, int len, int timeout_ms) {
    int rc = 0;
    int recvlen = 0;
    int ret = -1;
    fd_set fdset;
    struct timeval tv;

    FD_ZERO(&fdset);
    FD_SET(n->my_socket, &fdset);


    tv.tv_sec = timeout_ms / 1000;
    tv.tv_usec = (timeout_ms % 1000) * 1000;
    ret = select(n->my_socket + 1, &fdset, NULL, NULL, &tv);
    MQTT_DBG("mqtt read timer=%d ms", timeout_ms);
    if (ret < 0) {
        MQTT_DBG("mqtt read(select) fail ret=%d", ret);
        return -1;
    } else if (ret == 0) {
        MQTT_DBG("mqtt read(select) timeout");
        return -2;
    } else if (ret == 1) {
        do {
            MQTT_DBG("mqtt read recv len = %d, recvlen = %d", len, recvlen);
            rc = recv(n->my_socket, buffer + recvlen, len - recvlen, 0);
            if (rc > 0) {
                recvlen += rc;
                MQTT_DBG("mqtt read ret=%d, rc = %d, recvlen = %d", ret, rc, recvlen);
            } else {
                MQTT_DBG("mqtt read fail: ret=%d, rc = %d, recvlen = %d", ret, rc, recvlen);
                return -3;
            }
        } while (recvlen < len);
    }
    return recvlen;
}

int mqtt_write(Network *n, unsigned char *buffer, int len, int timeout_ms) {
    int rc = 0;
    int ret = -1;
    fd_set fdset;
    struct timeval tv;

    FD_ZERO(&fdset);
    FD_SET(n->my_socket, &fdset);


    tv.tv_sec = timeout_ms / 1000;
    tv.tv_usec = (timeout_ms % 1000) * 1000;
    MQTT_DBG("mqtt write timer=%d ms", timeout_ms);
    ret = select(n->my_socket + 1, NULL, &fdset, NULL, &tv);

    if (ret < 0) {
        MQTT_DBG("mqtt write fail");
        return -1;
    } else if (ret == 0) {
        MQTT_DBG("mqtt write timeout");
        return -2;
    } else if (ret == 1) {
        rc = write(n->my_socket, buffer, len);
    }
    return rc;

}

void mqtt_disconnect(Network *n) {
    close(n->my_socket);
}

void NewNetwork(Network *n) {
    n->my_socket = -1;
    n->mqttread = mqtt_read;
    n->mqttwrite = mqtt_write;
    n->disconnect = mqtt_disconnect;
}

//tcp client

int ConnectNetwork(Network *n, char *addr, char *port) {
    int type = SOCK_STREAM;
    struct sockaddr_in address;
    int rc = -1;
    sa_family_t family = AF_INET;
    struct addrinfo *result = NULL;
    struct addrinfo hints = {0, AF_UNSPEC, SOCK_STREAM, IPPROTO_TCP, 0, NULL, NULL, NULL};

    if ((rc = getaddrinfo(addr, NULL, &hints, &result)) == 0) {
        struct addrinfo *res = result;

        /* prefer ip4 addresses */
        while (res) {
            if (res->ai_family == AF_INET) {
                result = res;
                break;
            }
            res = res->ai_next;
        }

        if (result->ai_family == AF_INET) {
            address.sin_port = htons(atoi(port));
            address.sin_family = family = AF_INET;
            address.sin_addr = ((struct sockaddr_in *) (result->ai_addr))->sin_addr;
#if MQTT_DEBUG
            int a = 0, b = 0, c = 0, d = 0;
            unsigned int temp = 0;

            temp = address.sin_addr.s_addr;
            a = temp & 0x000000FF;
            b = (temp >> 8) & 0x000000FF;
            c = (temp >> 16) & 0x000000FF;
            d = (temp >> 24) & 0x000000FF;
            MQTT_DBG("mqtt connect find addrinfo:%d.%d.%d.%d", a, b, c, d);
#endif
        } else {
            rc = -1;
        }
        freeaddrinfo(result);
    }
#if 0
    int ret;
    struct sockaddr_in addr_s;

    memset(&addr_s, 0, sizeof (addr_s));
    addr_s.sin_len = sizeof (addr_s);
    addr_s.sin_family = AF_INET;
    addr_s.sin_port = PP_HTONS(atoi(port));
    addr_s.sin_addr.s_addr = inet_addr(addr);

    /* create client socket */
    n->my_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (n->my_socket < 0) {
        MQTT_DBG("mqtt client create fail\n");
        return -1;
    }
#endif
    /* create client socket */
    if (rc == 0) {
        int opval = 1;
        n->my_socket = socket(family, type, 0);
        if (n->my_socket < 0) {
            MQTT_DBG("mqtt socket create fail");
            return -1;
        }
        /* connect remote servers*/
        rc = connect(n->my_socket, (struct sockaddr *) &address, sizeof (address));

        if (rc < 0) {
            close(n->my_socket);
            MQTT_DBG("mqtt socket connect fail:rc=%d,socket = %d", rc, n->my_socket);
            return -2;
        }

        setsockopt(n->my_socket, IPPROTO_TCP, TCP_NODELAY, &opval, sizeof (opval));
    }

    return rc;
}

