#ifndef LCD_H
#define LCD_H
#include <stdint.h>
#include "stm32f1xx_hal.h"

#define MCMD 0X00
#define MDATA 0x01
/*
RS & RW : Port
D0-D7: Port
*/

typedef struct{
	GPIO_TypeDef *GPIO_Data;
	GPIO_TypeDef *GPIO_R;
	uint16_t D0;
	uint16_t D1;
	uint16_t D2;
	uint16_t D3;
	uint16_t D4;
	uint16_t D5;
	uint16_t D6;
	uint16_t D7;
	uint16_t RS;
	uint16_t RW;
	uint16_t En;
}LCD;

extern LCD mLCD;

void LCD_Init();
void LCD_Write_data(uint8_t data);
void LCD_Write_cmd(uint8_t data);
void LCD_Write_Byte(uint8_t data,uint8_t mode);
void Write_Print(char *str);

#endif