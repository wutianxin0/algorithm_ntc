/*
 * All rights reserved.
 *
 * File name:     algorithm_ntc.c
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-02-21     wutianxin0   [1.0.0]
 */

#include <algorithm_ntc.h>

void ntc_init(ntc_val_t *val,
              double sys_vol,
              double pudo_res,
              unsigned int ntc_res,
              unsigned int hex_x,
              unsigned int b_x)
{
    val->sys_vol=sys_vol;
    val->pudo_res=pudo_res;
    val->ntc_res=ntc_res;
    val->hex_x=hex_x;
    val->b_x=b_x;
}

/**
 * This function converts the ADC value to a temperature value.
 * Rt=R*EXP(B*(1/T1-1/T2))
 *
 * @param NTC initializes the structure.
 * @param ADC values
 *
 * @return NTC temperature
 */
double algorithm_ntc(ntc_val_t *val,unsigned int adc_val)
{
    double v_x;    /* Measured voltage value */
    double rt_x;   /* Measure the resistance */
    double temp_x; /* Measure the temperature */
    if(adc_val == 0)
    {
        return -100;/* Input error */
    }
    v_x = val->sys_vol - ((double)adc_val / val->hex_x * val->sys_vol);
    rt_x = (val->pudo_res * v_x) / (val->sys_vol - v_x);
    temp_x = ( 1 / (log(rt_x / val->ntc_res) / val->b_x + (1 / 298.15) ) ) - 273.15;
    return temp_x;
}
