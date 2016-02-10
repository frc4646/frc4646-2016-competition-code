#include "RobotGoalAngle.h"
#include "Subsystems/VisionCalculation.h"
#include "Subsystems/DropDrive.h"

RobotGoalAngle::RobotGoalAngle():
turning(0)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(visioncalculation);
	Requires(dropdrive);
}

// Called just before this Command runs the first time
void RobotGoalAngle::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RobotGoalAngle::Execute()
{
	turning = visioncalculation->RobotToGoalAngle()/320.0;
	dropdrive->SetDrive(turning, 1);
	SmartDashboard::PutNumber("Goal X Position", (double)visioncalculation->RobotToGoalAngle());

}

// Make this return true when this Command no longer needs to run execute()
bool RobotGoalAngle::IsFinished()
{
	return (turning<0.1 && turning>-0.1);
}

// Called once after isFinished returns true
void RobotGoalAngle::End()
{
	dropdrive->SetDrive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RobotGoalAngle::Interrupted()
{
	End();
}
