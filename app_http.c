#include "sys.h"
#include "osal.h"
#include "mrf.h"
#include "httpclient.h"

#define RES_BUF_SIZE    1024

void entryHTTP(void * arg) {
    (void) arg;
    TRACE("[APP] - HTTP TEST -\n");  
    wifi_config(0, 0, 0);
    wifi_begin(1);
    TRACE("[APP] WIFI READY\n");      
    
    char * url = "http://www.wizio.eu/test.php";
    httpclient_t client = {0};
    httpclient_data_t client_data = {0};
    char * buf = (char *) pvPortMalloc(RES_BUF_SIZE);    
      
START:    
    memset(buf, 0, sizeof (buf));
    client_data.response_buf = buf;
    client_data.response_buf_len = RES_BUF_SIZE;
    httpclient_get(&client, url, &client_data);
    TRACE("[HTTP] Data received: %s\r\n", client_data.response_buf);

    delay_ms(60 * 1000);
    goto START;
}
