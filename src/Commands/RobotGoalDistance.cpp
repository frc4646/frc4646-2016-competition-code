#include "RobotGoalDistance.h"
#include "Subsystems/DropDrive.h"
#include "Subsystems/VisionCalculation.h"
#include "Subsystems/LEDSystem.h"

RobotGoalDistance::RobotGoalDistance()
{
	Requires(dropdrive);
	Requires(visioncalculation);
	Requires(ledsystem);
}

// Called just before this Command runs the first time
void RobotGoalDistance::Initialize()
{
	heightPixels = visioncalculation->GetGoalDistance();
}

// Called repeatedly when this Command is scheduled to run
void RobotGoalDistance::Execute()
{
	heightPixels = visioncalculation->GetGoalDistance();
	SmartDashboard::PutNumber("Target Height", visioncalculation->GetGoalDistance());
	if(heightPixels<45){
		dropdrive->SetDrive(.2,0);
	}
	else if(heightPixels>50){
		dropdrive->SetDrive(-.2,0);

	}
	else{
		dropdrive->SetDrive(0,0);

	}
}

// Make this return true when this Command no longer needs to run execute()
bool RobotGoalDistance::IsFinished()
{
	return (heightPixels<50 && heightPixels>45);
}

// Called once after isFinished returns true
void RobotGoalDistance::End()
{
	dropdrive->SetDrive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RobotGoalDistance::Interrupted()
{
	End();
}
