/*
 * USART.h
 *
 * Created: 2/6/2023 4:19:21 PM
 *  Author: Bishoy Refaat
 */ 

#ifndef USART_H_
#define USART_H_

//		|-----------------------------------------------|
//		|===================Includes====================|
//		|-----------------------------------------------|

#include "ATMEGA32.h"
#include "GPIO.h"
#include "EXTI.h"
#include "stdint.h"
//		|-----------------------------------------------|
//		|================GENERIC MACROS=================|
//		|-----------------------------------------------|


//		|-----------------------------------------------|
//		|=============GENERIC VARIABLES=================|
//		|-----------------------------------------------|


//		|-----------------------------------------------|
//		|=============GENERIC FUNCTIONS=================|
//		|-----------------------------------------------|




//		|-----------------------------------------------|
//		|======User Type Definitions (structures)=======|
//		|-----------------------------------------------|

typedef struct{
	
	uint8_t INT_CASE;	//Enable the interrupt of the USART or not
						//Specified @ref INT_CASE_define
	
	uint8_t USART_ENABLE;	//Enable the USART
							//Specified @ref USART_ENABLE_define
							
	uint8_t MPCM_Case;		//Enable or disable the Multi-processor Communication Mode 
							//Specified @ref MPCM_Case_define
	
	uint8_t CLK_MODE;		//Defines which used clock mode synchronous or Asynchronous 
							//Specified @ref CLK_MODE_define	
	
	uint8_t Device_SYNCH_MODE;	//Define which device mode used master or slave
								//Specified @ref Device_SYNCH_MODE_define
							
	uint8_t Device_ASYNCH_MODE;	//Define which device mode used normal speed or double speed
								//Specified @ref Device_ASYNCH_MODE_define							
	
	uint8_t BaudRate;		//Defines the baud rate if the asynchronous clock mode
							//Specified @ref BaudRate_define
	
	uint8_t DataSize;		//Defines the effective data size transmitted
							//Specified @ref DataSize_define
							
							//NOTE : Data size 5:8 specified in register UCSRC bits UCSZ1 UCSZ0
							//BUT Data size 9 specified in register UCSRB bit UCSZ2 & register UCSRC bits UCSZ1 UCSZ0
							
								
	uint8_t Parity;		//Defines the parity bit if used even or odd
						//Specified @ref Parity_define
	
	uint8_t StopBits;		//Defines the count of the stop bits
							//Specified @ref StopBits_define
	
	uint8_t ClockPolarity;		//Defines the polarity of the clock in synchronous mode rising edge or falling edge 
								//Specified @ref ClockPolarity_define
	
	void(*P_USART_CallBack[3])(void);
}USART_CFG_t;

//		|------------------------------------------------------------------|
//		|=================Macros Configuration References==================|
//		|------------------------------------------------------------------|

		//***********************@ref INT_CASE_define***********************
#define INT_CASE_Enable		1
#define INT_CASE_Disable	0


		//***********************@ref USART_ENABLE_define***********************
//UCSRB->RXEN_4 , TXEN_3
#define USART_ENABLE_TX		0b01	
#define USART_ENABLE_RX		0b10
#define USART_ENABLE_TX_RX	0b11


		//***********************@ref MPCM_Case_define***********************
//UCSRA->0
#define MPCM_Case_Enable	1	//
#define MPCM_Case_Disable	0	//


		//***********************@ref CLK_MODE_define***********************
//UCSRC->6
#define CLK_MODE_SYNCH		1	
#define CLK_MODE_ASYNCH		0	


		//***********************@ref Device_SYNCH_MODE_define***********************

		//***********************@ref Device_ASYNCH_MODE_define***********************
//UCSRA->1
#define Device_ASYNCH_MODE_NormalSpeed	0
#define Device_ASYNCH_MODE_DoubleSpeed	1


		//***********************@ref BaudRate_define***********************
//UBRRL , UBBRH->[0:3]
#define BaudRate_2400	2400
#define BaudRate_4800	4800
#define BaudRate_9600	9600
#define BaudRate_14400	14400
#define BaudRate_19200	19200
#define BaudRate_28800	28800
#define BaudRate_38400	38400
#define BaudRate_57600	57600
		
		
		//***********************@ref DataSize_define***********************
//UCSRC->1,2
#define DataSize_5	0b00
#define DataSize_6	0b01
#define DataSize_7	0b10
#define DataSize_8	0b11
//UCSRB->2
#define DataSize_9	0b111


		//***********************@ref Parity_define***********************
//UCSRC->4,5
#define Parity_Disable		0b00
#define Parity_EN_EVEN		0b10
#define Parity_EN_ODD		0b11


		//***********************@ref StopBits_define***********************
//UCSRC->3
#define StopBits_1BIT	0
#define StopBits_2BITs	1


		//***********************@ref ClockPolarity_define***********************
//UCSRC->0
#define ClockPolarity_Faling	0
#define ClockPolarity_Rising	1


//		|------------------------------------------------------------------|
//		|=============APIs Supported by "MCAL GPIO DRIVER"=================|
//		|------------------------------------------------------------------|



/**================================================================
* @Fn - MCAL_USART_Init
* @brief - Initialize USART
* @param[in] - USART pin configurations
*/
void MCAL_USART_Init(USART_CFG_t *USART_CFG);



/**================================================================
* @Fn - MCAL_USART_Reset
* @brief - Reset USART
*/
void MCAL_USART_Reset(void);



/**================================================================
* @Fn - MCAL_USART_GPIO_SetPins
* @brief - Set the GPIO pins according to the chosen USART
* @param[in] - USART pin configurations
*/
void MCAL_USART_GPIO_SetPins(USART_CFG_t *USART_CFG);



/**================================================================
* @Fn - MCAL_USART_SendData
* @brief - Send data from the microcontroller to another peripheral cross USART
* @param[in] - Pointer to the buffer used to store data
* @param[in] - USART pin configurations
*/
void MCAL_USART_SendData(uint16_t *PBuffer , USART_CFG_t *USART_CFG);



/**================================================================
* @Fn - MCAL_USART_ReceiveData
* @brief - Receive data from a particular peripheral to microcontroller cross USART
* @param[in] - Pointer to the buffer used to store data
* @param[in] - USART pin configurations
*/
void MCAL_USART_ReceiveData(uint16_t *PBuffer , USART_CFG_t *USART_CFG);


#endif