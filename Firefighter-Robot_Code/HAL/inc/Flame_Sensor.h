#ifndef Flame_Sensor
#define Flame_Sensor
#include "stm32_f103c6_ADC.h"


#define Flame_Fromtmid_ch
#define Flame_FrontRight_ch
#define Flame_FrontLeft_ch
#define Flame_Back_ch
#define Flame_Right_ch
#define Flame_Left_ch

//=================================APIS==================
<<<<<<< HEAD
void HAL_Flame_init(void);
=======

>>>>>>> 4eba040f452215fb65d2c5b4382abb6cf435b301
int Flame_Frontmid_Read();
int Flame_FrontRight_Read();
int Flame_FrontLeft_Read();
int Flame_Back_Read();
int Flame_Right_Read();
int Flame_Left_Read();



#endif
