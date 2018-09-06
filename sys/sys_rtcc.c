/*
 *  Created on: 30.08.2018
 *      Author: Georgi Angelov
 * 
 * PIC32MZ errata sheet
 * 4. Module: Secondary Oscillator
 * A crystal oscillator cannot be used as the input to the Secondary Oscillator (SOSC) pins SOSCI and SOSCO.
 * Device ID Revision = A1
 * Silicon Work around
 * Use an external clock source (32,768 Hz) 
 * applied to the SOSCO pin with the FSOSCEN bit (DEVCFG1<6>) set to ‘0’ 
 * (i.e., the SOSC is disabled through the Configuration Word) 
 * for a real-time clock base; otherwise, 
 * use the internal LPRC for non-precision requirements.
 */

#include "sys_rtcc.h"

static rtc_time_t rtc_time;

void rtc_init(void){

}

int rtc_get_time(rtc_time_t * time) {
    memcpy(time, &rtc_time, sizeof(rtc_time_t));
    return 0;
}

int rtc_set_time(const rtc_time_t * time) {
    memcpy(&rtc_time, time, sizeof(rtc_time_t));
    return 0;
}
