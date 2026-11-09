#include "LCD.h"

void LCD_Write_Byte(uint8_t data,uint8_t mode) {
	 if(mode == 0x01) {
		 //data
		 HAL_GPIO_WritePin(mLCD.GPIO_R,mLCD.RS,1); //RS = 1;
	 }else if(mode == 0x00) {
		 //CMD
		  HAL_GPIO_WritePin(mLCD.GPIO_R,mLCD.RS,0); //RS = 0;
	 }
	 
	 HAL_GPIO_WritePin(mLCD.GPIO_Data,mLCD.D0,(data & 0x01));
	 HAL_GPIO_WritePin(mLCD.GPIO_Data,mLCD.D1,(data & 0x02));
	 HAL_GPIO_WritePin(mLCD.GPIO_Data,mLCD.D2,(data & 0x04));
	 HAL_GPIO_WritePin(mLCD.GPIO_Data,mLCD.D3,(data & 0x08));
	 HAL_GPIO_WritePin(mLCD.GPIO_Data,mLCD.D4,(data & 0x10));
	 HAL_GPIO_WritePin(mLCD.GPIO_Data,mLCD.D5,(data & 0x20));
	 HAL_GPIO_WritePin(mLCD.GPIO_Data,mLCD.D6,(data & 0x40));
	 HAL_GPIO_WritePin(mLCD.GPIO_Data,mLCD.D7,(data & 0x80));
	 
	 HAL_GPIO_WritePin(mLCD.GPIO_R,mLCD.En,0);
	 HAL_Delay(1);
	 HAL_GPIO_WritePin(mLCD.GPIO_R,mLCD.En,1);
	 HAL_Delay(1);
	 HAL_GPIO_WritePin(mLCD.GPIO_R,mLCD.En,0);
	 HAL_Delay(1);
}

void LCD_Write_data(uint8_t data) {
	 LCD_Write_Byte(data,1);
} 

void LCD_Write_cmd(uint8_t data) {
	 LCD_Write_Byte(data,0);
}

void LCD_Init() {
	HAL_GPIO_WritePin(mLCD.GPIO_R,mLCD.RW,0);
	HAL_Delay(50);
	LCD_Write_cmd(0x38);
	HAL_Delay(5);
	LCD_Write_cmd(0x0C);
  HAL_Delay(5);
	LCD_Write_cmd(0x01);
  HAL_Delay(5);
	LCD_Write_cmd(0x06);
  HAL_Delay(5);
}

void Write_Print(char *str) {
	while(*str) {
	    LCD_Write_data(*str++);
	}
}