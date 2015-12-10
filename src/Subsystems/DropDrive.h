#ifndef DropDrive_H
#define DropDrive_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DropDrive: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	RobotDrive DriveTrain;
	Talon leftMotors;
	Talon rightMotors;
public:
	DropDrive();
	void InitDefaultCommand();
	void HandleDrive(Joystick& drive);
};

#endif
