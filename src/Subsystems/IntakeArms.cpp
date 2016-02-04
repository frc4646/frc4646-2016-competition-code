#include "IntakeArms.h"
#include "../RobotMap.h"

IntakeArms::IntakeArms() :
		Subsystem("ExampleSubsystem"),
		armright(5),
		armleft(6),
		LimitDown(new DigitalInput(4)),
		LimitUp(new DigitalInput(5))
{

}

void IntakeArms::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

bool IntakeArms::GetDownValue()
{
	return LimitDown->Get();
}

bool IntakeArms::GetUpValue()
{
	return LimitUp->Get();
}

void IntakeArms::SetSpeed(double power)
{
	armright.Set(power);
	armleft.Set(power);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
