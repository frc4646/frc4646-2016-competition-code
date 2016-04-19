#include "RobotAngleDistance.h"
#include "Subsystems/DropDrive.h"
#include "Subsystems/VisionCalculation.h"

RobotAngleDistance::RobotAngleDistance():
confidence(0),

turning(0),
robotTurn(0),
heightPixels(0)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(dropdrive);
	Requires(visioncalculation);
}

// Called just before this Command runs the first time
void RobotAngleDistance::Initialize()
{

}

const int DESIRED_Y_POS=214;
const int DEADBAND = 1;
const int LIMITLOW = DESIRED_Y_POS - DEADBAND;
const int LIMITHIGH = DESIRED_Y_POS + DEADBAND;

// Called repeatedly when this Command is scheduled to run
void RobotAngleDistance::Execute()
{
	heightPixels = visioncalculation->GetGoalDistance();
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

	if(heightPixels<LIMITLOW){
		dropdrive->SetDrive(-.15,robotTurn*6.67);// + ((LIMITLOW - heightPixels)/250.0),0);
	}
	else if(heightPixels>LIMITHIGH){
		dropdrive->SetDrive(.15,robotTurn*6.67);// + ((heightPixels - LIMITHIGH)/250.0),0);
	}
	else if (turning < 0.01 && turning > -0.05){
		dropdrive->SetDrive(0,0);
	}
	else
	{
		dropdrive->SetDrive(1, robotTurn);
	}
	SmartDashboard::PutBoolean("WithinRange",(heightPixels<LIMITHIGH && heightPixels>LIMITLOW));
	SmartDashboard::PutBoolean("LinedUp",confidence > 3);

}

// Make this return true when this Command no longer needs to run execute()
bool RobotAngleDistance::IsFinished()
{
	isInRange();
	return confidence > 3 && (heightPixels<LIMITHIGH && heightPixels>LIMITLOW);
}

// Called once after isFinished returns true
void RobotAngleDistance::End()
{
	dropdrive->SetDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RobotAngleDistance::Interrupted()
{
	End();
}

void RobotAngleDistance::isInRange() {
	if (turning < 0.12 && turning > -0.12)
	{
		confidence++;
	}
	else
	{
		confidence = 0;
	}
}

