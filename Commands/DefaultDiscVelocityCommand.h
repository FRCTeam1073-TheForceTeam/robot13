#ifndef DEFAULT_DISC_VELOCITY_COMMAND_H
#define DEFAULT_DISC_VELOCITY_COMMAND_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
class DefaultDiscVelocityCommand : public Command{
public:
	DefaultDiscVelocityCommand() {Requires(Robot::discVelocity);}
	void Initialize(){
		
	}
	void Execute(){
		DriverStationLCD::GetInstance()->PrintfLine(DriverStationLCD::kUser_Line1, "primary %f", RobotMap::shooterFrontJag->GetSpeed());
		DriverStationLCD::GetInstance()->PrintfLine(DriverStationLCD::kUser_Line2, "support %f", RobotMap::shooterBackJag->GetSpeed());
		//printf("4:%d\t5:%d\n", RobotMap::velocity1->Get(), RobotMap::velocity2->Get());
		Robot::discVelocity->ProcessInterrupt();
		if(Robot::discVelocity->IsThereNewData()){
			float velocity = Robot::discVelocity->GetVelocityFPS();
			float time = Robot::discVelocity->GetEllapsedTime();
			printf("Disc Shot @ %ffps!\nTime Delta:\t%f\n",velocity, time);
			SmartDashboard::PutNumber(DISC_SHOT_SPEED_FPS, velocity);
			SmartDashboard::PutNumber(DISC_ELLAPSED_TIME, time);
		}	
	}
	bool IsFinished() {return false;}
	void End(){}
	void Interrupted(){}
};
#endif
