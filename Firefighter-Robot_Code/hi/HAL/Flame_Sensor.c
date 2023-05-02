#include "Flame_Sensor.h"

ADC_config_t ADC_Pin;


void BIRG(void)
{
//	VAL = ADC1->DR;
//	ADC1->CR2 &=~(1<<0);
//	if (VAL > 2170)
//			{
//				_delay_ms(1000);
//				MCAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
//				_delay_ms(1000);
//				VAL = 0;
//			}
}

void HAL_Flame_init(void)
{
	ADC_Pin.MODE=ADC_MODE_Single;
	ADC_Pin.Data_alignment=ADC_Data_alignment_Right;
	ADC_Pin.sampling_time=ADC_sampling_time_1_5;
	ADC_Pin.Channel=Ch0;
	ADC_Pin.IRQ_EN = ADC_IRQ_ENABLE_Disable;
	ADC_Pin.P_IRQ_CALL = BIRG;
	MCAL_ADC_Init(&ADC_Pin);

	ADC_Pin.MODE=ADC_MODE_Single;
	ADC_Pin.Data_alignment=ADC_Data_alignment_Right;
	ADC_Pin.sampling_time=ADC_sampling_time_1_5;
	ADC_Pin.Channel=Ch1;
    MCAL_ADC_Init(&ADC_Pin);

	ADC_Pin.MODE=ADC_MODE_Single;
	ADC_Pin.Data_alignment=ADC_Data_alignment_Right;
	ADC_Pin.sampling_time=ADC_sampling_time_1_5;
	ADC_Pin.Channel=Ch2;
	MCAL_ADC_Init(&ADC_Pin);

	ADC_Pin.MODE=ADC_MODE_Single;
	ADC_Pin.Data_alignment=ADC_Data_alignment_Right;
	ADC_Pin.sampling_time=ADC_sampling_time_1_5;
	ADC_Pin.Channel=Ch3;
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
}



int Flame_Frontmid_Read()
{
	return MCAL_ADC_Read(0);
}
int Flame_FrontRight_Read()
{
	return MCAL_ADC_Read(1);
}
int Flame_FrontLeft_Read()
{
	return MCAL_ADC_Read(2);
}
int Flame_Back_Read()
{
	return MCAL_ADC_Read(3);
}
int Flame_Right_Read()
{
	return MCAL_ADC_Read(4);
}
int Flame_Left_Read()
{
	return MCAL_ADC_Read(5);
}




