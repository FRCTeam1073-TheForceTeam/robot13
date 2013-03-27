#ifndef HARDWARE_PORT_DEFINITIONS_H
#define HARDWARE_PORT_DEFINITIONS_H
//#define ADD_SECONDARY_DRIVE 
//Define the above constant to enable secondary drive CIM's (also add correct can ID's below)

//Joystick IDs
#define JOY_OPERATOR 1
#define JOY_LEFT 2
#define JOY_RIGHT 3

//CAN Jaguar IDs
#define JAGUAR_SHOOTER_BACK 7
#define JAGUAR_SHOOTER_FRONT 5
#define JAGUAR_DRIVE_LEFT 6
#define JAGUAR_DRIVE_RIGHT 9
#ifdef ADD_SECONDARY_DRIVE 
	#define JAGUAR_DRIVE_SECONDARY_LEFT 4
	#define JAGUAR_DRIVE_SECONDARY_RIGHT 8
#endif
#define JAGUAR_CLIMBER_CIM_LEFT 2
#define JAGUAR_CLIMBER_CIM_RIGHT 3

//Analog Input Channels
#define ANALOG_GYRO 1
#define ANALOG_SHOOTER_ANGLE_MAG_ENCODER 2
#define ANALOG_COLLECTOR_DISC_PROXIMITY 3
#define ANALOG_CLIMBER_LEFT_ANGLE_MAG_ENCODER 5
#define ANALOG_CLIMBER_RIGHT_ANGLE_MAG_ENCODER 6

//Digital Input Channels
#define DIGITAL_MUZZLE_VELOCITY_ONE 1
#define DIGITAL_MUZZLE_VELOCITY_TWO 2
#define DIGITAL_MUZZLE_VELOCITY_EMITTER_POWER 3 //Obviously we won't construct anything with this, just to show that it exists
#define DIGITAL_COLLECTOR_OPTICAL_SHOT_SENSOR 4
#define DIGITAL_COLLECTOR_OPTICAL_SHOT_SENSOR_EMITTER_POWER 5 //Obviously we won't construct anything with this, just to show that it exists
#define DIGITAL_SHOOTER_IR_ENCODER 6
#define DIGITAL_SHOOTER_IR_EMITTER 7 //not actually used, just so you dont try and use this port
#define DIGITAL_JUMPER_12 12
#define DIGITAL_JUMPER_13 13
#define DIGITAL_JUMPER_14 14

//PWM IDs
#define PWM_CLIMBER_LEFT_WINDOW_MOTOR 1
#define PWM_CLIMBER_RIGHT_WINDOW_MOTOR 2
#define PWM_FEEDER_MOTOR 3
#define PWM_SHOOTER_ELEVATION_MOTOR 4
#define PWM_ROLLER_SPIKE_MOTOR 5
#endif
