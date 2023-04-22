/*
 * DC_Motor.c
 *
 *  Created on: ١٣‏/٠٤‏/٢٠٢٣
 *      Author: Abotaleb
 */


#include "DC_Motor.h"



TIMx_config_t Timer2;

void HAL_DC_Motors_init(void)
{
	Timer2.MODE = TIMx_MODE_PWM1;
	Timer2.COUNT_MODE = TIMx_COUNT_MODE_UP;
	Timer2.Prescalers =7;      // 1M
	// init 4 Channels with 0 duty cycle
	Timer2.TopValue = Top_Value;
	Timer2.CompareValue = Top_Value;

	// set Channel 1 as an Alternative output with speed 10M
	MCAL_TIMx_Init(TIM2, &Timer2, Front_Left_Motor);

	// set Channel 2 as an Alternative output with speed 10M
	MCAL_TIMx_Init(TIM2, &Timer2, Front_Right_Motor);

	// set Channel 3 as an Alternative output with speed 10M
	MCAL_TIMx_Init(TIM2, &Timer2, Back_Left_Motor);

	// set Channel 4 as an Alternative output with speed 10M
	MCAL_TIMx_Init(TIM2, &Timer2, Back_Right_Motor);
}



void Car_Routation(char angle , char direction)
{

	// todo equation to calculate the duty cycle from angle

	if(direction == Car_TurnLeft)
	{
		// by iteration set the duty cycle  according to specific angle to the Front_Right_Motor
		MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(70),Front_Right_Motor);

		MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(15),Front_Left_Motor);

		MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(15),Back_Left_Motor);

		MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(15),Back_Right_Motor);


		// by iteration set delay to specific rotation
		delay_ms(100);

		// stop the movement
		Car_Stop_Moving();

	}
	else if(direction == Car_TurnRight)
	{
		// by iteration set the duty cycle  according to specific angle to the Front_Left_Motor
		MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(50),Front_Left_Motor);

		MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(15),Front_Right_Motor);

		MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(15),Back_Left_Motor);

		MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(15),Back_Right_Motor);


		// by iteration set delay to specific rotation
		delay_ms(100);


		// stop the movement
		Car_Stop_Moving();


	}
}



void Car_Move(char speed , char distance)
{
	// by iteration set duty cycle to specific speed
	MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(50),Front_Left_Motor);
	MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(50),Front_Right_Motor);
	MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(50),Back_Left_Motor);
	MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(50),Back_Right_Motor);

	// by iteration set delay to specific distance
	delay_ms(2000);

	// stop the movement
	Car_Stop_Moving();

}
void Car_Stop_Moving(void)
{
	MCAL_TIMx_DeInit(TIM2);
}
