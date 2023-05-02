/*
 * stm32_f103c6_TIM2_3.c
 *
 *  Created on: 13/2/2023
 *  Author: Salama mohamed
 */

#include <stm32_f103c6_TIM2_3.h>

/*
 * ===============================================================
 *
 *                      Generic Variable
 *
 * ===============================================================
 */


//===============================================================================



/*
 * ===============================================================
 *
 *                      Generic Macro
 *
 * ===============================================================
 */


//=======================================================================================



/*
 * ===============================================================
 *
 *                      Generic Function
 *
 * ===============================================================
 */

//==========================================================================================



/*
 * ===============================================================
 *
 *                      API Function Definitions
 *
 * ===============================================================
 */

/**================================================================
* @Fn				-MCAL_TIMx_Init
* @brief		  	-Initializes the Timer [2-3] according to the specified parameters in the TIMx_Config
* 					 @ ref  TIM2_MODE_Define  and @ ref  TIM2_COUNT_MODE_Define and @ ref  TIM2_Prescalers_Defin
* @param [in] 		-TIMx_Config: configuration information for the specified timer 2 or 3
* @param [in] 		-TIMx:  specified TIMx x=[ 2 : 3 ]
* @param [in] 		-Chan:  specified channel from 1 to 4
* @retval 			-none
* Note				-Support Fast PWM and Normal ( delay mode )
*/
void MCAL_TIMx_Init( TIMx_TypeDef* TIMx , TIMx_config_t* TIMx_Config , channel Chan )
{
	GPIO_Pinconfig_t pinconfig ;
	// Enable counter and Disable update event
	TIMx->CR1=0b10000001;
	//set delay mode or PWM mode
	if(TIMx_Config->MODE != TIMx_MODE_Delay)
	{
		// set pin
		if(TIMx==TIM2)
		{
			RCC_TIM2_CLK_Enable();//clock enable
			pinconfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP  ;
			pinconfig.GPIO_OUTPUT_Speed = GPIO_speed_10M ;
			switch(Chan)
			{
			case CH1 :
				{
					//set pin outpt
					pinconfig.pinNumber = GPIO_PIN_0 ;
					break;
				}
			case CH2 :
				{
					//set pin output
					pinconfig.pinNumber = GPIO_PIN_1 ;
					break;
				}
			case CH3 :
				{
					//set pin output
					pinconfig.pinNumber = GPIO_PIN_2 ;
					break;
				}
			case CH4 :
				{
					//set pin output
					pinconfig.pinNumber = GPIO_PIN_3 ;
					break;
				}
			}
			MCAL_GPIO_Init(GPIOA, &pinconfig) ;
			//Disable interrupt
			 NVIC_IRQ28_TIM2_Disable();
		}
		else if(TIMx==TIM3)
		{
			pinconfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP  ;
			pinconfig.GPIO_OUTPUT_Speed = GPIO_speed_10M ;
			switch(Chan)
			{
			case CH1 :
				{
					//set pin output
					pinconfig.pinNumber = GPIO_PIN_6 ;
					MCAL_GPIO_Init(GPIOA, &pinconfig) ;
					break;
				}
			case CH2 :
				{
					//set pin output
					pinconfig.pinNumber = GPIO_PIN_7 ;
					MCAL_GPIO_Init(GPIOA, &pinconfig) ;
					break;
				}
			case CH3 :
				{
					//set pin output
					pinconfig.pinNumber = GPIO_PIN_0 ;
					MCAL_GPIO_Init(GPIOB, &pinconfig) ;
					break;
				}
			case CH4 :
				{
					//set pin output
					pinconfig.pinNumber = GPIO_PIN_1 ;
					MCAL_GPIO_Init(GPIOB, &pinconfig) ;
					break;
				}
			}
			//Disable interrupt
			 NVIC_IRQ28_TIM2_Disable();
		}
		else if(TIMx==TIM4)
		{
			pinconfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP  ;
			pinconfig.GPIO_OUTPUT_Speed = GPIO_speed_10M ;
			switch(Chan)
			{
			case CH1 :
				{
					//set pin output
					pinconfig.pinNumber = GPIO_PIN_6 ;
					break;
				}
			case CH2 :
				{
					//set pin output
					pinconfig.pinNumber = GPIO_PIN_7 ;
					break;
				}
			case CH3 :
				{
					//set pin output
					pinconfig.pinNumber = GPIO_PIN_8 ;
					break;
				}
			case CH4 :
				{
					//set pin output
					pinconfig.pinNumber = GPIO_PIN_9 ;

					break;
				}
			}
			MCAL_GPIO_Init(GPIOB, &pinconfig) ;
			//Disable interrupt
			 NVIC_IRQ30_TIM4_Disable();
		}
		// set PWM mode 1 or PWM mode 2 and Output compare  preload enable
		switch(Chan)
		{
		case CH1 :
			{
				TIMx->CCMR1 |=15<<3;
				break;
			}
		case CH2 :
			{
				TIMx->CCMR1 |=15<<11;
				break;
			}
		case CH3 :
			{
				TIMx->CCMR2 |=15<<3;
				break;
			}
		case CH4 :
			{
				TIMx->CCMR2 |=15<<11;
				break;
			}
		}
	}
	else
	{
		//delay mode
		switch(Chan)
		{
		case CH1 :
			{
				TIMx->CCMR1 &=~(15<<3);
				break;
			}
		case CH2 :
			{
				TIMx->CCMR1 &=~(15<<11);
				break;
			}
		case CH3 :
			{
				TIMx->CCMR2 &=~(15<<3);
				break;
			}
		case CH4 :
			{
				TIMx->CCMR2  &=~(15<<11);
				break;
			}
		}
	}
	//output polarity and  output enable
	switch(Chan)
	{
	case CH1 :
		{
			TIMx->CCER|=1<<0;
			//set init Compare value 10000
			TIMx->CCR1 = 10000;
			break;
		}
	case CH2 :
		{
			TIMx->CCER|=1<<4;
			//set init Compare value 10000
			TIMx->CCR2 = 10000;
			break;
		}
	case CH3 :
		{
			TIMx->CCER|=1<<8;
			//set init Compare value 10000
			TIMx->CCR3 = 10000;
			break;
		}
	case CH4 :
		{
			TIMx->CCER|=1<<12;
			//set init Compare value 10000
			TIMx->CCR4 = 10000;
			break;
		}
	}
	// set Prescalers
	TIMx->PSC = TIMx_Config->Prescalers;
	//set init top value 20000
	TIMx->ARR = 20000;
}

/**================================================================
* @Fn				-MCAL_TIMx_Set_Compare_Value
* @brief		  	-set a compare value to compared with the counter value  to generate waveform output (at PWM Mode)
* @param [in] 		-TIMx:  specified TIMx x=[ 2 : 3 ]
* @param [in] 		-Compare_Value: Compare_Value pass to CCRx x=[1:4]
* @param [in] 		-Chan: Chose channel 1,2,3 or 4 (TIMx contains 4 channel)
* @retval 			-none
* Note				-none
*/
void MCAL_TIMx_Set_Compare_Value( TIMx_TypeDef* TIMx  , uint16_t Compare_Value , channel Chan )
{

	switch(Chan)
	{
	case CH1 :
		{
			TIMx->CCR1 = Compare_Value;
			break;
		}
	case CH2 :
		{
			TIMx->CCR2 = Compare_Value;
			break;
		}
	case CH3 :
		{
			TIMx->CCR3 = Compare_Value;
			break;
		}
	case CH4 :
		{
			TIMx->CCR4 = Compare_Value;
			break;
		}
	}
	TIM3->EGR |=1<<0;
}

/**================================================================
* @Fn				-MCAL_TIMx_Set_TOP_Value
* @brief		  	-set a TOP value , it is maximum value the timer can reach (to control the output frequency)
* @param [in] 		-TOP_Value: TOP_Value pass to ARR
* @param [in] 		-TIMx:  specified TIMx x=[ 2 : 3 ]
* @retval 			-none
* Note				-none
*/
void MCAL_TIMx_Set_TOP_Value( TIMx_TypeDef* TIMx  , uint16_t TOP_Value )
{
	TIMx->ARR=TOP_Value;
}


/**================================================================
* @Fn				-MCAL_TIMx_DeInit
* @brief		  	-Disable counter
* @param [in] 		-TIMx:  specified TIMx x=[ 2 : 3 ]
* @retval 			-none
* Note				-none
*/
void MCAL_TIMx_DeInit( TIMx_TypeDef* TIMx )
{
	TIMx->ARR=0;
	TIMx->CR1=0;
}
//================================================================================================



void MCAL_TIM4_CAP_Init(void)
{
	//set pin capture input channel 1
	GPIO_Pinconfig_t pinconfig ;
	pinconfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	pinconfig.pinNumber = GPIO_PIN_6;
	MCAL_GPIO_Init(GPIOB, &pinconfig);

	//set Prescalers 7+1=8 TIM4 Clock=8mhz/8=1mh
	TIM4->PSC |= 7;
	//set top value
	TIM4->ARR |= 0XFFFF;
	//CC1 channel is configured as input, IC1 is mapped on TI1
	TIM4->CCMR1 |= 0x31;



	TIM4->CR1 &= ~(3 << 8);		// Bits 9:8 CKD: Clock division	-	00: tDTS = tCK_INT

	TIM4->CR1 |= (1 << 7); 		//Bit 7 ARPE: Auto-reload preload enable






	// Enable capture on CC1
	TIM4->CCER |= (1<<0);
}


float MCAL_TIM4_CAP_Get_High(void)
{
	float temp = 0;
	// enable counter
	TIM4->CR1 |= 1;

	//wait until raising edge
	while(!(TIM4->SR &(1<<1)));
	TIM4->SR=0;
	//reset counter
	TIM4->CNT=0;
	//Set CAP at falling edge
	TIM4->CCER |=1<<1;
	//wait until falling edge
	while(!(TIM4->SR &(1<<1)));
	TIM4->SR=0;

	temp = ((1.0/1000000)*TIM4->CCR1);

	// disable counter
	TIM4->CR1 &= ~(1);
	return temp;
}

float MCAL_TIM4_CAP_Get_Low(void)
{
	// enable counter
	TIM4->CR1=1;
	//Set CAP at falling edge
	TIM4->CCER |=1<<1;
	//wait until falling edge
	while(!(TIM4->SR &(1<<1)));
	TIM4->SR=0;
	//reset counter
	TIM4->CNT=0;
	//Set CAP at raising edge
	TIM4->CCER &=~(1<<1);
	//wait until raising edge
	while(!(TIM4->SR &(1<<1)));
	TIM4->SR=0;
	// disable counter
	TIM4->CR1=0;
	return ((1.0/1000000)*TIM4->CCR1);
}


uint16_t MCAL_TIM4_CAP_Get_Freq(void)
{
	uint16_t freq;
	freq=1/(MCAL_TIM4_CAP_Get_Low()+MCAL_TIM4_CAP_Get_High());
	return freq;
}

uint16_t MCAL_TIM4_CAP_Get_Duty_Cycle(void)
{
	uint16_t Duty;
	Duty=MCAL_TIM4_CAP_Get_High()/(MCAL_TIM4_CAP_Get_Low()+MCAL_TIM4_CAP_Get_High());
	return Duty;
}
