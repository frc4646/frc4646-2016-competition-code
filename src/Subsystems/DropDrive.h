#ifndef DropDrive_H
#define DropDrive_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "Talon.h"
#include "AnalogGyro.h"
#include "PinEnums.h"

class DropDrive: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon leftMotors;
	Talon rightMotors;
	RobotDrive DriveTrain;
	AnalogGyro gyro;

public:
	DropDrive(MotorPin leftPort, MotorPin rightPort, AnalogPin gyroPort);
	void InitDefaultCommand();
	void HandleDrive(float left, float right);
	void Stop();
	void SetDrive(double power, double curve);
	double GetHeading();
	void ResetGyro();
	void SendSD();
	void GyroCalibrate();
};

#endif
