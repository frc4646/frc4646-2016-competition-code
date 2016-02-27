#include "SpinUp.h"
#include "Subsystems/LauncherPIDSubsystem.h"
SpinUp::SpinUp(double speed)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(leftlauncherpid);
	Requires(rightlauncherpid);
	launchSpeed = speed;
}

// Called just before this Command runs the first time
void SpinUp::Initialize()
{
	//pidtest->ClearError();
	leftlauncherpid->SetSetpoint(launchSpeed);
	leftlauncherpid->Enable();
	rightlauncherpid->SetSetpoint(launchSpeed);
	rightlauncherpid->Enable();

}

// Called repeatedly when this Command is scheduled to run
void SpinUp::Execute()
{




}

// Make this return true when this Command no longer needs to run execute()
bool SpinUp::IsFinished()
{
//	return !leftlauncherpid->OnTarget();
	return (leftlauncherpid->OnTarget() && rightlauncherpid->OnTarget());
}

// Called once after isFinished returns true
void SpinUp::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpinUp::Interrupted()
{
}
