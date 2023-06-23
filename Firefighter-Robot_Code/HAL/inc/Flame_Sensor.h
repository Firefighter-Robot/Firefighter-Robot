#ifndef Flame_Sensor
#define Flame_Sensor
#include "stm32_f103c6_ADC.h"



#define Flame_Fromtmid_ch					Ch0
#define Flame_FrontRight_ch					Ch2
#define Flame_FrontLeft_ch					Ch4
#define Flame_Back_ch						Ch5
#define Flame_Right_ch						Ch8
#define Flame_Left_ch						Ch7

//=================================APIS==================

void HAL_Flame_init(void);
int Flame_Frontmid_Read();
int Flame_FrontRight_Read();
int Flame_FrontLeft_Read();
int Flame_Back_Read();
int Flame_Right_Read();
int Flame_Left_Read();



#endif
