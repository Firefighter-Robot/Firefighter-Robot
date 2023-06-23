#include "Flame_Sensor.h"

ADC_config_t ADC_Pin;


void HAL_Flame_init(void)
{
	GPIO_Pinconfig_t pinconfig ;
	pinconfig.GPIO_MODE = GPIO_MODE_Analog  ;
	pinconfig.pinNumber = GPIO_PIN_0 ;
	MCAL_GPIO_Init(GPIOA, &pinconfig) ;

	pinconfig.GPIO_MODE = GPIO_MODE_Analog  ;
	pinconfig.pinNumber = GPIO_PIN_2 ;
	MCAL_GPIO_Init(GPIOA, &pinconfig) ;

	pinconfig.GPIO_MODE = GPIO_MODE_Analog  ;
	pinconfig.pinNumber = GPIO_PIN_4 ;
	MCAL_GPIO_Init(GPIOA, &pinconfig) ;

	pinconfig.GPIO_MODE = GPIO_MODE_Analog  ;
	pinconfig.pinNumber = GPIO_PIN_5 ;
	MCAL_GPIO_Init(GPIOA, &pinconfig) ;

	pinconfig.GPIO_MODE = GPIO_MODE_Analog  ;
	pinconfig.pinNumber = GPIO_PIN_7 ;
	MCAL_GPIO_Init(GPIOA, &pinconfig) ;

	pinconfig.GPIO_MODE = GPIO_MODE_Analog  ;
	pinconfig.pinNumber = GPIO_PIN_0 ;
	MCAL_GPIO_Init(GPIOB, &pinconfig) ;

	ADC_Pin.MODE=ADC_MODE_Single;
	ADC_Pin.Data_alignment=ADC_Data_alignment_Right;
	ADC_Pin.sampling_time=ADC_sampling_time_1_5;
	ADC_Pin.Channel=Ch0;
	MCAL_ADC_Init(&ADC_Pin);
	ADC_Pin.MODE=ADC_MODE_Single;
	ADC_Pin.Data_alignment=ADC_Data_alignment_Right;
	ADC_Pin.sampling_time=ADC_sampling_time_1_5;
	ADC_Pin.Channel=Ch2;
        MCAL_ADC_Init(&ADC_Pin);
	ADC_Pin.MODE=ADC_MODE_Single;
	ADC_Pin.Data_alignment=ADC_Data_alignment_Right;
	ADC_Pin.sampling_time=ADC_sampling_time_1_5;
	ADC_Pin.Channel=Ch4;
	MCAL_ADC_Init(&ADC_Pin);
	ADC_Pin.MODE=ADC_MODE_Single;
	ADC_Pin.Data_alignment=ADC_Data_alignment_Right;
	ADC_Pin.sampling_time=ADC_sampling_time_1_5;
	ADC_Pin.Channel=Ch5;
	MCAL_ADC_Init(&ADC_Pin);
	ADC_Pin.MODE=ADC_MODE_Single;
	ADC_Pin.Data_alignment=ADC_Data_alignment_Right;
	ADC_Pin.sampling_time=ADC_sampling_time_1_5;
	ADC_Pin.Channel=Ch6;
	MCAL_ADC_Init(&ADC_Pin);
	ADC_Pin.MODE=ADC_MODE_Single;
	ADC_Pin.Data_alignment=ADC_Data_alignment_Right;
	ADC_Pin.sampling_time=ADC_sampling_time_1_5;
	ADC_Pin.Channel=Ch7;
	MCAL_ADC_Init(&ADC_Pin);
}
int Flame_Frontmid_Read()
{
	return MCAL_ADC_Read(Ch0);
}
int Flame_FrontRight_Read()
{
	return MCAL_ADC_Read(Ch2);
}
int Flame_FrontLeft_Read()
{
	return MCAL_ADC_Read(Ch4);
}
int Flame_Back_Read()
{
	return MCAL_ADC_Read(Ch5);
}
int Flame_Right_Read()
{
	return MCAL_ADC_Read(Ch6);///
}
int Flame_Left_Read()
{
	return MCAL_ADC_Read(Ch8);
}




