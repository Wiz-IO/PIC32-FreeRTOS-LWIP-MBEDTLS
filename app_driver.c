#include "sys.h"
#include "osal.h"
#include "mrf.h"

void entryDRIVER(void * arg) {
    (void) arg;
    TRACE("[APP] - DRIVER -\n");
    WDRV_Init();
    while (1) {
        delay_ms(100);        
        LED_ORANGE_TOGGLE();
    }
}
