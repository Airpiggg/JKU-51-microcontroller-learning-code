#include <REGX52.H>
#include <INTRINS.H>

unsigned char Nmb = 0;

void Delay(unsigned int xms)
{
	while(xms)
	{
		unsigned char i, j;

		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
}

void main()
{
	P2 = ~0x01;
	while(1)
	{
		if(P3_1 == 0)
		{
			Delay(20);
			while(P3_1 == 0);
			Delay(20);
			
			if(++Nmb == 8)
				Nmb = 0;
			P2 = ~(0x01 << Nmb);
		}
		
		if(P3_0 == 0)
		{
			Delay(20);
			while(P3_0 == 0);
			Delay(20);
			
			if(Nmb == 0)
				Nmb = 7;
			else
				Nmb--;
			P2 = ~(0x01 << Nmb);
		}
	}
}