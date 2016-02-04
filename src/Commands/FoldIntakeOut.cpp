#include "FoldIntakeOut.h"
#include "Subsystems/IntakeArms.h"
FoldIntakeOut::FoldIntakeOut()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(intakearms);
}

// Called just before this Command runs the first time
void FoldIntakeOut::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void FoldIntakeOut::Execute()
{
	intakearms->SetSpeed(0.8);
}

// Make this return true when this Command no longer needs to run execute()
bool FoldIntakeOut::IsFinished()
{
	return intakearms->GetDownValue();
}

// Called once after isFinished returns true
void FoldIntakeOut::End()
{
	intakearms->SetSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FoldIntakeOut::Interrupted()
{
	intakearms->SetSpeed(0);
}
