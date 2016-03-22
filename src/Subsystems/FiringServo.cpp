#include "FiringServo.h"
#include "../RobotMap.h"

FiringServo::FiringServo(MotorPin servoPort) :
		Subsystem("ExampleSubsystem"),
		StagingServo(servoPort)
{

}

void FiringServo::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void FiringServo::GoToAngle(double angle) {
	StagingServo.SetAngle(angle);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
