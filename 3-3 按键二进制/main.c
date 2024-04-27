#include <REGX52.H>
#include <INTRINS.H>

void Delay(unsigned int xms)
{
	unsigned char i, j;

	while(xms--)
	{
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
}

void main()
{
	{
		if(P3_1 == 0)
	while(1)
		{
			Delay(20);
			while(P3_1 == 0);
			Delay(20);
			
			P2--;
		}
	}
}