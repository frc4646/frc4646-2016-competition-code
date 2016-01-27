#include "UltrasonicCommand.h"

UltrasonicCommand::UltrasonicCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(ultrasonicsensor);
}

// Called just before this Command runs the first time
void UltrasonicCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void UltrasonicCommand::Execute()
{
	SmartDashboard::PutNumber("Distance", ultrasonicsensor->GetDistance());
	SmartDashboard::PutNumber("Voltage", ultrasonicsensor->GetVoltage());

}

// Make this return true when this Command no longer needs to run execute()
bool UltrasonicCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void UltrasonicCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UltrasonicCommand::Interrupted()
{

}
