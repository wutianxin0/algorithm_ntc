/*
 * All rights reserved.
 *
 * File name:     algorithm_ntc_samples.c
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-02-21     wutianxin0   [1.0.0]
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <algorithm_ntc.h>

#define ADC_DEV_NAME        "adc1"            /* ADC 设备名称 */
#define ADC_DEV_CHANNEL     8                 /* ADC 通道 */
#define REFER_VOLTAGE       330               /* 参考电压 3.3V,数据精度乘以100保留2位小数*/
#define CONVERT_BITS        (1 << 12)         /* 转换位数为12位 */

rt_adc_device_t adc_dev;
rt_uint32_t adc_value;
rt_err_t ret = RT_EOK;

ntc_val_t val;
double temp_adc;

void adc_init(void)
{
    /* 查找设备 */
    adc_dev = (rt_adc_device_t)rt_device_find(ADC_DEV_NAME);
    if (adc_dev == RT_NULL)
    {
         rt_kprintf("adc sample run failed! can't find %s device!\n", ADC_DEV_NAME);
         return -100;
    }

    /* 使能设备 */
    ret = rt_adc_enable(adc_dev, ADC_DEV_CHANNEL);
    if (ret != RT_EOK)
    {
          rt_kprintf("Failed to enable ADC!\n", ADC_DEV_NAME);
          return -100;
    }
}

double ntc_sample_temp(void)
{
    /* 读取采样值 */
    adc_value = rt_adc_read(adc_dev, ADC_DEV_CHANNEL);

    /* NTC相关参数初始化 */
    ntc_init(&val,3.3,5.1,100,4095,3950);

    /* ADC值转换为温度值 */
    temp_adc=algorithm_ntc(&val,adc_value);

    return temp_adc;
}
