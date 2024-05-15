#include <REGX52.H>
#include "Timer0.h"
#include "LCD1602.h"

unsigned char Hours, Minutes, Seconds;

void main ()
{
	LCD_Init();
	LCD_ShowString(1, 1, "Time for now is:");
	LCD_ShowString(2, 3, ":");
	LCD_ShowString(2, 6, ":");
	Timer0_Init();
	while(1)
	{
		LCD_ShowNum(2, 7, Seconds, 2);
		LCD_ShowNum(2, 4, Minutes, 2);
		LCD_ShowNum(2, 1, Hours, 2);
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count++;
	if(T0Count >= 1000)
	{
		T0Count = 0;
		Seconds++;
		if(Seconds == 60) 
		{
			Seconds = 0;
			Minutes++;
			if(Minutes == 60)
			{
				Minutes = 0;
				Hours++;
				if(Hours == 24)
				{
					Hours = 0;
				}
			}
		}
	}
}