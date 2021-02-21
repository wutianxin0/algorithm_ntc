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

#define ADC_DEV_NAME        "adc1"            /* ADC �豸���� */
#define ADC_DEV_CHANNEL     8                 /* ADC ͨ�� */
#define REFER_VOLTAGE       330               /* �ο���ѹ 3.3V,���ݾ��ȳ���100����2λС��*/
#define CONVERT_BITS        (1 << 12)         /* ת��λ��Ϊ12λ */

rt_adc_device_t adc_dev;
rt_uint32_t adc_value;
rt_err_t ret = RT_EOK;

ntc_val_t val;
double temp_adc;

void adc_init(void)
{
    /* �����豸 */
    adc_dev = (rt_adc_device_t)rt_device_find(ADC_DEV_NAME);
    if (adc_dev == RT_NULL)
    {
         rt_kprintf("adc sample run failed! can't find %s device!\n", ADC_DEV_NAME);
         return -100;
    }

    /* ʹ���豸 */
    ret = rt_adc_enable(adc_dev, ADC_DEV_CHANNEL);
    if (ret != RT_EOK)
    {
          rt_kprintf("Failed to enable ADC!\n", ADC_DEV_NAME);
          return -100;
    }
}

double ntc_sample_temp(void)
{
    /* ��ȡ����ֵ */
    adc_value = rt_adc_read(adc_dev, ADC_DEV_CHANNEL);

    /* NTC��ز�����ʼ�� */
    ntc_init(&val,3.3,5.1,100,4095,3950);

    /* ADCֵת��Ϊ�¶�ֵ */
    temp_adc=algorithm_ntc(&val,adc_value);

    return temp_adc;
}
