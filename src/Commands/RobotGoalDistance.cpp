#include "RobotGoalDistance.h"
#include "Subsystems/DropDrive.h"
#include "Subsystems/VisionCalculation.h"
#include "Subsystems/LEDSystem.h"
#include "RobotMap.h"

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

//const int DESIRED_HEIGHT = 295;
const int DESIRED_HEIGHT=457;
//const int DEADBAND = 10;
const int DEADBAND = 10;
const int LIMITLOW = DESIRED_HEIGHT - DEADBAND;
const int LIMITHIGH = DESIRED_HEIGHT + DEADBAND;


// Called repeatedly when this Command is scheduled to run
void RobotGoalDistance::Execute()
{
	heightPixels = visioncalculation->GetGoalDistance();
	SmartDashboard::PutNumber("Target Height", visioncalculation->GetGoalDistance());//Possible height 54 w/ first shooter modification
	if(heightPixels<LIMITLOW){
		dropdrive->SetDrive(-.15,0);// + ((LIMITLOW - heightPixels)/250.0),0);
	}
	else if(heightPixels>LIMITHIGH){
		dropdrive->SetDrive(.15,0);// + ((heightPixels - LIMITHIGH)/250.0),0);
	}
	else{
		dropdrive->SetDrive(0,0);

	}
	SmartDashboard::PutBoolean("WithinRange",(heightPixels<LIMITHIGH && heightPixels>LIMITLOW));
}

// Make this return true when this Command no longer needs to run execute()
bool RobotGoalDistance::IsFinished()
{
	return (heightPixels<LIMITHIGH && heightPixels>LIMITLOW);
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
