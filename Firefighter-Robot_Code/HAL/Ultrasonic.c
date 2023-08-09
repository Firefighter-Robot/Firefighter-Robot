/*
 * Ultrasonic.c
 *
 *  Created on: ١٥‏/٠٤‏/٢٠٢٣
 *      Author: Abotaleb
 */

#include "Ultrasonic.h"


static GPIO_Pinconfig_t GPIO_Pin;


void HAL_Ultrasonic_init(void)
{
	MCAL_TIM4_CAP_Init();
	// set trigger as an output
	GPIO_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	GPIO_Pin.GPIO_OUTPUT_Speed = GPIO_speed_10M;
	GPIO_Pin.pinNumber = Trigger_Pin1;
	MCAL_GPIO_Init(GPIOB,&GPIO_Pin);


	//	GPIO_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	//		GPIO_Pin.GPIO_OUTPUT_Speed = GPIO_speed_10M;
	//		GPIO_Pin.pinNumber = Trigger_Pin2;
	//		MCAL_GPIO_Init(GPIOB,&GPIO_Pin);

}

float Ultrasnic_Read(channel Chan)
{
	float Distance = 0 ;
	//
	//	switch (Chan)
	//	{
	//	case CH1:
	//		//trigger pulse for 10ms to start the ultrasonic
	//			MCAL_GPIO_WritePin(PORT, Trigger_Pin1, GPIO_PIN_SET);
	//			delay_ms(10);
	//			MCAL_GPIO_WritePin(PORT, Trigger_Pin1, GPIO_PIN_RESET);
	//		break;
	//
	//	case CH2:
	//		//trigger pulse for 10ms to start the ultrasonic
	//			MCAL_GPIO_WritePin(PORT, Trigger_Pin2, GPIO_PIN_SET);
	//			delay_ms(10);
	//			MCAL_GPIO_WritePin(PORT, Trigger_Pin2, GPIO_PIN_RESET);
	//
	//		break;
	// }

	//trigger pulse for 10ms to start the ultrasonic
	MCAL_GPIO_WritePin(PORT, Trigger_Pin1, GPIO_PIN_SET);
	delay_ms(10);
	MCAL_GPIO_WritePin(PORT, Trigger_Pin1, GPIO_PIN_RESET);

	// The speed of sound in free space is 340 m/s = 34000 cm/s
	// the speed = Distance / time
	// the Distance = speed * time = 34000 * time (the time of pulse on ECHO pin)
	Distance = (MCAL_TIM4_CAP_Get_High(Chan)/58.3);
	return Distance;

}
