/*
 *  Created on: 30.08.2018
 *      Author: Georgi Angelov
 */

#include "sys.h"
#include "osal.h"
#include "mrf.h"
#include "httpclient.h"

/* HTTP Client is blocked */

#define RES_BUF_SIZE    1024
static char response[RES_BUF_SIZE], header[RES_BUF_SIZE];

#define URL_COUNT 4
char * url[URL_COUNT] = {
    "http://www.wizio.eu/test.php",
    "https://raw.githubusercontent.com/Wiz-IO/LIB/master/test_https",    
    "https://os.mbed.com/media/uploads/mbed_official/hello.txt",
    "https://tlstest.paypal.com/",
};

void entryHTTP(void * arg) {
    (void) arg;
    LOG("[HTTP] BEGIN\n");
    WIFI_waitReady();
    static uint32_t index = 0;
    uint32_t startTime, elapsed;
    httpclient_t client = {0};
    httpclient_data_t client_data = {0};
START:
    startTime = xTaskGetTickCount();
    LOG("\n[HTTP] GET: %s\n", url[index % URL_COUNT]);
    memset(response, 0, sizeof (response));
    memset(header, 0, sizeof (header));
    memset(&client, 0, sizeof (httpclient_t));
    memset(&client_data, 0, sizeof (httpclient_data_t));
    client_data.header_buf = header;
    client_data.header_buf_len = RES_BUF_SIZE;
    client_data.response_buf = response;
    client_data.response_buf_len = RES_BUF_SIZE;
    httpclient_get(&client, url[index % URL_COUNT], &client_data);
    elapsed = ElapsedTime(startTime, xTaskGetTickCount()) * portTICK_PERIOD_MS;
    LOG("[HTTP] Elapsed: %u mSec\n", elapsed);
    LOG("[HTTP] Header: %s\n", client_data.header_buf);
    LOG("\n[HTTP] Receive: %s\n", client_data.response_buf);
    
    index++;
    delay_ms(30 * 1000);    
    goto START;
}
