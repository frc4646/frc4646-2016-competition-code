#include "ServoExtend.h"
#include "Subsystems/FiringServo.h"

ServoExtend::ServoExtend()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(firingservo);
}

// Called just before this Command runs the first time
void ServoExtend::Initialize()
{
	firingservo->Set(.465);

}

// Called repeatedly when this Command is scheduled to run
void ServoExtend::Execute()
{
	firingservo->Set(.465);
}

// Make this return true when this Command no longer needs to run execute()
bool ServoExtend::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ServoExtend::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ServoExtend::Interrupted()
{

}
