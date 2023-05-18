/*
 * stm32_f103c6_ADC.c
 *  Created on: 25/3/2023
 *  Author: Salama mohamed
 */

#include "stm32_f103c6_ADC.h"

/**================================================================
* @Fn				-MCAL_ADC_Init
* @brief		  	-Initializes the ADC  according to the specified parameters in the ADC_Config
* 					 @ ref  ADC_Data_alignment_Define  and  @ ref  ADC_MODE_Define  and ....
* @param [in] 		-ADC_Config: configuration information for  ADC {CH0 TO CH17}
* 					 take  pointer to function (this function calling at interrupt)
* @retval 			-none
* Note				-none
*/

void MCAL_ADC_Init( ADC_config_t* ADC_Config )
{
	//set  Data alignment
	if(ADC_Config->Data_alignment==ADC_Data_alignment_Left)
	{
		ADC1->CR2|=ADC_Data_alignment_Left;
	}
	else
	{
		//be default is right
	}
	//set mode
	if(ADC_Config->MODE==ADC_MODE_continuous)
	{
		ADC1->CR2|=ADC_MODE_continuous;
	}
	else
	{
		//be default single mode
	}
	//set sampling_time
	if(ADC_Config->sampling_time!=ADC_sampling_time_1_5)
	{
		if(ADC_Config->Channel<10)
			ADC1->SMPR1 |=ADC_Config->sampling_time<<(ADC_Config->Channel*3);
		else
			ADC1->SMPR2 |=ADC_Config->sampling_time<<((ADC_Config->Channel-10)*3);
	}
	else
	{
		//be default 1.5 cycle
	}
	if(ADC_Config->IRQ_EN==ADC_IRQ_ENABLE_Enable)
	{
		ADC1->CR1 |=ADC_IRQ_ENABLE_Enable;
		NVIC_IRQ18_ADC_Enable();
	}
	else
	{
		ADC1->CR1 &=ADC_IRQ_ENABLE_Disable;
		NVIC_IRQ18_ADC_Disable();
	}
}


/**================================================================
* @Fn				-MCAL_ADC_Read
* @brief		  	-Read the ADC value
* @param [in]		-enum NUM_CH CH :Select ADC channel {CH0 TO CH17}
* @retval 			-ADC value
* Note				-Support CH0 TO CH17 (Single_Mode Data_alignment_Right )
*/
uint16_t MCAL_ADC_Read( enum NUM_CH CH )
{
	uint16_t data;
	//Channel selection
	ADC1->SQR3=CH;
	//Enable adc
	ADC1->CR2 |=1<<0;
	ADC1->CR2 |=1<<0;
	//Start conversion
	ADC1->CR2 |=1<<22;
	while(!(ADC1->SR & (1<<4)));
	ADC1->SR &=~(1<<4);
	while(!(ADC1->SR & (1<<1)));
	data=ADC1->DR;
	ADC1->CR2 &=~(1<<0);
	return data;
}
