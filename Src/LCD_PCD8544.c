#include "LCD_PCD8544.h"

uint8_t LCD_5110_buff[84*6]; //буфер для дисплея

void LCD_5110_CLK_impulse ()
{
	LCD_Clk_0;
	//HAL_Delay(1);
	LCD_Clk_1;
}

void LCD_5110_Write_byte (uint8_t Data, uint8_t Data_Command)
{
	if(Data_Command==LCD_Command) LCD_DC_0;
	if(Data_Command==LCD_Data) 		LCD_DC_1;
	//HAL_Delay(1);
	for(uint8_t i=0;i<8;i++)
  {
		if(Data & 0x80) LCD_Din_1; else LCD_Din_0;
		Data=Data<<1;
		LCD_5110_CLK_impulse();
  }
}

void LCD_5110_Write_symbol (uint8_t DataArr[], uint8_t Zero_N,uint8_t pX, uint8_t pY)
{
	//вводим начальный адрес uint8_t pX, uint8_t pY
	LCD_DC_1;
	LCD_5110_Write_byte(0x40 + pY, LCD_Command); //установка курсора в позицию 0,0
	LCD_5110_Write_byte(0x80 + pX, LCD_Command);
	
	LCD_5110_Write_byte(DataArr[Zero_N+0],LCD_Data);
	LCD_5110_Write_byte(DataArr[Zero_N+1],LCD_Data);
	LCD_5110_Write_byte(DataArr[Zero_N+2],LCD_Data);
	LCD_5110_Write_byte(DataArr[Zero_N+3],LCD_Data);	

}

void LCD_5110_refresh ()
{

	LCD_CE_0;
	LCD_DC_0;
	LCD_5110_Write_byte(0x40, LCD_Command); //установка курсора в позицию 0,0
	LCD_5110_Write_byte(0x80, LCD_Command);
	for(uint8_t y=0;y<6;y++)
  {
		for(uint8_t x=0; x<84;x++)
    {
			LCD_5110_Write_byte(LCD_5110_buff[y*84+x], LCD_Data);
    }
  }
}



//Инициализация
void LCD_5110_init ()
{
	LCD_Clk_0;
	LCD_CE_0;
	LCD_Rst_0;
	LCD_Rst_1;
	
	LCD_5110_Write_byte(0x21, LCD_Command);
	LCD_5110_Write_byte(0xC1, LCD_Command);
	
	LCD_5110_Write_byte(0x06, LCD_Command);
	LCD_5110_Write_byte(0x13, LCD_Command);
	
	LCD_5110_Write_byte(0x20, LCD_Command);
	LCD_5110_Write_byte(0x0c, LCD_Command);
	
	//lcd8544_senddata(0b1100);	  // 0b1100 - normal mode
			                        // 0b1101 - invert mode
			                        // 0b1001 - полностью засвеченный экран
			                        // 0b1000 - чистый экран
	for(uint8_t i=0;i<((uint8_t) sizeof(LCD_5110_buff));i++)
  {
		LCD_5110_buff[i]=0x00;
  }
	LCD_5110_refresh();
}


// вывод пиксела
void lcd8544_putpix(unsigned char x, unsigned char y, unsigned char mode) {
	if ((x>84) || (y>47)) return;

	unsigned int adr=(y>>3)*84+x;
	unsigned char data=(1<<(y&0x07));

	if (mode) LCD_5110_buff[adr]|=data;
   else LCD_5110_buff[adr]&=~data;
}


