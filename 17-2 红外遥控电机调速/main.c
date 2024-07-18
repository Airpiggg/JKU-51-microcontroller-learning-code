#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"
#include "Motor.h"
#include "IR.h"

unsigned char Address, Command;

void main()
{
	Motor_Init();
	IR_Init();
	Nixie_Scan(1, 0);
	while(1)
	{	
		if(IR_GetDataFlag())
		{
			Command = IR_GetCommand();
			if(Command == IR_0) 
			{
				Motor_SetSpeed(0);
				Nixie_Scan(1, 0);
			}
			if(Command == IR_1) 
			{
				Motor_SetSpeed(50);
				Nixie_Scan(1, 1);
			}
			if(Command == IR_2) 
			{
				Motor_SetSpeed(75);
				Nixie_Scan(1, 2);
			}
			if(Command == IR_3) 
			{
				Motor_SetSpeed(100);
				Nixie_Scan(1, 3);
			}
		}
	}  
}
