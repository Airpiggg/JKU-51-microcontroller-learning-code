#include <REGX52.H>
#include <INTRINS.H>
#include "Delay.h"

//蜂鸣器端口：
sbit Buzzer = P2^5;

/**
  * @brief  蜂鸣器私有延时函数， 延时500us
  * @param  无
  * @retval 无
  */
void Buzzer_Delay500us(void)	//@11.0592MHz
{
	unsigned char data i;

	_nop_();
	i = 227;
	while (--i);
}

/**
  * @brief  蜂鸣器发声
  * @param  ms：发声的时长
  * @retval 无
  */
void Buzzer_Time(unsigned int ms)
{
	unsigned int i;
	for(i = 0;i < ms*2;i++)
	{
		Buzzer =! Buzzer;
		Buzzer_Delay500us();
	}
}
