#include <REGX52.H>
#include "Delay.h"
#include "UART.h"

unsigned char sec;

void main ()
{
	UART_Init();
	UART_SendByte('B');
	UART_SendByte(0x3a);
	while(1)
	{ 
		
	}
}

void UART_Routine() interrupt 4
{
	if(RI == 1)
	{
		P2 = SBUF;
		UART_SendByte(SBUF);
		RI = 0;
	}
	
}