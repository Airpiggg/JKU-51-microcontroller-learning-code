#include <REGX52.H>
#include <INTRINS.H>

void Delay(unsigned int xms)
{
	unsigned char i, j;
	while(xms)
	{
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
	unsigned int i = 0;
	while(1)
	{
		if(P3_0 == 0)
		{
			Delay(10);
			while(P3_0 == 0);
			Delay(10);
			i++;
			if(i == 1) P2_0 = ~P2_0;
			if(i == 2) 
			{
				P2_0 = ~P2_0;
				P2_1 = ~P2_1;
			}
			if(i == 3) 
			{
				P2_1 = ~P2_1;
				P2_2 = ~P2_2;
			}
			if(i == 4) 
			{
				P2_2 = ~P2_2;
				P2_3 = ~P2_3;
			}
			if(i == 5) 
			{
				P2_3 = ~P2_3;
				P2_4 = ~P2_4;
			}
			if(i == 6) 
			{
				P2_4 = ~P2_4;
				P2_5 = ~P2_5;
			}
			if(i == 7) 
			{
				P2_5 = ~P2_5;
				P2_6 = ~P2_6;
			}
			if(i == 8) 
			{
				P2_6 = ~P2_6;
				P2_7 = ~P2_7;
			}
			if(i == 9) 
			{
				P2_7 = ~P2_7;
				i = 0;
			}
		}
	}
}