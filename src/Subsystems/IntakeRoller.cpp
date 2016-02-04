#include "IntakeRoller.h"
#include "../RobotMap.h"

IntakeRoller::IntakeRoller() :
		Subsystem("ExampleSubsystem"),
		right(0),
		left(1)
{

}

void IntakeRoller::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void IntakeRoller::SetSpeed(double power)
{
	right.Set(power);
	left.Set(power);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
