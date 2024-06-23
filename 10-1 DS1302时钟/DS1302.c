#include <REGX52.H>

//引脚定义
sbit DS1302_SCLK = P3^6;
sbit DS1302_IO = P3^4;
sbit DS1302_CE = P3^5;

//寄存器写入地址/指令定义
#define DS1302_SECOND		0x80
#define DS1302_MINUTE		0x82
#define DS1302_HOUR		0x84
#define DS1302_DATE		0x86
#define DS1302_MONTH		0x88
#define DS1302_DAY		0x8A
#define DS1302_YEAR		0x8C
#define DS1302_WP		0x8E

//时间数组，索引0~6分别是年、月、日、时、分、秒、星期
unsigned char DS1302_Time[] = {24, 6, 22, 18, 8, 15, 6};

/**
  * @brief DS1302初始函数 
  * @param  无
  * @retval 无
  */
void DS1302_Init()
{
	DS1302_CE = 0;
	DS1302_SCLK = 0;
}

/**
  * @brief  DS1302写入一个字节
  * @param  Command：命令字节/地址
  * @param  Data：写入的字节
  * @retval 无
  */
void DS1302_WriteByte(unsigned char Command, Data)
{
	unsigned char i;
	DS1302_CE = 1;
	for(i=0;i<8;i++)
	{
		DS1302_IO = Command&(0x01 << i);
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
	}
	for(i=0;i<8;i++)
	{
		DS1302_IO = Data&(0x01 << i);
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
	}
	DS1302_CE = 0;
}

/**
  * @brief  DS1302读出一个字节
  * @param  Command命令字节/地址
  * @retval 读出的数据
  */
unsigned char DS1302_ReadByte(unsigned char Command)
{
	unsigned char i, Data = 0x00;
	Command |= 0x01;
	DS1302_CE = 1;
	for(i=0;i<8;i++)
	{
		DS1302_IO = Command&(0x01 << i);
		DS1302_SCLK = 0;
		DS1302_SCLK = 1;
	}
	for(i = 0;i<8;i++)
	{
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
		if(DS1302_IO == 1) {Data |= (0x01 << i);}
	}
	DS1302_CE = 0;
	DS1302_IO = 0;
	return Data;
}

/**
  * @brief  十进制数转换为BCD数
  * @param  Dec：将要转换的十进制数
  * @retval 转换好的BCD数
  */
unsigned char DecToBCD(unsigned char Dec)
{
	unsigned char BCD;
	BCD = Dec/10*16 + Dec%10;
	return BCD;
}

/**
  * @brief  BCD数转换为十进制数
  * @param  BCD：需要转换的BCD数
  * @retval Dec：转换好的十进制数
  */
unsigned char BCDToDec(unsigned char BCD)
{
	unsigned char Dec;
	Dec = BCD/16*10 + BCD%16;
	return Dec;
}

/**
  * @brief  DS1302设置时间，调用之后，DS1302_Time数组中的数字会被设置到DS1302中
  * @param  无
  * @retval 无
  */
void DS1302_SetTime(void)
{
	DS1302_WriteByte(DS1302_WP, 0x00);
	DS1302_WriteByte(DS1302_YEAR, DecToBCD(DS1302_Time[0]));
	DS1302_WriteByte(DS1302_MONTH, DecToBCD(DS1302_Time[1]));
	DS1302_WriteByte(DS1302_DATE, DecToBCD(DS1302_Time[2]));
	DS1302_WriteByte(DS1302_HOUR, DecToBCD(DS1302_Time[3]));
	DS1302_WriteByte(DS1302_MINUTE, DecToBCD(DS1302_Time[4]));
	DS1302_WriteByte(DS1302_SECOND, DecToBCD(DS1302_Time[5]));
	DS1302_WriteByte(DS1302_DAY, DecToBCD(DS1302_Time[6]));
	DS1302_WriteByte(DS1302_WP, 0x80);
}

/**
  * @brief  DS1302读取时间，调用之后，DS1302中的数据会被读取到DS1302_Time数组中
  * @param  无
  * @retval 无
  */
void DS1302_ReadTime(void)
{
	unsigned char Temp;
	DS1302_Time[0] = BCDToDec(DS1302_ReadByte(DS1302_YEAR));
	DS1302_Time[1] = BCDToDec(DS1302_ReadByte(DS1302_MONTH));
	DS1302_Time[2] = BCDToDec(DS1302_ReadByte(DS1302_DATE));
	DS1302_Time[3] = BCDToDec(DS1302_ReadByte(DS1302_HOUR));
	DS1302_Time[4] = BCDToDec(DS1302_ReadByte(DS1302_MINUTE));
	DS1302_Time[5] = BCDToDec(DS1302_ReadByte(DS1302_SECOND));
	DS1302_Time[6] = BCDToDec(DS1302_ReadByte(DS1302_DAY));
}

