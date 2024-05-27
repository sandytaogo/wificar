/*
 * Copyright (C) wificar, Inc.
 * 工具函数库头文件声明
 * @author txf
 * date 2020-04-12 12:12:12
 */
#ifndef __util_h__
#define __util_h__

#define uchar unsigned char 
#define uint unsigned int



sfr ADC_CONTR   =   0xBC;           //ADC控制寄存器
sfr ADC_RES     =   0xBD;           //ADC高8位结果
sfr ADC_LOW2    =   0xBE;           //ADC低2位结果
sfr P1ASF       =   0x9D;           //P1口第2功能控制寄存器

#define ADC_POWER   0x80            //ADC电源控制位
#define ADC_FLAG    0x10            //ADC完成标志



void delay(uint z);

#endif
