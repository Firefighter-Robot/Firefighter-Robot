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
#include "DC_Motor.h"
#include "Ultrasonic.h"
#include "Flame_Sensor.h"





#define distance_step								5
#define angle_step									5

#define distance_step		10
#define angle_step			50


//Speeds
     
#define Car_Speed_0       _0_Duty_cycle       
#define Car_Speed_5       _5_Duty_cycle       
#define Car_Speed_10      _10_Duty_cycle  
#define Car_Speed_15      _15_Duty_cycle  
#define Car_Speed_20      _20_Duty_cycle  
#define Car_Speed_25      _25_Duty_cycle  
#define Car_Speed_30      _30_Duty_cycle  
#define Car_Speed_35      _35_Duty_cycle  
#define Car_Speed_40      _40_Duty_cycle  
#define Car_Speed_45      _45_Duty_cycle  
#define Car_Speed_50      _50_Duty_cycle  
#define Car_Speed_55      _55_Duty_cycle  
#define Car_Speed_60      _60_Duty_cycle  
#define Car_Speed_65      _65_Duty_cycle  
#define Car_Speed_70      _70_Duty_cycle  
#define Car_Speed_75      _75_Duty_cycle  
#define Car_Speed_80      _80_Duty_cycle  
#define Car_Speed_85      _85_Duty_cycle  
#define Car_Speed_90      _90_Duty_cycle  
#define Car_Speed_95      _95_Duty_cycle  
#define Car_Speed_100     _100_Duty_cycle     




//Directions
#define Car_TurnRight	HAL_Car_TurnRight
#define Car_TurnLeft	HAL_Car_TurnLeft


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

#define pumb(x)


extern int Flame_Frontmid_Read();
extern int Flame_FrontRight_Read();
extern int Flame_FrontLeft_Read();
extern int Flame_Back_Read();
extern int Flame_Right_Read();
extern int Flame_Left_Read();





extern uint8_t Ultrasnic_Read();
    
extern void Car_Routation(char angle , char direction); //routate the car
extern void Car_Move(uint16_t speed , char distance); //move foraward only
extern void Servo_RotationAngle(char angle , char dirction);


extern void Car_Stop_Moving();

extern void Clock_INIT(void);


//extern void pumb(char action);




#endif
