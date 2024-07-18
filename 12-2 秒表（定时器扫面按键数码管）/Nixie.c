#include <REGX52.H>
#include "Delay.h"

unsigned char Nixie_Buf[9] = {0, 16, 10, 10, 10, 10, 10, 10, 10};

unsigned char Nixietable[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,0x7F, 0x6F, 0x77, 0x7F, 0x39, 0x3F, 0x79, 0x71, 0x00, 0x40};

void Nixie_SetBuf(unsigned char Location, Number)
{
	Nixie_Buf[Location] = Number;
}

void Nixie_Scan(unsigned char location, number)
{
	  P0 = 0x00;
	switch(location)
	{
		case 1:P2_4=1;P2_3=1;P2_2=1;break;
		case 2:P2_4=1;P2_3=1;P2_2=0;break;
		case 3:P2_4=1;P2_3=0;P2_2=1;break;
		case 4:P2_4=1;P2_3=0;P2_2=0;break;
		case 5:P2_4=0;P2_3=1;P2_2=1;break;
		case 6:P2_4=0;P2_3=1;P2_2=0;break;
		case 7:P2_4=0;P2_3=0;P2_2=1;break;
		case 8:P2_4=0;P2_3=0;P2_2=0;break;
	}
	P0 = Nixietable[number];
}

void Nixie_Loop(void)
{
	static unsigned char i = 1;
	Nixie_Scan(i, Nixie_Buf[i]);
	i++;
	if(i > 8) {i = 1;}
}
