/*
 * DC_Motor.c
 *
 *  Created on: ١٣‏/٠٤‏/٢٠٢٣
 *      Author: Abotaleb
 */


#include "DC_Motor.h"



TIMx_config_t Timer2;

void HAL_PWM_Set(uint32_t Duty_cycle,uint8_t Motor)
{
	Timer2.MODE = TIMx_MODE_PWM1;
	Timer2.COUNT_MODE = TIMx_COUNT_MODE_UP;
	Timer2.Prescalers =8;      // 1M
	Timer2.TopValue = Top_Value;
	Timer2.CompareValue = Duty_cycle;

	MCAL_TIMx_Init(TIM2, &Timer2, Motor);
}



void Car_Routation(char angle , char direction)
{

	// todo equation to calculate the duty cycle from angle

	if(direction == Car_TurnLeft)
	{
		// by iteration set the duty cycle  according to specific angle to the Front_Right_Motor
		HAL_PWM_Set(_50_Duty_cycle,Front_Right_Motor);
		// by iteraton set delay to specific rotation 
		delay_ms(100);

		// stop Front_Right_Motor
		HAL_PWM_Set(_0_Duty_cycle,Front_Right_Motor);
		// stop Front_Left_Motor
		HAL_PWM_Set(_0_Duty_cycle,Front_Left_Motor);
		// stop Back_Left_Motor
		HAL_PWM_Set(_0_Duty_cycle,Back_Left_Motor);
		// stop Back_Right_Motor
		HAL_PWM_Set(_0_Duty_cycle,Back_Right_Motor);

	}
	else if(direction == Car_TurnRight)
	{
		// by iteration set the duty cycle  according to specific angle to the Front_Left_Motor
		HAL_PWM_Set(_50_Duty_cycle,Front_Left_Motor);
		// by iteraton set delay to specific rotation 
		delay_ms(100);


		// stop Front_Left_Motor
		HAL_PWM_Set(_0_Duty_cycle,Front_Left_Motor);
		// stop Front_Right_Motor
		HAL_PWM_Set(_0_Duty_cycle,Front_Right_Motor);
		// stop Back_Left_Motor
		HAL_PWM_Set(_0_Duty_cycle,Back_Left_Motor);
		// stop Back_Right_Motor
		HAL_PWM_Set(_0_Duty_cycle,Back_Right_Motor);
	}
}



void Car_Move(char speed , char distance)
{
	// by iteration set duty cycle to specific speed
	HAL_PWM_Set(_50_Duty_cycle,Front_Left_Motor);
	HAL_PWM_Set(_50_Duty_cycle,Front_Right_Motor);
	HAL_PWM_Set(_50_Duty_cycle,Back_Left_Motor);
	HAL_PWM_Set(_50_Duty_cycle,Back_Right_Motor);

	// by iteration set delay to specific distance
	delay_ms(2000);

	// stop the movement
	HAL_PWM_Set(_0_Duty_cycle,Front_Left_Motor);
	HAL_PWM_Set(_0_Duty_cycle,Front_Right_Motor);
	HAL_PWM_Set(_0_Duty_cycle,Back_Left_Motor);
	HAL_PWM_Set(_0_Duty_cycle,Back_Right_Motor);

}
