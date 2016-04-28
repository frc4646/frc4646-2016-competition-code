#include "FiringServo.h"
#include "../RobotMap.h"
#include "Commands/ServoManual.h"
#include "Commands/ServoRetract.h"

FiringServo::FiringServo(MotorPin servoPort) :
		Subsystem("ExampleSubsystem"),
		StagingServo(servoPort)
{
	RetractServo();
}

void FiringServo::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
//	SetDefaultCommand(new ServoManual());
//	SetDefaultCommand(new ServoRetract());
}

void FiringServo::GoToAngle(double angle) {
	StagingServo.SetAngle(angle);
}

void FiringServo::Set(double angle)
{
	StagingServo.Set(angle);
}


void FiringServo::RetractServo()
{
	StagingServo.Set(.047);
}
void FiringServo::ExtendServo()
{
	StagingServo.Set(.630);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
