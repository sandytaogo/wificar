#ifndef __ADC_H__
#define __ADC_H__

#include "reg51.h"
#include "intrins.h"


sfr ADC_CONTR   =   0xBC;           //ADC���ƼĴ���
sfr ADC_RES     =   0xBD;           //ADC��8λ���
sfr ADC_LOW2    =   0xBE;           //ADC��2λ���
sfr P1ASF       =   0x9D;           //P1�ڵ�2���ܿ��ƼĴ���

#define ADC_POWER   0x80            //ADC��Դ����λ
#define ADC_FLAG    0x10            //ADC��ɱ�־
#define ADC_START   0x08            //ADC��ʼ����λ
#define ADC_SPEEDLL 0x00            //540��ʱ��
#define ADC_SPEEDL  0x20            //360��ʱ��
#define ADC_SPEEDH  0x40            //180��ʱ��
#define ADC_SPEEDHH 0x60            //90��ʱ��

#define ADC_Channel	6			//ѡ��ADCͨ��110 ��P1.6Ϊ�¶Ƚӿ�

void GetADCResult(unsigned char ch,unsigned int *value);
void InitADC(void);
void ADC_convert(void);

#endif