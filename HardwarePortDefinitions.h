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
#ifdef ADD_SECONDARY_DRIVE //as if...
	#define JAGUAR_DRIVE_SECONDARY_LEFT 4
	#define JAGUAR_DRIVE_SECONDARY_RIGHT 8
#endif

//Analog Input Channels
#define ANALOG_GYRO 1
#define ANALOG_SHOOTER_ANGLE_MAG_ENCODER 4

//Digital Input Channels
#define DIGITAL_COLLECTOR_OPTICAL_SHOT_SENSOR 4
#define DIGITAL_COLLECTOR_OPTICAL_SHOT_SENSOR_EMITTER_POWER 5 //Obviously we won't construct anything with this, just to show that it exists
#define DIGITAL_JUMPER_12 12
#define DIGITAL_JUMPER_13 13
#define DIGITAL_JUMPER_14 14

//PWM IDs
#define PWM_FEEDER_MOTOR 3
#define PWM_SHOOTER_ELEVATION_MOTOR 4
#endif
