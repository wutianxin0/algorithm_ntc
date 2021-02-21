/*
 * All rights reserved.
 *
 * File name:     algorithm_ntc.h
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-02-21     wutianxin0   [1.0.0]
 */

#ifndef APPLICATIONS_ALGORITHM_NTC_H_
#define APPLICATIONS_ALGORITHM_NTC_H_

#include <math.h>

typedef struct
{
    double          sys_vol;     /* System Voltage */
    double          pudo_res;    /* Pull-down resistor */
    unsigned int    ntc_res;     /* Thermistor nominal resistance value */
    unsigned int    hex_x;       /* The ADC resolution -12Bit_4095 10Bit_1024 8Bit_255 */
    unsigned int    b_x;         /* B value of thermistor */
}ntc_val_t;

void ntc_init(ntc_val_t *val,
              double sys_vol,
              double pudo_res,
              unsigned int ntc_res,
              unsigned int hex_x,
              unsigned int b_x);

double algorithm_ntc(ntc_val_t *val,unsigned int adc_val);

#endif /* APPLICATIONS_ALGORITHM_NTC_H_ */
