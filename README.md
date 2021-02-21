# algorithm_ntc

## 1、介绍

NTC热敏电阻器的价格低廉，在电子产品中被广泛应用，而且具有多种封装形式，能够很方便地应用到各种电路中。

NTC热敏电阻随着温度的升高而降低了电阻（即负温度系数），阻值即为NTC的的标称阻值，大多数情况下即华氏25℃时的阻值，例如，10K的NTC热敏电阻即它在25℃时的阻值为10KΩ，当然也有些特殊的阻值是以其它温度为标称的。B值是材料常数，其由制成它的陶瓷材料确定，并描述在两个温度点之间的特定温度范围内的电阻（R/T）曲线的梯度。每个热敏电阻材料将具有不同的材料常数，因此具有不同的电阻与温度曲线。NTC热敏电阻的阻值与温度对照主要关注：B值、温度、NTC阻值、阻值公差。（例如：3455 25℃ 10KΩ 1% )

algorithm_ntc是通过了解NTC特性，使用Rt=R*EXP(B*(1/T1-1/T2))算法，已知系统电压、下拉电阻、热敏电阻(NTC)25℃标称电阻值、ADC的分辨率、热敏电阻(NTC)B值。推出X温度。

一般使用NTC，都会根据生产厂商给定的热敏电阻，温度-阻值表计算相关值后，建立数组，通过查表方法最终获得温度值，algorithm_ntc只需知道热敏电阻(NTC)25℃标称电阻值和热敏电阻(NTC)B值，无需提前计算、建立数组等方法，很方便快速的获取温度值。当然也可以通过algorithm_ntc去计算从而建立数组，而无需通过复杂计算，消耗资源。

### 1.1 目录结构

| 名称 | 说明 |
| docs        | 文档目录 |
| examples | 例子目录，并有相应的一些说明 |
| inc           | 头文件目录 |
| src           | 源代码目录 |

### 1.2 使用说明

* 包含头文件 `#include <algorithm_ntc.h>`
* 定义名为xxx的结构体变量 `ntc_val_t xxx;`

### 1.3 函数功能

* 初始化系统电压、下拉电阻、热敏电阻(NTC)25℃标称电阻值、ADC的分辨率、热敏电阻(NTC)B值
void ntc_init(ntc_val_t *val,
              double sys_vol,
              double pudo_res,
              unsigned int ntc_res,
              unsigned int hex_x,
              unsigned int b_x)

* 输入采集的ADC值后输出热敏电阻的温度值
double algorithm_ntc(ntc_val_t *val,unsigned int adc_val)

## 2、注意事项

> 说明：使用前请先查看algorithm_ntc\docs\原理图.png 。此方法较消耗资源，可通过algorithm_ntc提前计算建立数组等，通过查表获取最终温度值，根据项目需求选择。

## 3、联系方式 & 感谢

* 维护：wutianxin0
* 主页：https://github.com/RT-Thread-packages/algorithm_ntc
