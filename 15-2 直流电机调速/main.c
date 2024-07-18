#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"
#include "Timer0.h"

sbit Motor = P1^0;

unsigned char Counter, Compare;
unsigned char KeyNum, Speed;

void main()
{
	Timer0_Init();
	while(1)
	{
		KeyNum = Key();
		if(KeyNum == 1)
		{
			Speed++;
			Speed %= 4;
			if(Speed == 0) {Compare = 0;}
			if(Speed == 1) {Compare = 50;}
			if(Speed == 2) {Compare = 75;}
			if(Speed == 3) {Compare = 100;}
		}
		Nixie_Scan(1, Speed);
	}  
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count1 = 0, T0Count2 = 0;
	TL0 = 0xA4;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	T0Count1++;
	Counter++;
	Counter %= 100;
	if(Counter < Compare)
	{
		Motor = 1;
	}
	else
	{
		Motor = 0;
	}
	if(T0Count1  == 2)
	{
		Key_Loop();
		T0Count1 = 0;
	}
}