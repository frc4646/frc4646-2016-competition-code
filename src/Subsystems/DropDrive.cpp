#include "DropDrive.h"
#include "../RobotMap.h"
#include "../Commands/TankDrive.h"

DropDrive::DropDrive() :
		Subsystem("DropDrive"),
		leftMotors(1),
		rightMotors(0),
		DriveTrain(leftMotors, rightMotors)
{

}

void DropDrive::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new TankDrive());
	DriveTrain.SetSafetyEnabled(false);

}

void DropDrive::HandleDrive(Joystick& drive) {
	DriveTrain.TankDrive(drive.GetRawAxis(1), drive.GetRawAxis(3), true);
}

void DropDrive::Stop() {
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
