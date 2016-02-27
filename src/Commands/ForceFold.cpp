#include "ForceFold.h"
#include "Subsystems/IntakeArms.h"
ForceFold::ForceFold()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(intakearms);
}

// Called just before this Command runs the first time
void ForceFold::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ForceFold::Execute()
{
	intakearms->ForceRaise();
}

// Make this return true when this Command no longer needs to run execute()
bool ForceFold::IsFinished()
{
	return intakearms->GetUpValue();
}

// Called once after isFinished returns true
void ForceFold::End()
{
	intakearms->SetSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ForceFold::Interrupted()
{
	intakearms->SetSpeed(0);
}
