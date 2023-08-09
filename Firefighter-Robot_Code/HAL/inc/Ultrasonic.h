/*
 * Ultrasonic.h
 *
 *  Created on: ١٥‏/٠٤‏/٢٠٢٣
 *      Author: Abotaleb
 */

#ifndef INC_ULTRASONIC_H_
#define INC_ULTRASONIC_H_

#include "stm32_f103c6_TIM2_3.h"
#include "stm32_f103c6_GPIO.h"
#include "delay.h"


#define Trigger_Pin1 					GPIO_PIN_5
#define Trigger_Pin2 					GPIO_PIN_11
#define PORT 							GPIOB


void HAL_Ultrasonic_init(void);
float Ultrasnic_Read(channel Chan);



#endif /* INC_ULTRASONIC_H_ */
