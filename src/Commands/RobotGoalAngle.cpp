#include "RobotGoalAngle.h"
#include "Subsystems/VisionCalculation.h"
#include "Subsystems/DropDrive.h"
#include <algorithm>

RobotGoalAngle::RobotGoalAngle():
turning(0),
robotTurn(0),
confidence(0)
{
	Requires(visioncalculation);
	Requires(dropdrive);
}

// Called just before this Command runs the first time
void RobotGoalAngle::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RobotGoalAngle::Execute()//Optimal middle x ~307 with first shooter modification
{
	turning = visioncalculation->RobotToGoalAngle()/320.0;
	if (turning > 0.01)
	{
		robotTurn = 0.18;
	}
	else if (turning < -0.05)
	{
		robotTurn = -0.18;
	}
	else
	{
		robotTurn = 0;
	}

	dropdrive->SetDrive(robotTurn, 1);
	SmartDashboard::PutNumber("Goal X Position", robotTurn);
	SmartDashboard::PutBoolean("LinedUp",confidence > 3);
}

// Make this return true when this Command no longer needs to run execute()
bool RobotGoalAngle::IsFinished()
{
	isInRange();
	return confidence > 3;
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

void RobotGoalAngle::isInRange() {
	if (turning < 0.15 && turning > -0.15)
	{
		confidence++;
	}
	else
	{
		confidence = 0;
	}
}
