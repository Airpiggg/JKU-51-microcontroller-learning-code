#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int Password;
unsigned char Sum;

void main()
{
	LCD_Init();
	LCD_ShowString(1, 1, "Password:");
	while(1)
	{
		KeyNum = MatrixKey();
		if(KeyNum) 
		{
			if(KeyNum <= 10) //如果按键S1~S10按下，输入密码
			{
				Password *= 10; //密码左移一位
				Password += KeyNum%10; //获取一位密码
				Sum++;
			}
			else if(KeyNum == 11)
			{
				Password /= 10;
				if(Sum) Sum--;
			}
			if(Sum && Sum % 4 == 0)
			{
				if(Password == 0666)
				{
					LCD_Init();
					LCD_ShowString(1, 1, "Access succeed!");
					Password=0;
					Sum = 0;
				}
				else
				{
					LCD_Init();
					LCD_ShowString(1, 1, "Access Denied!");
					Password=0;
					Sum = 0;
				}
				Delay(1500);
				LCD_Init();
				LCD_ShowString(1, 1, "Password:");
			}
			else
			{
				LCD_ShowNum(2, 1, Password, 4);
			}
			
		}
	}
}