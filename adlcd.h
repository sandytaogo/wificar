/*
 * Copyright (C) wificar, Inc.
 * ADC 数字模拟信号转换头文件声明
 * @author txf
 * date 2020-04-12 12:12:12
 */
#ifndef __ADLCD_H__
#define __ADLCD_H__

#include "reg51.h"
#include "intrins.h"

sfr ADC_CONTR   =   0xBC;           //ADC控制寄存器
sfr ADC_RES     =   0xBD;           //ADC高8位结果
sfr ADC_LOW2    =   0xBE;           //ADC低2位结果
sfr P1ASF       =   0x9D;           //P1口第2功能控制寄存器

#define ADC_POWER   0x80            //ADC电源控制位
#define ADC_FLAG    0x10            //ADC完成标志
#define ADC_START   0x08            //ADC起始控制位
#define ADC_SPEEDLL 0x00            //540个时钟
#define ADC_SPEEDL  0x20            //360个时钟
#define ADC_SPEEDH  0x40            //180个时钟
#define ADC_SPEEDHH 0x60            //90个时钟

/**
 *初始化声明函数
 */
void init_adc(void);

/**
 * 信号转换函数
 */
void adc_convert(void);

#endif