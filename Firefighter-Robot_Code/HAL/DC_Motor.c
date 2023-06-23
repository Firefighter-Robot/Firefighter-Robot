/*
 * DC_Motor.c
 *
 *  Created on: ١٣‏/٠٤‏/٢٠٢٣
 *      Author: Abotaleb
 */


#include "DC_Motor.h"



TIMx_config_t Timer2;
static GPIO_Pinconfig_t GPIO_Pin;

//Motor1_Front     Front_Left_Motor       		  GPIO_PIN_10  PORTA                                
//Motor1_Back      Front_Left_Motor               GPIO_PIN_11  PORTA
//Motor2_Front     Front_Right_Motor              GPIO_PIN_12  PORTA
//Motor2_Back      Front_Right_Motor              GPIO_PIN_13  PORTA
//Motor3_Front     Back_Left_Motor                GPIO_PIN_3   PORTB
//Motor3_Back      Back_Left_Motor                GPIO_PIN_4   PORTB
//Motor4_Front     Back_Right_Motor               GPIO_PIN_7   PORTB
//Motor4_Back      Back_Right_Motor               GPIO_PIN_8   PORTB
void Set_GPIO_pins(void)
{
	GPIO_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	GPIO_Pin.GPIO_OUTPUT_Speed = GPIO_speed_10M;




#ifdef HALF_Controle_2_Channel
	// Left_Motors				Front
	GPIO_Pin.pinNumber = Left_Motors_Front;
	MCAL_GPIO_Init(GPIOB,&GPIO_Pin);

	// Left_Motors  			 Back
	GPIO_Pin.pinNumber = Left_Motors_Back;
	MCAL_GPIO_Init(GPIOB,&GPIO_Pin);

	// Right_Motors				Front
	GPIO_Pin.pinNumber = Right_Motors_Front;
	MCAL_GPIO_Init(GPIOB,&GPIO_Pin);

	// Right_Motors				Back
	GPIO_Pin.pinNumber = Right_Motors_Back;
	MCAL_GPIO_Init(GPIOB,&GPIO_Pin);
#endif
#ifdef FULL_Controle_4_Channel


	// Front_Left_Motor    Motor1_Front 
	GPIO_Pin.pinNumber = Motor1_Front;
	MCAL_GPIO_Init(GPIOA,&GPIO_Pin);

	// Front_Left_Motor    Motor1_Back 
	GPIO_Pin.pinNumber = Motor1_Back;
	MCAL_GPIO_Init(GPIOA,&GPIO_Pin);

	// Front_Right_Motor	Motor2_Front
	GPIO_Pin.pinNumber = Motor2_Front;
	MCAL_GPIO_Init(GPIOA,&GPIO_Pin);

	// Front_Right_Motor	Motor2_Back	
	GPIO_Pin.pinNumber = Motor2_Back;
	MCAL_GPIO_Init(GPIOA,&GPIO_Pin);

	// Back_Left_Motor	Motor3_Front
	GPIO_Pin.pinNumber = Motor3_Front;
	MCAL_GPIO_Init(GPIOB,&GPIO_Pin);

	// Back_Left_Motor	Motor3_Back	
	GPIO_Pin.pinNumber = Motor3_Back;
	MCAL_GPIO_Init(GPIOB,&GPIO_Pin);

	// Back_Right_Motor	Motor4_Front
	GPIO_Pin.pinNumber = Motor4_Front;
	MCAL_GPIO_Init(GPIOB,&GPIO_Pin);

	// Back_Right_Motor	Motor4_Back	
	GPIO_Pin.pinNumber = Motor4_Back;
	MCAL_GPIO_Init(GPIOB,&GPIO_Pin);

#endif

}



void HAL_DC_Motors_init(void)
{
	Timer2.MODE = TIMx_MODE_PWM1;
	Timer2.COUNT_MODE = TIMx_COUNT_MODE_UP;
	Timer2.Prescalers =7;      // 1M
	// init 4 Channels with 0 duty cycle
//	Timer2.TopValue = 20000;
//	Timer2.CompareValue = 10000;


#ifdef FULL_Controle_4_Channel
	// set Channel 1 as an Alternative output with speed 10M
	MCAL_TIMx_Init(TIM2, &Timer2, Front_Left_Motor);

	// set Channel 2 as an Alternative output with speed 10M
	MCAL_TIMx_Init(TIM2, &Timer2, Front_Right_Motor);

	// set Channel 3 as an Alternative output with speed 10M
	MCAL_TIMx_Init(TIM2, &Timer2, Back_Left_Motor);

	// set Channel 4 as an Alternative output with speed 10M
	MCAL_TIMx_Init(TIM2, &Timer2, Back_Right_Motor);

#endif

#ifdef HALF_Controle_2_Channel
	// set Channel 1 as an Alternative output with speed 10M
	MCAL_TIMx_Init(TIM2, &Timer2, Left_Motors);

	// set Channel 2 as an Alternative output with speed 10M
	MCAL_TIMx_Init(TIM2, &Timer2, Right_Motors);
#endif

	Set_GPIO_pins();
}

void Car_Rotation_Object(uint8_t direction , uint32_t del)
{
	if(direction == HAL_Car_TurnRight)
	{
		// Right Motors will move forward
		MCAL_GPIO_WritePin(GPIOB,Right_Motors_Front,GPIO_PIN_SET);
		MCAL_GPIO_WritePin(GPIOB,Right_Motors_Back,GPIO_PIN_RESET);
		// Left Motors will move backward
		MCAL_GPIO_WritePin(GPIOB,Left_Motors_Back,GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(GPIOB,Left_Motors_Front,GPIO_PIN_SET);

		// by iteration angle
		MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(30),Right_Motors);
		MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(30),Left_Motors);
		delay_ms(del);

	}
	else if(direction == HAL_Car_TurnLeft)
	{

		// motor Front_Left_Motor move forward
		MCAL_GPIO_WritePin(GPIOB,Left_Motors_Front,GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(GPIOB,Left_Motors_Back,GPIO_PIN_SET);
		// motor Back_Left_Motor move forward
		MCAL_GPIO_WritePin(GPIOB,Right_Motors_Back,GPIO_PIN_SET);
		MCAL_GPIO_WritePin(GPIOB,Right_Motors_Front,GPIO_PIN_RESET);

		// by iteration set the duty cycle  according to specific angle to the Front_Left_Motor
		MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(30),Left_Motors);
		MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(30),Right_Motors);
		delay_ms(del);

	}
}

void Car_Routation(uint8_t direction)
{

	// todo equation to calculate the duty cycle from angle


#ifdef FULL_Controle_4_Channel
	if(direction == HAL_Car_TurnLeft)
	{
		// motor Front_Right_Motor move forward 
		MCAL_GPIO_WritePin(GPIOA,Motor2_Front,GPIO_PIN_SET);
		MCAL_GPIO_WritePin(GPIOA,Motor2_Back,GPIO_PIN_RESET);
		// motor Back_Right_Motor move forward 
		MCAL_GPIO_WritePin(GPIOB,Motor4_Front,GPIO_PIN_SET);
		MCAL_GPIO_WritePin(GPIOB,Motor4_Back,GPIO_PIN_RESET);


		// motor Front_Left_Motor move backward
		MCAL_GPIO_WritePin(GPIOA,Motor1_Front,GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(GPIOA,Motor1_Back,GPIO_PIN_SET);
		// motor Back_Left_Motor move backward
		MCAL_GPIO_WritePin(GPIOB,Motor3_Front,GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(GPIOB,Motor3_Back,GPIO_PIN_SET);


		// by iteration set the duty cycle  according to specific angle to the Front_Right_Motor
		MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(30),Front_Right_Motor);

		MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(30),Front_Left_Motor);

		MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(30),Back_Left_Motor);

		MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(30),Back_Right_Motor);

	}
	else if(direction == HAL_Car_TurnRight)
	{

		// motor Front_Left_Motor move forward 
		MCAL_GPIO_WritePin(GPIOA,Motor1_Front,GPIO_PIN_SET);
		MCAL_GPIO_WritePin(GPIOA,Motor1_Back,GPIO_PIN_RESET);
		// motor Back_Left_Motor move forward 
		MCAL_GPIO_WritePin(GPIOB,Motor3_Front,GPIO_PIN_SET);
		MCAL_GPIO_WritePin(GPIOB,Motor3_Back,GPIO_PIN_RESET);

		// motor Front_Right_Motor move backward
		MCAL_GPIO_WritePin(GPIOA,Motor2_Front,GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(GPIOA,Motor2_Back,GPIO_PIN_SET);
		// motor Back_Right_Motor move backward
		MCAL_GPIO_WritePin(GPIOB,Motor4_Front,GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(GPIOB,Motor4_Back,GPIO_PIN_SET);

		// by iteration set the duty cycle  according to specific angle to the Front_Left_Motor
		MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(30),Front_Left_Motor);

		MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(30),Front_Right_Motor);

		MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(30),Back_Left_Motor);

		MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(30),Back_Right_Motor);

	}
#endif

#ifdef HALF_Controle_2_Channel
	if(direction == HAL_Car_TurnRight)
	{
		// Right Motors will move forward
		MCAL_GPIO_WritePin(GPIOB,Right_Motors_Front,GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(GPIOB,Right_Motors_Back,GPIO_PIN_SET);
		// Left Motors will move backward
		MCAL_GPIO_WritePin(GPIOB,Left_Motors_Back,GPIO_PIN_SET);
		MCAL_GPIO_WritePin(GPIOB,Left_Motors_Front,GPIO_PIN_RESET);

		// by iteration angle
		MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(30),Right_Motors);
		MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(30),Left_Motors);

	}
	else if(direction == HAL_Car_TurnLeft)
	{

		// motor Front_Left_Motor move forward
		MCAL_GPIO_WritePin(GPIOB,Left_Motors_Front,GPIO_PIN_SET);
		MCAL_GPIO_WritePin(GPIOB,Left_Motors_Back,GPIO_PIN_RESET);
		// motor Back_Left_Motor move forward
		MCAL_GPIO_WritePin(GPIOB,Right_Motors_Back,GPIO_PIN_SET);
		MCAL_GPIO_WritePin(GPIOB,Right_Motors_Front,GPIO_PIN_RESET);

		// by iteration set the duty cycle  according to specific angle to the Front_Left_Motor
		MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(30),Left_Motors);
		MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(30),Right_Motors);

	}
#endif

	// by iteration set delay to specific rotation
	delay_ms(350);


	// stop the movement
	Car_Stop_Moving();
}



void Car_Move(uint8_t speed , uint32_t distance)
{
#ifdef FULL_Controle_4_Channel
	// motor Front_Left_Motor move forward 
	MCAL_GPIO_WritePin(GPIOA,Motor1_Front,GPIO_PIN_SET);
	MCAL_GPIO_WritePin(GPIOA,Motor1_Back,GPIO_PIN_RESET);
	// motor Front_Right_Motor move forward 
	MCAL_GPIO_WritePin(GPIOA,Motor2_Front,GPIO_PIN_SET);
	MCAL_GPIO_WritePin(GPIOA,Motor2_Back,GPIO_PIN_RESET);
	// motor Back_Left_Motor move forward 
	MCAL_GPIO_WritePin(GPIOB,Motor3_Front,GPIO_PIN_SET);
	MCAL_GPIO_WritePin(GPIOB,Motor3_Back,GPIO_PIN_RESET);
	// motor Back_Right_Motor move forward 
	MCAL_GPIO_WritePin(GPIOB,Motor4_Front,GPIO_PIN_SET);
	MCAL_GPIO_WritePin(GPIOB,Motor4_Back,GPIO_PIN_RESET);


	// by iteration set duty cycle to specific speed
	MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(speed),Front_Left_Motor);
	MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(speed),Front_Right_Motor);
	MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(speed),Back_Left_Motor);
	MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(speed),Back_Right_Motor);


#endif


#ifdef HALF_Controle_2_Channel

	MCAL_GPIO_WritePin(GPIOB,Left_Motors_Front,GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(GPIOB,Left_Motors_Back,GPIO_PIN_SET);

	MCAL_GPIO_WritePin(GPIOB,Right_Motors_Front,GPIO_PIN_SET);
	MCAL_GPIO_WritePin(GPIOB,Right_Motors_Back,GPIO_PIN_RESET);

	//uint8_t b = speed - ;

	// by iteration set duty cycle to specific speed
	MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(speed),Left_Motors);	// prefered left - > 40 duty , right -> 70 duty cycle
	MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(speed),Right_Motors);
	//delay_ms(distance);

#endif
	// by iteration set delay to specific distance
	delay_ms(distance);

	// stop the movement
//	Car_Stop_Moving();


}

void U_Turn(uint8_t speed)
{
	Car_Move(speed,5000);

	MCAL_GPIO_WritePin(GPIOB,Right_Motors_Front,GPIO_PIN_SET);
	MCAL_GPIO_WritePin(GPIOB,Right_Motors_Back,GPIO_PIN_RESET);

	MCAL_GPIO_WritePin(GPIOB,Left_Motors_Back,GPIO_PIN_SET);
	MCAL_GPIO_WritePin(GPIOB,Left_Motors_Front,GPIO_PIN_RESET);

	MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(speed),Left_Motors);
	MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(speed),Right_Motors);
	// by iteration
	delay_ms(2000);

	Car_Move(speed,0); // 0 is the distance we will set it in the delay function
}

void Car_Stop_Moving(void)
{
#ifdef FULL_Controle_4_Channel
	MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(0),Front_Left_Motor);
	MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(0),Front_Right_Motor);
	MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(0),Back_Left_Motor);
	MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(0),Back_Right_Motor);
#endif
#ifdef HALF_Controle_2_Channel
	MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(0),Left_Motors);
	MCAL_TIMx_Set_Compare_Value(TIM2,_Duty_Cycle(0),Right_Motors);
#endif
}
