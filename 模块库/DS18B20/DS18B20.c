#include <REGX52.H>
#include "OneWire.h"
#include "LCD1602.h"

#define DS18B20_SEARCH_ROM		0xF0
#define DS18B20_READ_ROM		0x33
#define DS18B20_MATCH_ROM		0x55
#define DS18B20_SKIP_ROM		0xCC
#define DS18B20_ALARM_ROM		0xEC

#define DS18B20_CONVERT_T		0x44
#define DS18B20_WRITE_SCRATCHPAD		0x4E
#define DS18B20_READ_SCRATCHPAD			0xBE
#define DS18B20_COPY_SCRATCHPAD			0x48
#define DS18B20_RECALL_E2		0xB8
#define DS18B20_READ_POWER_SUPPLY		0xB4

/**
  * @brief  DS18B20开始温度变换
  * @param  无
  * @retval 无
  */
void DS18B20_ConvertT(void)
{
	OneWire_Init();
	OneWire_SendByte(DS18B20_SKIP_ROM);
	OneWire_SendByte(DS18B20_CONVERT_T);
}

/**
  * @brief  DS18B20读取温度
  * @param  无
  * @retval T：温度的数值，类型是浮点数
  */
float DS18B20_ReadT(void)
{
	unsigned char TLSB, TMSB;
	int Temp;
	float T;
	OneWire_Init();
	OneWire_SendByte(DS18B20_SKIP_ROM);
	OneWire_SendByte(DS18B20_READ_SCRATCHPAD);
	TLSB = OneWire_ReceiveByte();
	TMSB = OneWire_ReceiveByte();
	Temp = (TMSB<<8) | TLSB;
	T = Temp/16.0;
	return T; 
} 