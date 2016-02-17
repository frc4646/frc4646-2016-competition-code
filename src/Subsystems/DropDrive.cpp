#include "DropDrive.h"
#include "../RobotMap.h"
#include "../Commands/TankDrive.h"
#include "../OI.h"

DropDrive::DropDrive() :
		Subsystem("DropDrive"),
		leftMotors(0),
		rightMotors(1),
		DriveTrain(leftMotors, rightMotors),
		gyro(1)
{
	gyro.Reset();
	leftMotors.SetInverted(false);
	rightMotors.SetInverted(false);
}

void DropDrive::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new TankDrive());
	DriveTrain.SetSafetyEnabled(false);

}

void DropDrive::HandleDrive(Joystick& left, Joystick& right) {
	DriveTrain.TankDrive(left.GetRawAxis(1)*-1.0, right.GetRawAxis(1)*-1.0);
//	SmartDashboard::PutNumber("Gyro heading", gyro.GetAngle());
}

void DropDrive::Stop() {
	leftMotors.SetSpeed(0);
	rightMotors.SetSpeed(0);
}

void DropDrive::SetDrive(double power, double curve) {
	DriveTrain.Drive(power, curve);
}

double DropDrive::GetHeading()
{
	return gyro.GetAngle();
}

void DropDrive::ResetGyro()
{
	gyro.Reset();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
