/*
 * DRIVERS.c
 *
 * Created: 2/6/2023 4:11:34 PM
 * Author : Bishoy Refaat
 */ 

#include "ATMEGA32.h"
#include "EXTI.h"
#include "GPIO.h"
#include "USART.h"
#include "LCD_DRIVER.h"
#include "KEYPAD_DRIVER.h"
#include "SEVEN_SEG.h"



void BIRG_USART_RXCIE(void){

}

void BIRG_USART_TXCIE(void){
		
}

void BIRG_USART_UDRIE(void){
		
}
// void USART_INIT(void){
// 
// }
uint16_t BUFFER;
int main(void)
{
		USART_CFG_t usartcfg;
		usartcfg.INT_CASE = INT_CASE_Disable;
		usartcfg.CLK_MODE = CLK_MODE_ASYNCH;
		usartcfg.BaudRate = BaudRate_14400;
		usartcfg.ClockPolarity = ClockPolarity_Rising;
		usartcfg.DataSize = DataSize_7;
		usartcfg.Device_ASYNCH_MODE = Device_ASYNCH_MODE_NormalSpeed;
		usartcfg.MPCM_Case = MPCM_Case_Disable;
		usartcfg.Parity = Parity_Disable;
		usartcfg.P_USART_CallBack[0] = BIRG_USART_RXCIE;
		usartcfg.P_USART_CallBack[1] = BIRG_USART_TXCIE;
		usartcfg.P_USART_CallBack[2] = BIRG_USART_UDRIE;
		usartcfg.StopBits = StopBits_1BIT;
		usartcfg.USART_ENABLE = USART_ENABLE_TX_RX;
		MCAL_USART_Init(&usartcfg);
		
	
	while (1) {
				
		MCAL_USART_ReceiveData(&BUFFER , &usartcfg );
		MCAL_USART_SendData(&BUFFER , &usartcfg );
		
			
	}
}

