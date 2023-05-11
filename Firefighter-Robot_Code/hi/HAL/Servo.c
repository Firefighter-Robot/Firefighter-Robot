/*
 * Servo.c
 *
 *  Created on: 20/2/2023
 *  Author: Salama mohamed
 */


#include "Servo.h"

void Servo_Init(void)
{
	uint16_t top;
	top=( ( 0.02 *  MCAL_Get_PCLC1_FREQ() ) / 8 );
	TIMx_config_t  TIMx_Config;
	TIMx_Config.COUNT_MODE=TIMx_COUNT_MODE_UP;
	TIMx_Config.MODE=TIMx_MODE_PWM2;
	TIMx_Config.Prescalers=7;  // timer clock 1mhz
<<<<<<< HEAD:Firefighter-Robot_Code/HAL/Servo.c
	MCAL_TIMx_Init(TIM2, &TIMx_Config , CH2);
	MCAL_TIMx_Set_Compare_Value(TIM2,10000,CH2);
	MCAL_TIMx_Set_TOP_Value(TIM2, 20000);//Frequency 50 hz
=======
	MCAL_TIMx_Init(TIM3, &TIMx_Config , CH2);
	MCAL_TIMx_Set_Compare_Value(TIM3,10000,CH2);
	MCAL_TIMx_Set_TOP_Value(TIM3, top);//Frequency 50 hz
>>>>>>> 2202aee7558f4236c971f44f1a2401b16518f7b6:Firefighter-Robot_Code/hi/HAL/Servo.c
}

void My_Servo(uint8_t angle)
{
	uint16_t compared;
	compared=500+((11.11*angle)+0.5);
	MCAL_TIMx_Set_Compare_Value(TIM3,compared,CH2);

}

void Servo_DInit(void)
{
	// disable timer3
	TIM3->CR1=0;
}
