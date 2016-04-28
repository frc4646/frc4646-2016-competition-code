#include "ReverseSpeed.h"
#include "Subsystems/LauncherPIDSubsystem.h"
#include "Subsystems/SlavedLauncherPID.h"

ReverseSpeed::ReverseSpeed()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(slavelauncherpid);
	//	Requires(leftlauncherpid);
//	Requires(rightlauncherpid);
}

// Called just before this Command runs the first time
void ReverseSpeed::Initialize()
{
	slavelauncherpid->Reverse();
	//	leftlauncherpid->Reverse();
//	rightlauncherpid->Reverse();

}

// Called repeatedly when this Command is scheduled to run
void ReverseSpeed::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ReverseSpeed::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ReverseSpeed::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReverseSpeed::Interrupted()
{

}
