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

void (*GP_ADC_IRQ_CALL)(void);

void MCAL_ADC_Init( ADC_config_t* ADC_Config )
{

	MCAL_ADC_GPIO_SetPins (ADC_Config->Channel);

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
		GP_ADC_IRQ_CALL = ADC_Config->P_IRQ_CALL;
	}
	else
	{
		ADC1->CR1 &=ADC_IRQ_ENABLE_Disable;
		NVIC_IRQ18_ADC_Disable();
	}
	ADC1->CR2 |=1<<0;
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
	ADC1->SQR3 = CH;
	//Enable adc
<<<<<<< HEAD:Firefighter-Robot_Code/stm32_f103c6_Drivers/stm32_f103c6_ADC.c
	ADC1->CR2 |=1<<0;
	while(!(ADC1->SR & (1<<1)));
	data=ADC1->DR;
=======
	ADC1->CR2 |= 1<<0;
	ADC1->CR2 |= 1<<0;
	//Start conversion
	ADC1->CR2 |= 1<<22;
	while(!(ADC1->SR & (1<<4)));
	ADC1->SR &= ~(1<<4);
	//while(!(ADC1->SR & (1<<1)));
	data=ADC1->DR;
	ADC1->CR2 &= ~(1<<0);
>>>>>>> 2202aee7558f4236c971f44f1a2401b16518f7b6:Firefighter-Robot_Code/hi/stm32_f103c6_Drivers/stm32_f103c6_ADC.c
	return data;
}



void MCAL_ADC_GPIO_SetPins (enum NUM_CH CH)
{
	switch (CH)
	{
		case Ch0 :
		{
			GPIO_Pinconfig_t gpiocfg;
			gpiocfg.GPIO_MODE = GPIO_MODE_Analog;
			gpiocfg.pinNumber = GPIO_PIN_0;
			MCAL_GPIO_Init(GPIOA, &gpiocfg);
		}
		case Ch1 :
		{
			GPIO_Pinconfig_t gpiocfg;
			gpiocfg.GPIO_MODE = GPIO_MODE_Analog;
			gpiocfg.pinNumber = GPIO_PIN_1;
			MCAL_GPIO_Init(GPIOA, &gpiocfg);
		}
		case Ch2 :
		{
			GPIO_Pinconfig_t gpiocfg;
			gpiocfg.GPIO_MODE = GPIO_MODE_Analog;
			gpiocfg.pinNumber = GPIO_PIN_2;
			MCAL_GPIO_Init(GPIOA, &gpiocfg);
		}
		case Ch3 :
		{
			GPIO_Pinconfig_t gpiocfg;
			gpiocfg.GPIO_MODE = GPIO_MODE_Analog;
			gpiocfg.pinNumber = GPIO_PIN_3;
			MCAL_GPIO_Init(GPIOA, &gpiocfg);
		}
		case Ch4 :
		{
			GPIO_Pinconfig_t gpiocfg;
			gpiocfg.GPIO_MODE = GPIO_MODE_Analog;
			gpiocfg.pinNumber = GPIO_PIN_4;
			MCAL_GPIO_Init(GPIOA, &gpiocfg);
		}
		case Ch5 :
		{
			GPIO_Pinconfig_t gpiocfg;
			gpiocfg.GPIO_MODE = GPIO_MODE_Analog;
			gpiocfg.pinNumber = GPIO_PIN_5;
			MCAL_GPIO_Init(GPIOA, &gpiocfg);
		}
		case Ch6 :
		{
			GPIO_Pinconfig_t gpiocfg;
			gpiocfg.GPIO_MODE = GPIO_MODE_Analog;
			gpiocfg.pinNumber = GPIO_PIN_6;
			MCAL_GPIO_Init(GPIOA, &gpiocfg);
		}
		case Ch7 :
		{
			GPIO_Pinconfig_t gpiocfg;
			gpiocfg.GPIO_MODE = GPIO_MODE_Analog;
			gpiocfg.pinNumber = GPIO_PIN_7;
			MCAL_GPIO_Init(GPIOA, &gpiocfg);
		}

	}
}




void ADC1_2_IRQHandler(void)
{
	GP_ADC_IRQ_CALL();
}


