#include "ServoRetract.h"
#include "Subsystems/FiringServo.h"

ServoRetract::ServoRetract()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(firingservo);
}

// Called just before this Command runs the first time
void ServoRetract::Initialize()
{
	firingservo->RetractServo();
}

// Called repeatedly when this Command is scheduled to run
void ServoRetract::Execute()
{
	firingservo->RetractServo();
}

// Make this return true when this Command no longer needs to run execute()
bool ServoRetract::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ServoRetract::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ServoRetract::Interrupted()
{

}
