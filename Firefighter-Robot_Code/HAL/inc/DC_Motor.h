/*
 * DC_Motor.h
 *
 *  Created on: ١٣‏/٠٤‏/٢٠٢٣
 *      Author: Abotaleb
 */

#ifndef INC_DC_MOTOR_H_
#define INC_DC_MOTOR_H_


#include "stm32_f103c6_TIM2_3.h"
#include "delay.h"


#define Front_Left_Motor 								CH1
#define Front_Right_Motor 								CH2
#define Back_Left_Motor 								CH3
#define Back_Right_Motor 								CH4


// Front_Left_Motor
#define Motor1_Front                                    GPIO_PIN_10  // PORTA
#define Motor1_Back                                     GPIO_PIN_9  // PORTA
//Front_Right_Motor
#define Motor2_Front                                    GPIO_PIN_11  // PORTA
#define Motor2_Back                                     GPIO_PIN_12  // PORTA
//Back_Left_Motor
#define Motor3_Front                                    GPIO_PIN_3   // PORTB
#define Motor3_Back                                     GPIO_PIN_4   // PORTB
//Back_Right_Motor
#define Motor4_Front                                    GPIO_PIN_7   // PORTB
#define Motor4_Back                                     GPIO_PIN_8   // PORTB


//Directions
#define HAL_Car_TurnRight									0
#define HAL_Car_TurnLeft									1


#define Top_Value										(uint16_t)20000

// set specific duty cycle
#define _Step_5_Duty_Cycle								(uint16_t)(Top_Value / 20)


#define _0_Duty_cycle									(uint16_t)(Top_Value - (0*_Step_5_Duty_Cycle))
#define _5_Duty_cycle									(uint16_t)(Top_Value - (1*_Step_5_Duty_Cycle))
#define _10_Duty_cycle									(uint16_t)(Top_Value - (2*_Step_5_Duty_Cycle))
#define _15_Duty_cycle									(uint16_t)(Top_Value - (3*_Step_5_Duty_Cycle))
#define _20_Duty_cycle									(uint16_t)(Top_Value - (4*_Step_5_Duty_Cycle))
#define _25_Duty_cycle									(uint16_t)(Top_Value - (5*_Step_5_Duty_Cycle))
#define _30_Duty_cycle									(uint16_t)(Top_Value - (6*_Step_5_Duty_Cycle))
#define _35_Duty_cycle									(uint16_t)(Top_Value - (7*_Step_5_Duty_Cycle))
#define _40_Duty_cycle									(uint16_t)(Top_Value - (8*_Step_5_Duty_Cycle))
#define _45_Duty_cycle									(uint16_t)(Top_Value - (9*_Step_5_Duty_Cycle))
#define _50_Duty_cycle									(uint16_t)(Top_Value - (10*_Step_5_Duty_Cycle))
#define _55_Duty_cycle									(uint16_t)(Top_Value - (11*_Step_5_Duty_Cycle))
#define _60_Duty_cycle									(uint16_t)(Top_Value - (12*_Step_5_Duty_Cycle))
#define _65_Duty_cycle									(uint16_t)(Top_Value - (13*_Step_5_Duty_Cycle))
#define _70_Duty_cycle									(uint16_t)(Top_Value - (14*_Step_5_Duty_Cycle))
#define _75_Duty_cycle									(uint16_t)(Top_Value - (15*_Step_5_Duty_Cycle))
#define _80_Duty_cycle									(uint16_t)(Top_Value - (16*_Step_5_Duty_Cycle))
#define _85_Duty_cycle									(uint16_t)(Top_Value - (17*_Step_5_Duty_Cycle))
#define _90_Duty_cycle									(uint16_t)(Top_Value - (18*_Step_5_Duty_Cycle))
#define _95_Duty_cycle									(uint16_t)(Top_Value - (19*_Step_5_Duty_Cycle))
#define _100_Duty_cycle									(uint16_t)(Top_Value - (20*_Step_5_Duty_Cycle))



// set any duty cycle
#define _Step_Duty_Cycle								(uint16_t)(Top_Value / 100)
#define _Duty_Cycle(x)									(uint16_t)( (Top_Value - (x*_Step_Duty_Cycle) ) )


void HAL_DC_Motors_init(void);
void Car_Routation(char angle , char direction);
void Car_Move(uint16_t speed , char distance);
void Car_Stop_Moving(void);

#endif /* INC_DC_MOTOR_H_ */
