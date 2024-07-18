#include <REGX52.H>

unsigned char Key_KeyNumber;

/**
  * @brief  获取按键键码
  * @param  无
  * @retval Temp：按下按键的键码，范围：0，1~4，0表示无按键按下
  */
unsigned char Key(void)
{
	unsigned char Temp;
	Temp = Key_KeyNumber;
	Key_KeyNumber = 0;
	return Temp;
}

/**
  * @brief  获取独立按键键码
  * @param  无
  * @retval 返回按下按键的键码，范围0~4，无按键按下时返回值为0
  */
unsigned char Key_GetState()
{
	unsigned char KeyNumber = 0;
	
	if(P3_1 == 0)
	{
		KeyNumber = 1;
	}
	else if(P3_0 == 0)
	{
		KeyNumber = 2;
	}
	else if(P3_2 == 0)
	{
		KeyNumber = 3;
	}else if(P3_3 == 0)
	{
		KeyNumber = 4 ;
	}
	return KeyNumber;
}

/**
  * @brief  按键驱动函数，在中断中调用
  * @param  无
  * @retval 无
  */
void Key_Loop(void)
{
	static unsigned char NowState, LastState;
	LastState = NowState;				//按键状态更新
	NowState = Key_GetState();			//获取当前的按键状态
	if(LastState == 1 && NowState == 0)	//当设置为1 0的时候，是松开按键触发，而当设置为0 1的时候是按下按键触发
	{
		Key_KeyNumber = 1;
	}
	if(LastState == 2 && NowState == 0)
	{
		Key_KeyNumber = 2;
	}
	if(LastState == 3 && NowState == 0)
	{
		Key_KeyNumber = 3;
	}
	if(LastState == 4 && NowState == 0)
	{
		Key_KeyNumber = 4;
	}
}