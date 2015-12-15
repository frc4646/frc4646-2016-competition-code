#ifndef DropDrive_H
#define DropDrive_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "Talon.h"

class DropDrive: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon leftMotors;
	Talon rightMotors;
	RobotDrive DriveTrain;

public:
	DropDrive();
	void InitDefaultCommand();
	void HandleDrive(Joystick& stick);
	void Stop();
};

#endif
