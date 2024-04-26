/**************************************************************************************************
  Filename:      sh10.c

  Description:    sh10 driver 
                  
**************************************************************************************************/

/******************************************************************************
 * INCLUDES
 */
#include "ioCC2530.h"
#include "hal_defs.h"
#include "get_adc.h"


/******************************************************************************
 * GLOBAL VARIABLES
 */
void hal_adc_Init(void);
 uint16 readVoltage(void);
//static volatile uint32 value;

void hal_adc_Init(void)
{
	APCFG  |=1;   
        P0SEL  |= (1 << (0));	
        P0DIR  &= ~(1 << (0));	
    
}
/******************************************************************************
 * 名称       get_adc
 * 功能       读取A/D值
 * 入口参数   无
 * 出口参数   16位电压值，分辨率为10mV, 如0x0102表示2.58V
 *****************************************************************************/
uint16 get_adc(void)
{
  uint32 value;
  hal_adc_Init(); // ADC初始化
  ADCIF = 0;   //清ADC 中断标志
  //采用基准电压avdd5:3.3V，通道0，启动AD转化
  ADCCON3 = (0x80 | 0x10 | 0x00);
  while ( !ADCIF )
  {
    ;  //等待AD转化结束
  }
  value = ADCL;				//ADC转换结果的低位部分存入value中
  value |= (((uint16)ADCH)<< 8);	//取得最终转换结果存入value中
  value = value * 330;
  value = value >> 15;  		//根据计算公式算出结果值	
  return (uint16)value;
}

























