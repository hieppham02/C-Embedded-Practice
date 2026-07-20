#include "LCD.h"

LCD mLCD;

void LCD_Init(){
	HAL_GPIO_WritePin(mLCD.PORT_R, mLCD.RW, 0);
	HAL_Delay(50);
	LCD_Write_Cmd(0x38);
	HAL_Delay(5);
	LCD_Write_Cmd(0x0C);
	HAL_Delay(5);
	LCD_Write_Cmd(0x01);
	HAL_Delay(5);
	LCD_Write_Cmd(0x06);
	HAL_Delay(5);
}

void LCD_Write_Byte(uint8_t data, uint8_t mode){
	if(mode == 0x01){
		//data
		HAL_GPIO_WritePin(mLCD.PORT_R, mLCD.RS, 1);	// RS = 1
		
	} else if(mode == 0x00){
		//cmd
		HAL_GPIO_WritePin(mLCD.PORT_R, mLCD.RS, 0); 	// RS = 0
	}
	HAL_GPIO_WritePin(mLCD.PORT_DATA, mLCD.D0, (data & 0x01) ? 1 : 0);
	HAL_GPIO_WritePin(mLCD.PORT_DATA, mLCD.D1, (data & 0x02) ? 1 : 0);
	HAL_GPIO_WritePin(mLCD.PORT_DATA, mLCD.D2, (data & 0x04) ? 1 : 0);
	HAL_GPIO_WritePin(mLCD.PORT_DATA, mLCD.D3, (data & 0x08) ? 1 : 0);
	HAL_GPIO_WritePin(mLCD.PORT_DATA, mLCD.D4, (data & 0x10) ? 1 : 0);
	HAL_GPIO_WritePin(mLCD.PORT_DATA, mLCD.D5,(data & 0x20) ? 1 : 0);
	HAL_GPIO_WritePin(mLCD.PORT_DATA, mLCD.D6, (data & 0x40) ? 1 : 0);
	HAL_GPIO_WritePin(mLCD.PORT_DATA, mLCD.D7, (data & 0x80) ? 1 : 0);
	
	HAL_GPIO_WritePin(mLCD.PORT_R, mLCD.EN, 0);
	HAL_Delay(1);
	HAL_GPIO_WritePin(mLCD.PORT_R, mLCD.EN, 1);
	HAL_Delay(1);
	HAL_GPIO_WritePin(mLCD.PORT_R, mLCD.EN, 0);
	HAL_Delay(1);
	
}

void LCD_Write_Data(uint8_t data){
	LCD_Write_Byte(data, 1);
}

void LCD_Write_Cmd(uint8_t data){
	LCD_Write_Byte(data, 0);
}

void LCD_Print(char *str){
	while(*str){
		LCD_Write_Data(*str++);
	}
}