#ifndef APIS_H_
#define APIS_H_


#include <stm32_f103c6_TIM2_3.h>
#include"stm32_f103c6_GPIO.h"
#include"stm32_f103c6_EXTI.h"
#include "stm32f103x6.h"
#include"stm32_f103c6_USART.h"
#include"stm32_f103c6_SPI.h"
#include "stm32_f103c6_I2C.h"
#include "LCD.h"
#include "Keypad.h"
#include "EEPROM.h"
#include "delay.h"
#include "Servo.h"
#include "stm32_f103c6_ADC.h"


#define distance_step
#define angle_step

//Speeds
#define Car_Speed_
#define Car_Speed_
#define Car_Speed_
#define Car_Speed_
#define Car_Speed_

//Directions
#define Car_TurnRight
#define Car_TurnLeft

#define Servo_TurnRight
#define Servo_TurnLeft

//Angles
#define Car_RoutatioAngle_
#define Car_RoutatioAngle_
#define Car_RoutatioAngle_
#define Car_RoutatioAngle_
#define Car_RoutatioAngle_


#define Servo_RoutatioAngle_
#define Servo_RoutatioAngle_
#define Servo_RoutatioAngle_
#define Servo_RoutatioAngle_
#define Servo_RoutatioAngle_



#define pumb_on
#define pumb_off



int Flame_Frontmid_Read();
int Flame_FrontRight_Read();
int Flame_FrontLeft_Read();
int Flame_Back_Read();
int Flame_Right_Read();
int Flame_Left_Read();


int Ultrasnic_Read();

void Car_Routation(char angle , char direction); //routate the car
void Car_Move(char speed , char distance); //move foraward only
void Servo_RotationAngle(char angle , char dirction);

void Clock_INIT(void);


void pumb(char action);





void Clock_INIT(void)
{
    //set on the clock for PORTA
    RCC_GPIOA_CLK_EN();
    //set on the clock for PORTB
    RCC_GPIOB_CLK_EN();
    //set on the clock for AFIO
    RCC_GPIOC_CLK_EN();
    RCC_AFIO_CLK_EN();
    RCC_TIM2_CLK_Enable();
    RCC_TIM3_CLK_Enable();
    RCC_TIM4_CLK_Enable();
    RCC_ADC1_CLK_Enable();
}







#endif
