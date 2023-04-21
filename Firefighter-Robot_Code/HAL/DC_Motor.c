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

	if(direction == HAL_Car_TurnLeft)
	{
		// by iteration set the duty cycle  according to specific angle to the Front_Right_Motor
		HAL_PWM_Set(_Duty_Cycle(50),Front_Right_Motor);

		HAL_PWM_Set(_Duty_Cycle(15),Front_Left_Motor);

		HAL_PWM_Set(_Duty_Cycle(15),Back_Left_Motor);
		
		HAL_PWM_Set(_Duty_Cycle(15),Back_Right_Motor);


		// by iteration set delay to specific rotation
		delay_ms(100);

		// stop the movement
		Car_Stop_Moving();


	}
	else if(direction == HAL_Car_TurnRight)
	{
		// by iteration set the duty cycle  according to specific angle to the Front_Left_Motor
		HAL_PWM_Set(_Duty_Cycle(50),Front_Left_Motor);
		
		HAL_PWM_Set(_Duty_Cycle(15),Front_Right_Motor);
		
		HAL_PWM_Set(_Duty_Cycle(15),Back_Left_Motor);
		
		HAL_PWM_Set(_Duty_Cycle(15),Back_Right_Motor);


		// by iteration set delay to specific rotation
		delay_ms(100);


		// stop the movement
		Car_Stop_Moving();


	}
}



void Car_Move(uint16_t speed , char distance)
{
	// by iteration set duty cycle to specific speed
	HAL_PWM_Set(_Duty_Cycle(50),Front_Left_Motor);
	HAL_PWM_Set(_Duty_Cycle(50),Front_Right_Motor);
	HAL_PWM_Set(_Duty_Cycle(50),Back_Left_Motor);
	HAL_PWM_Set(_Duty_Cycle(50),Back_Right_Motor);

	// by iteration set delay to specific distance
	delay_ms(2000);

	// stop the movement
	Car_Stop_Moving();

}
void Car_Stop_Moving(void)
{
	MCAL_TIMx_DeInit(TIM2);

}
