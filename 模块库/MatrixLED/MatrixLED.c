#include <REGX52.H>
#include "Delay.h"

sbit RCK = P3^5;	//这里RCK等于原理图中的RCLK
sbit SCK = P3^6 ;	//这里SCK等于原理图中的SRCLK
sbit SER = P3^4;

#define MATRIX_LED_PORT		P0

/**
  * @brief  74HC595写入一个字节
  * @param  Byte是写入的字节
  * @retval 无
  */

void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i; 
	for(i = 0;i < 8;i++)
	{
		SER = Byte & (0x80 >> i);	//SER是一个一位的数据，Byte与0x80（1000 0000）进行与运算时，就相当于取出了最高位的数字，其他的都是0
		SCK = 1;
		SCK = 0;
	}
	RCK = 1;
	RCK = 0;
}

/**
  * @brief  点阵屏初始化
  * @param  无
  * @retval 无
  */

void MatrixLED_Init()
{
	SCK = 0;
	RCK = 0; 
}

/**
* @brief  LED点阵屏显示一列数据
  * @param  Column是要选择的列，范围是：0~7，0在最左面
  * @param  Data选择列显示的数据，高位在上，1为亮，0为灭
  * @retval 无
  */

void MatrixLED_ShowColumn(unsigned char Column, Data)
{
	_74HC595_WriteByte(Data);
	MATRIX_LED_PORT = ~(0x80 >> Column);
	Delay(1);
	MATRIX_LED_PORT = 0xFF;
}
