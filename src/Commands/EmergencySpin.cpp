#include "EmergencySpin.h"
#include "Subsystems/LauncherPIDSubsystem.h"
EmergencySpin::EmergencySpin()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(leftlauncherpid);
	Requires(rightlauncherpid);
}

// Called just before this Command runs the first time
void EmergencySpin::Initialize()
{
	//pidtest->ClearError();
	leftlauncherpid->Manual();
	rightlauncherpid->Manual();

}

// Called repeatedly when this Command is scheduled to run
void EmergencySpin::Execute()
{

	leftlauncherpid->SetManual(.9);
	rightlauncherpid->SetManual(.9);

}

// Make this return true when this Command no longer needs to run execute()
bool EmergencySpin::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void EmergencySpin::End()
{
	leftlauncherpid->SetManual(0);
	rightlauncherpid->SetManual(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EmergencySpin::Interrupted()
{
	leftlauncherpid->SetManual(0);
	rightlauncherpid->SetManual(0);
}
