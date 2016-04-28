#include "StopSpeed.h"
#include "Subsystems/LauncherPIDSubsystem.h"
#include "Subsystems/SlavedLauncherPID.h"

StopSpeed::StopSpeed()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(slavelauncherpid);
	//	Requires(leftlauncherpid);
//	Requires(rightlauncherpid);
}

// Called just before this Command runs the first time
void StopSpeed::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void StopSpeed::Execute()
{
	slavelauncherpid->Disable();
	//	leftlauncherpid->Disable();
//	rightlauncherpid->Disable();
}

// Make this return true when this Command no longer needs to run execute()
bool StopSpeed::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void StopSpeed::End()
{
	slavelauncherpid->Disable();
	//	leftlauncherpid->Disable();
//	rightlauncherpid->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopSpeed::Interrupted()
{

}
