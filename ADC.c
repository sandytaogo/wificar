#include "ADC.H"

/*----------------------------
Get ADC result
----------------------------*/
void GetADCResult(unsigned char ch,unsigned int *value)
{
	ADC_CONTR = ADC_POWER | ADC_SPEEDLL | ch | ADC_START;
    _nop_();                        //Must wait before inquiry
    _nop_();
    _nop_();
    _nop_();
    _nop_();                        //Must wait before inquiry
    _nop_();
    while(!(ADC_CONTR & ADC_FLAG));//Wait complete flag
    ADC_CONTR &= ~ADC_FLAG;         //Close ADC

	*value = 0;
	*value = ADC_RES;
	*value = ((*value)*4 + ADC_LOW2);		//Return ADC result.���騺����?��????������??8??ADC?��1?
}
/*----------------------------
Initial ADC sfr
----------------------------*/
void InitADC(void)
{

  P1ASF = 0x40;                	//Open channels ADC function 0100 0000 p1.6ʹ��AD����

	ADC_RES  = 0;                    		//Clear previous result
	ADC_LOW2 = 0;
  ADC_CONTR = ADC_POWER | ADC_SPEEDLL;

                           					//ADC power-on and delay
}