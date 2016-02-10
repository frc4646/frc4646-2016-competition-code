#include "SendI2C.h"

SendI2C::SendI2C(LEDSystem::LEDstate state):
	stateLED(state)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(ledsystem);
}

// Called just before this Command runs the first time
void SendI2C::Initialize()
{
	ledsystem->SendLEDState(stateLED);
}

// Called repeatedly when this Command is scheduled to run
void SendI2C::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SendI2C::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SendI2C::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SendI2C::Interrupted()
{

}
