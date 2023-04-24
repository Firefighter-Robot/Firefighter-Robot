/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include"APIs.h"


#define ULTRA_Threshold			20
#define Flame_Threshold			40
#define DISTANCE 	50



// delete this macro when writing Pump driver
#define pumb(x)   ;


int n = 1;


typedef enum Redirection
{

	Front_mid_en,
	Front_Left_en,
	Front_Right_en,
	Right_en,
	Left_en,
	Back_en

}Redirection;



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




Redirection Flame_MaxReading()
{
	int FrontMid = Flame_Frontmid_Read() - (int)Flame_Threshold;
	int FrontRight = Flame_FrontRight_Read() - (int)Flame_Threshold;
	int FrontLeft = Flame_FrontLeft_Read() - (int)Flame_Threshold;
	int Back = Flame_Back_Read() - (int)Flame_Threshold;
	int Right = Flame_Right_Read() - (int)Flame_Threshold;
	int Left = Flame_Left_Read() - (int)Flame_Threshold;

	if ((FrontMid > FrontRight) && (FrontMid > FrontLeft) && (FrontMid > Back) && (FrontMid > Right) && (FrontMid > Left))
	{
		return Front_mid_en;
	}
	else if ((FrontRight > FrontLeft) && (FrontRight > Back) && (FrontRight > Right) && (FrontRight > Left))
	{
		return Front_Right_en;
	}
	else if ((FrontLeft > Back) && (FrontLeft > Right) && (FrontLeft > Left))
	{
		return Front_Left_en;
	}
	else if ((Back > Right) && (Back > Left))
	{
		return Back_en;
	}
	else if ((Right > Left))
	{
		return Right_en;
	}
	else
	{
		return Left_en;
	}
}

void CarAdjustament (Redirection MaxReading)
{
	switch (MaxReading)
	{
	case Front_Left_en :
	case Left_en :
		//turn left
		while(Flame_MaxReading() != Front_mid_en)
		{
			Car_Routation( Angle_Step_40 , Car_TurnLeft);
		}
	case Front_Right_en :
	case Right_en :
	case Back_en :
		//turn right
		while(Flame_MaxReading() != Front_mid_en)
		{
			Car_Routation( Angle_Step_40 , Car_TurnRight);
		}
	}
}


void CarMovements()
{
	//turn_right -> n * count
	Car_Routation( 90 , Car_TurnRight);
	Car_Move(Car_Speed_70 , n * DISTANCE);
	//turn right -> n * count
	Car_Routation( 90 , Car_TurnRight);
	Car_Move(Car_Speed_70 , n * DISTANCE);
	n++;

}

void CarAction ()
{
	while(!(Ultrasnic_Read() <= ULTRA_Threshold))
	{
		//move forward
		Car_Move(Car_Speed_70 , distance_step);
	}
	//Routate the servo
	//Servo_RotationAngle(char angle , char dirction);
	//pumb on
	while(Flame_Frontmid_Read() >= Flame_Threshold)
	{
		pumb(pumb_on);
	}
	pumb(pumb_off);
}



void HAL_Driver_init(void)
{
	HAL_Flame_init();
	HAL_DC_Motors_init();
	HAL_Ultrasonic_init();
	//Init_servo();
	//Init_pumb();

}


int main (){

	Clock_INIT();
	HAL_Driver_init();

	unsigned char object_detected ;
	unsigned char flame_detected ;

	while(1)
	{
		object_detected = (Ultrasnic_Read() <= ULTRA_Threshold);
		flame_detected = ((Flame_Frontmid_Read() >= Flame_Threshold) || (Flame_FrontRight_Read() >= Flame_Threshold) || (Flame_FrontLeft_Read() >= Flame_Threshold) || (Flame_Back_Read() >= Flame_Threshold) || (Flame_Right_Read() >= Flame_Threshold) || (Flame_Left_Read() >= Flame_Threshold) );
		if(!(object_detected || flame_detected))
		{
			CarMovements();
		}
		else if(object_detected && flame_detected) // detected object
		{
			CarAdjustament (Flame_MaxReading());
			CarAction();
			n = 1;
		}
		else if (object_detected)
		{
			n = 1;
			CarMovements();
			//todo

		}
		else if (flame_detected)
		{
			CarAdjustament (Flame_MaxReading());
			CarAction();
			n = 1;
		}
	}


	return 0;

}
