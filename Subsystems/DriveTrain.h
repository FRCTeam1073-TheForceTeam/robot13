#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
class DriveTrain: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	bool isTurboOn;
	bool isCubicOn;
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	CANJaguar* leftDriveMotor;
	CANJaguar* rightDriveMotor;
	Gyro* driveTrainGyro;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	DriveTrain();
	void InitDefaultCommand();
	void Move(float left, float right);
	void GetPosition (float &left,float &right);
	float TicksToInches (float ticks);
	float GetGyroAngle ();
	void TurboOnOff(bool on);
	void CubicOnOff(bool on);
	bool IsCubic();
	
};
#endif
