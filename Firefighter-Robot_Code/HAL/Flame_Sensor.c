#include "Flame_Sensor.h"

ADC_config_t ADC_Pin;


void HAL_Flame_init(void)
{


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




