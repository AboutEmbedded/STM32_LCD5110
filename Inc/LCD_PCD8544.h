/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LCD_PCD8544_H__
#define __LCD_PCD8544_H__

#include "stm32f1xx_hal.h"

#define LCD_Clk_0 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET)
#define LCD_Clk_1 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET)

#define LCD_Din_0 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET)
#define LCD_Din_1 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET)

#define LCD_DC_0 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET)
#define LCD_DC_1 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET)

#define LCD_Rst_0 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET)
#define LCD_Rst_1 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET)

#define LCD_CE_0 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET)
#define LCD_CE_1 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET)

#define LCD_Command 0x00
#define LCD_Data 0xff


void LCD_5110_init (void);
void LCD_5110_Write_byte (uint8_t Data, uint8_t Data_Command);
void LCD_5110_Write_symbol (uint8_t DataArr[], uint8_t Zero_N,uint8_t pX, uint8_t pY);
void LCD_5110_refresh (void);

#endif /* __LCD_PCD8544_H__ */
