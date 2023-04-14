#include"APIs.h"



#define ULTRA_Threshold 
#define Flame_Threshold 
#define DISTANCE 	50
#define MotorSpeed 
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



Redirection Flame_MaxReading()
{
	int FrontMid = Flame_FrontMid_Read() - (int)Flame_Threshold;
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
			Car_Routation( angle_step , Car_TurnLeft);
		}	
	case Front_Right_en :
	case Right_en :
	case Back_en :
		//turn right
		while(Flame_MaxReading() != Front_mid_en)
		{
			Car_Routation( angle_step , Car_TurnRight);
		}	
	}
}


void CarMovements()
{
	//turn_right -> n * count
	Car_Routation( 90 , Car_TurnRight);
	Car_Move(MotorSpeed , n * DISTANCE);
	//turn right -> n * count
	Car_Routation( 90 , Car_TurnRight);
	Car_Move(MotorSpeed , n * DISTANCE);
	n++;
	
}

void CarAction ()
{
	while(!(Ultrasnic_Read() <= ULTRA_Threshold))
	{
		//move forward
		Car_Move(MotorSpeed , distance_step);
	}
	//Routate the servo
	Servo_RotationAngle(char angle , char dirction);
	//pumb on
	while(Flame_FrontMid_Read() >= Flame_Threshold)
	{	
		pumb(pumb_on);
	}
	pumb(pumb_off);
}

int main (){
	Clock_INIT();
	Init_GPIO();
	Init_Timer();
	Init_ADC();
	Init_ultasonic();
	Init_6_Flame();
	Init_Motor_drive();
	Init_servo();
	Init_pumb();

	unsigned char object_detected ;
	unsigned char flame_detected ;

	while(1)
	{
		object_detected = (Ultrasnic_Read() <= ULTRA_Threshold);
		flame_detected = ((Flame_FrontMid_Read() >= Flame_Threshold) || (Flame_FrontRight_Read() >= Flame_Threshold) || (Flame_FrontLeft_Read() >= Flame_Threshold) || (Flame_Back_Read() >= Flame_Threshold) || (Flame_Right_Read() >= Flame_Threshold) || (Flame_Left_Read() >= Flame_Threshold) );
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

}



