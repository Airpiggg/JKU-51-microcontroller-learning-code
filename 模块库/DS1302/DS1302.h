#ifndef __DS1302_H__
#define __DS1302_H__

extern unsigned char DS1302_Time[];

void DS1302_Init();
void DS1302_WriteByte(unsigned char Command, Data);
unsigned char DS1302_SendByte(unsigned char Command);
unsigned char DecToBCD(unsigned char Dec);	//十进制转换为BCD函数
unsigned char BCDToDec(unsigned char BCD);	//BCD转换为十进制函数
void DS1302_SetTime();	//在使用中只需调用这个函数和下面的函数即可
void DS1302_ReadTime();

#endif