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





#define distance_step		50
#define angle_step			50


//Speeds
     
#define Car_Speed_0      0
#define Car_Speed_5      5
#define Car_Speed_10     10
#define Car_Speed_15     15
#define Car_Speed_20     20
#define Car_Speed_25     25
#define Car_Speed_30     30
#define Car_Speed_35     35
#define Car_Speed_40     40
#define Car_Speed_45     45
#define Car_Speed_50     50
#define Car_Speed_55     55
#define Car_Speed_60     60
#define Car_Speed_65     65
#define Car_Speed_70     70
#define Car_Speed_75     75
#define Car_Speed_80     80
#define Car_Speed_85     85
#define Car_Speed_90     90
#define Car_Speed_95     95
#define Car_Speed_100    100






#define Angle_Step_0      0
#define Angle_Step_5      5
#define Angle_Step_10     10
#define Angle_Step_15     15
#define Angle_Step_20     20
#define Angle_Step_25     25
#define Angle_Step_30     30
#define Angle_Step_35     35
#define Angle_Step_40     40
#define Angle_Step_45     45
#define Angle_Step_50     50
#define Angle_Step_55     55
#define Angle_Step_60     60
#define Angle_Step_65     65
#define Angle_Step_70     70
#define Angle_Step_75     75
#define Angle_Step_80     80
#define Angle_Step_85     85
#define Angle_Step_90     90
#define Angle_Step_95     95
#define Angle_Step_100    100




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





extern float Ultrasnic_Read();
    
extern void Car_Routation(uint8_t direction); //routate the car
extern void Car_Move(uint8_t speed , uint32_t distance); //move foraward only
extern void Servo_RotationAngle(uint8_t angle , uint8_t dirction);
extern void U_Turn(uint8_t speed);

extern void Car_Stop_Moving();

extern void Clock_INIT(void);


//extern void pumb(char action);




#endif
