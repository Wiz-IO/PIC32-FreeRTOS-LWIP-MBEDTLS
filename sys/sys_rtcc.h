/* 
 * File:   sys_rtcc.h
 * Author: Georgi Angelov
 *
 * Created on 29 Август 2018, 13:51
 */

#ifndef SYS_RTCC_H
#define	SYS_RTCC_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <string.h>
    
typedef struct {
    uint8_t rtc_sec;        /**< Seconds after minutes   - [0,59]  */
    uint8_t rtc_min;        /**< Minutes after the hour  - [0,59]  */
    uint8_t rtc_hour;       /**< Hours after midnight    - [0,23]  */
    uint8_t rtc_day;        /**< Day of the month        - [1,31]  */
    uint8_t rtc_mon;        /**< Months                  - [1,12]  */
    uint8_t rtc_week;       /**< Days in a week          - [0,6]   */
    uint8_t rtc_year;       /**< Years                   - [0,127] */
} rtc_time_t;

void rtc_init(void);
int rtc_get_time(rtc_time_t * time);
int rtc_set_time(const rtc_time_t * time);


#ifdef	__cplusplus
}
#endif

#endif	/* SYS_RTCC_H */

