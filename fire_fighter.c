


#include"Peripherals.h" 		//Header file that includes the APIs of all Peripherals needed 		


int Flame_FrontMid_Read();		//Read value from the front mid sensor
int Flame_FrontRight_Read();	//Read value from the front right sensor
int Flame_FrontLeft_Read();		//Read value from the front left sensor
int Flame_Back_Read();			//Read value from the back sensor
int Flame_Right_Read();			//Read value from the right sensor
int Flame_Left_Read();			//Read value from the left sensor


int Ultrasnic_Read();	//Read value from the ultrasensor
void Motor_Routation(angle , direction);	//Controls the rotation of the car
void motor_move(speed);		//Controls the movements of the car
void Servo_RotationAngle(angle);	//Controls the rotation of the servo motor


main (){
	// Initialization of the peripherals
	Init_GPIO();
	Init_Timer();
	Init_ADC();
	Init_ultasonic();
	Init_Flame_FrontMid();		
 	Init_Flame_FrontRight();
 	Init_Flame_FrontLeft();	
 	Init_Flame_Back();			
 	Init_Flame_Right();			
 	Init_Flame_Left();			
	Init_Motor_drive();
	Init_servo();
	init_pumb();



//           Code

	while(1)
	{

		if(!Ultrasnic_Read()) // normal movement working while all sensors Doesn't reaad any thing
		{


		}
		else if  (Ultrasnic_Read())   
		{	

			if(Flame_FrontMid_Read() || Flame_FrontRight_Read() || Flame_FrontLeft_Read()) 
			{
				

			}
			else if (Flame_Right_Read())
			{


			}
			else if (Flame_Left_Read())
			{


			}
			else if (Flame_Back_Read())
			{


			}
			else 
			{
				//Avoid an obstacle algorithm 
			}


		}
	

}





}







