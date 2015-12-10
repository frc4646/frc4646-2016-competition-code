#include "Ringer.h"
#include "../RobotMap.h"

Ringer::Ringer() :
		Subsystem("Ringer"),
		ringerMotor(2)

{

}

void Ringer::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Ringer::SetSpeed(double power) {
	ringerMotor.SetSpeed((float)power);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
