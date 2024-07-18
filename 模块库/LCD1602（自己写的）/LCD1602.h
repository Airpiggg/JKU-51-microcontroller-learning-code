#ifndef __LCD1602_H__
#define __LCD1602_H__

void LCD_Init(void);
//void LCD_WriteCommand(unsigned char Command);当外部需要发送指令的时候调用此函数，比如流水灯等
void LCD_ShowChar(unsigned char Line, Column, Char);
void LCD_ShowString(unsigned char Line, unsigned char Column, unsigned char *String);
void LCD_ShowNum(unsigned char Line, Column, unsigned int Number, unsigned char Length);
void LCD_ShowSignedNum(unsigned char Line, Column, int Number, unsigned char Length);
void LCD_ShowHexNum(unsigned char Line, Column, unsigned int Number, unsigned char Length);
void LCD_ShowBinNum(unsigned char Line, Column, unsigned int Number, unsigned char Length);

#endif