#include "Flame_Sensor.h"

ADC_config_t ADC_Pin;


void HAL_Flame_init(void)
{
	GPIO_Pinconfig_t pinconfig ;
	pinconfig.GPIO_MODE = GPIO_MODE_INPUT_PU  ;
	pinconfig.pinNumber = GPIO_PIN_14 ;
	MCAL_GPIO_Init(GPIOB, &pinconfig) ;

//	pinconfig.GPIO_MODE = GPIO_MODE_Analog  ;
//	pinconfig.pinNumber = GPIO_PIN_1 ;
//	MCAL_GPIO_Init(GPIOB, &pinconfig) ;

	pinconfig.GPIO_MODE = GPIO_MODE_INPUT_PU  ;
	pinconfig.pinNumber = GPIO_PIN_1 ;
	MCAL_GPIO_Init(GPIOB, &pinconfig) ;


	pinconfig.GPIO_MODE = GPIO_MODE_INPUT_PU  ;
	pinconfig.pinNumber = GPIO_PIN_4 ;
	MCAL_GPIO_Init(GPIOA, &pinconfig) ;

	pinconfig.GPIO_MODE = GPIO_MODE_INPUT_PU  ;
	pinconfig.pinNumber = GPIO_PIN_5 ;
	MCAL_GPIO_Init(GPIOA, &pinconfig) ;

	pinconfig.GPIO_MODE = GPIO_MODE_INPUT_PU  ;
	pinconfig.pinNumber = GPIO_PIN_7 ;
	MCAL_GPIO_Init(GPIOA, &pinconfig) ;

	pinconfig.GPIO_MODE = GPIO_MODE_INPUT_PU  ;
	pinconfig.pinNumber = GPIO_PIN_15 ;
	MCAL_GPIO_Init(GPIOB, &pinconfig) ;

	pinconfig.GPIO_MODE = GPIO_MODE_INPUT_PU  ;
	pinconfig.pinNumber = GPIO_PIN_13 ;
	MCAL_GPIO_Init(GPIOB, &pinconfig) ;

//	ADC_Pin.MODE=ADC_MODE_Single;
//	ADC_Pin.Data_alignment=ADC_Data_alignment_Right;
//	ADC_Pin.sampling_time=ADC_sampling_time_1_5;
//	ADC_Pin.Channel=Ch0;
//	MCAL_ADC_Init(&ADC_Pin);


//	ADC_Pin.MODE=ADC_MODE_Single;
//	ADC_Pin.Data_alignment=ADC_Data_alignment_Right;
//	ADC_Pin.sampling_time=ADC_sampling_time_1_5;
//	ADC_Pin.Channel=Ch9;
//        MCAL_ADC_Init(&ADC_Pin);


//	ADC_Pin.MODE=ADC_MODE_Single;
//	ADC_Pin.Data_alignment=ADC_Data_alignment_Right;
//	ADC_Pin.sampling_time=ADC_sampling_time_1_5;
//	ADC_Pin.Channel=Ch4;
//	MCAL_ADC_Init(&ADC_Pin);
//	ADC_Pin.MODE=ADC_MODE_Single;
//	ADC_Pin.Data_alignment=ADC_Data_alignment_Right;
//	ADC_Pin.sampling_time=ADC_sampling_time_1_5;
//	ADC_Pin.Channel=Ch5;
//	MCAL_ADC_Init(&ADC_Pin);
//	ADC_Pin.MODE=ADC_MODE_Single;
//	ADC_Pin.Data_alignment=ADC_Data_alignment_Right;
//	ADC_Pin.sampling_time=ADC_sampling_time_1_5;
//	ADC_Pin.Channel=Ch7;
//	MCAL_ADC_Init(&ADC_Pin);
//	ADC_Pin.MODE=ADC_MODE_Single;
//	ADC_Pin.Data_alignment=ADC_Data_alignment_Right;
//	ADC_Pin.sampling_time=ADC_sampling_time_1_5;
//	ADC_Pin.Channel=Ch8;
//	MCAL_ADC_Init(&ADC_Pin);
}
int Flame_Frontmid_Read()
{
	return MCAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14);
}
int Flame_FrontLeft_Read()
{
	return MCAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13);
}
int Flame_Distance_Read()
{
	//return MCAL_ADC_Read(Ch9);
	return MCAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1);
}
int Flame_FrontRight_Read()
{
	return MCAL_GPIO_ReadPin(GPIOB, GPIO_PIN_15);
}
int Flame_Back_Read()
{
	return MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5);
}
int Flame_Right_Read()
{
	return MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7);///
}
int Flame_Left_Read()
{
	return MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4);
}




