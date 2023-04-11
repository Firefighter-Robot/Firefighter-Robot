/*
 * stm32_f103c6_ADC.h
 *  Created on: 25/3/2023
 *  Author: Salama mohamed
 */

#ifndef INC_STM32_F103C6_ADC_H_
#define INC_STM32_F103C6_ADC_H_

//Include
#include "stm32f103x6.h"
#include"stm32_f103c6_GPIO.h"
#include "stm32_f103c6_RCC.h"

//@ ref  ADC_Channel_Define
enum NUM_CH
{
	Ch0=0,
	Ch1,
	Ch2,
	Ch3,
	Ch4,
	Ch5,
	Ch6,
	Ch7,
	Ch8,
	Ch9,
	Ch10,
	Ch11,
	Ch12,
	Ch13,
	Ch14,
	Ch15,
	Ch16,
	Ch17,
};


typedef struct
{
	uint32_t MODE									; 	 //specified the ADC mode   (Single and continuous conversion modes)
														//this parameter must be set based on  @ ref  ADC_MODE_Define

	enum NUM_CH	Channel								; 	 //specified the ADC channel   (0 to 17)
														//this parameter must be set based on  @ ref  ADC_Channel_Define

	uint32_t Data_alignment							;	 //selects the alignment of data stored after conversion (Data can be left or right aligned ) .
										 	 	 	 	 //this parameter must be set based on  @ ref ADC_Data_alignment_Define

	uint32_t IRQ_EN									;	 //specified the interrupt (disable or enable )  .
														//this parameter must be set based on  @ ref  ADC_IRQ_ENABLE_Define

	uint32_t  sampling_time							;	 //specified the ADC samples the input voltage for a number of ADC_CLK cycles
														//this parameter must be set based on  @ ref  ADC_sampling_time_Define

	void (*P_IRQ_CALL)()							;    // set the function which will be call at IRQ happen

}ADC_config_t;

//=========================================================================
//-----------------------------
//Macros Configuration References
//-----------------------------
//@ ref  ADC_MODE_Define
#define ADC_MODE_Single				0
#define ADC_MODE_continuous 		(uint32_t)(1<<1)

//@ ref ADC_Data_alignment_Define
#define ADC_Data_alignment_Right	(uint32_t)(~(1<<11))
#define ADC_Data_alignment_Left		(uint32_t)(1<<11)

//@ ref  ADC_IRQ_ENABLE_Define
#define ADC_IRQ_ENABLE_Disable		(uint32_t)(~(1<<5))
#define ADC_IRQ_ENABLE_Enable		(uint32_t)(1<<5)

//@ ref  ADC_sampling_time_Define
#define ADC_sampling_time_1_5		(uint32_t)(0)
#define ADC_sampling_time_7_5		(uint32_t)(1)
#define ADC_sampling_time_13_5		(uint32_t)(2)
#define ADC_sampling_time_28_5		(uint32_t)(3)
#define ADC_sampling_time_41_5		(uint32_t)(4)
#define ADC_sampling_time_55_5		(uint32_t)(5)
#define ADC_sampling_time_71_5		(uint32_t)(6)
#define ADC_sampling_time_239_5		(uint32_t)(7)

/*
* ===============================================
* APIs Supported by "MCAL I2C DRIVER"
* ===============================================
*/
void MCAL_ADC_Init( ADC_config_t* ADC_Config );
uint16_t MCAL_ADC_Read( enum NUM_CH CH );

#endif /* INC_STM32_F103C6_ADC_H_ */
