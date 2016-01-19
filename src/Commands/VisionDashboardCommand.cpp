#include "VisionDashboardCommand.h"

VisionDashboardCommand::VisionDashboardCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(visionsubsystem);
}

// Called just before this Command runs the first time
void VisionDashboardCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void VisionDashboardCommand::Execute()
{
	visionsubsystem->SendData();
}

// Make this return true when this Command no longer needs to run execute()
bool VisionDashboardCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void VisionDashboardCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void VisionDashboardCommand::Interrupted()
{

}
