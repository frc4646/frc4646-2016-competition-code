#include "RobotGoalDistance.h"
#include "Subsystems/DropDrive.h"
#include "Subsystems/VisionCalculation.h"

RobotGoalDistance::RobotGoalDistance():
CommandBase("RobotGoalDistance"),
po(),
ps(visioncalculation),
pc(1.75,0.003,-0.3,&ps,&po)
{
	SmartDashboard::PutData("RobotGoalDistancePID", &pc);
	Requires(dropdrive);
	Requires(visioncalculation);
}

// Called just before this Command runs the first time
void RobotGoalDistance::Initialize()
{
	pc.Reset();
	pc.SetSetpoint(0.0);
	pc.SetOutputRange(-0.3,0.3);
	pc.Enable();
	dropdrive->ResetGyro();

}

//const int DESIRED_HEIGHT = 295;
const int DESIRED_Y_POS=112;
const int DEADBAND = 2;
const int LIMITLOW = DESIRED_Y_POS - DEADBAND;
const int LIMITHIGH = DESIRED_Y_POS + DEADBAND;


// Called repeatedly when this Command is scheduled to run
void RobotGoalDistance::Execute()
{
	distancePower = pc.Get();
	SmartDashboard::PutNumber("Distance Power", distancePower);
	dropdrive->StraightDrive(distancePower);
	/*heightPixels = visioncalculation->GetGoalDistance();
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
	SmartDashboard::PutBoolean("WithinRange",(heightPixels<LIMITHIGH && heightPixels>LIMITLOW));*/
}

// Make this return true when this Command no longer needs to run execute()
bool RobotGoalDistance::IsFinished()
{	return false;;
}

// Called once after isFinished returns true
void RobotGoalDistance::End()
{
	dropdrive->StraightDrive(0);
	pc.Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RobotGoalDistance::Interrupted()
{
	End();
}
