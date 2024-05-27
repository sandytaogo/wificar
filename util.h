/*
 * Copyright (C) wificar, Inc.
 * ���ߺ�����ͷ�ļ�����
 * @author txf
 * date 2020-04-12 12:12:12
 */
#ifndef __util_h__
#define __util_h__

#define uchar unsigned char 
#define uint unsigned int



sfr ADC_CONTR   =   0xBC;           //ADC���ƼĴ���
sfr ADC_RES     =   0xBD;           //ADC��8λ���
sfr ADC_LOW2    =   0xBE;           //ADC��2λ���
sfr P1ASF       =   0x9D;           //P1�ڵ�2���ܿ��ƼĴ���

#define ADC_POWER   0x80            //ADC��Դ����λ
#define ADC_FLAG    0x10            //ADC��ɱ�־



void delay(uint z);

#endif
