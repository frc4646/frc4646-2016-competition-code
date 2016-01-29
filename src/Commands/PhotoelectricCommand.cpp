#include "PhotoelectricCommand.h"

PhotoelectricCommand::PhotoelectricCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(photoelectricsensor);
}

// Called just before this Command runs the first time
void PhotoelectricCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void PhotoelectricCommand::Execute()
{
	SmartDashboard::PutNumber("PhotoElectric Sensor", photoelectricsensor->GetValue());
}

// Make this return true when this Command no longer needs to run execute()
bool PhotoelectricCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void PhotoelectricCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PhotoelectricCommand::Interrupted()
{

}
