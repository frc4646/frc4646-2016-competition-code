#include "ServoManual.h"
#include "OI.h"
#include "Subsystems/FiringServo.h"

ServoManual::ServoManual()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(firingservo);
}

// Called just before this Command runs the first time
void ServoManual::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ServoManual::Execute()
{
//	firingservo->Set(oi->GetLeftStick().GetRawAxis(2));
//	SmartDashboard::PutNumber("ServoCommand", oi->GetLeftStick().GetRawAxis(2));

}

// Make this return true when this Command no longer needs to run execute()
bool ServoManual::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ServoManual::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ServoManual::Interrupted()
{

}
