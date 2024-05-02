#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"

int Result = 0;

void main()
{
	LCD_Init();	
	while(1)
	{
		Result++;
		LCD_ShowNum(1, 1, Result, 3);
		Delay(1000);
	}
}